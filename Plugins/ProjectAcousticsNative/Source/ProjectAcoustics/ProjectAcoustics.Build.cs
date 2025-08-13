// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

//For debugging purposes only.
//#define ENABLE_DEBUGGING

using UnrealBuildTool;
using System.IO;

public class ProjectAcoustics : ModuleRules
{
    public ProjectAcoustics(ReadOnlyTargetRules Target) : base(Target)
    {

#if (ENABLE_DEBUGGING)
        PCHUsage = ModuleRules.PCHUsageMode.Default;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
#else
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
#endif

        PublicIncludePaths.AddRange(
            new string[] {
                // ... add public include paths required here ...
                "Runtime/Engine",
                "Runtime/Core"
            }
            );


        PrivateIncludePaths.AddRange(
            new string[] {
                "ProjectAcoustics/Public",
                "ThirdParty/Include",
                "ProjectAcoustics/Private",
                // ... add other private include paths required here ...
            }
            );
        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "Projects",
                // ... add other public dependencies that you statically link with here ...
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                // ... add private dependencies that you statically link with here ...
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
            );

        var thirdPartyDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ThirdParty"));
        // fix up include path that is needed for TritonApiTypes.h
        PublicIncludePaths.Add(Path.Combine(thirdPartyDir, "Include"));
        // Go find the right libs to link based on target platform and config
        // Assume release to start
        string configuration = "Release";
        string arch = "";
        string tritonLibName = "Triton.Runtime.lib";
        string tritonCodecLibName = "Triton.Codec.lib";
        string zfpName = "zfp.lib";

        // Override release only if running debug target with debug crt
        // change bDebugBuildsActuallyUseDebugCRT to true in BuildConfiguration.cs to actually link debug binaries
        if (Target.Configuration == UnrealTargetConfiguration.Debug && Target.bDebugBuildsActuallyUseDebugCRT)
        {
            configuration = "Debug";
        }

        // Validate that the target platform is supported in both Project Acoustics and UE version used
        string[] supportedPlatforms = { "Android", "Win64", "WinGDK", "XboxOneGDK", "XSX" };
        if (System.Array.IndexOf(supportedPlatforms, Target.Platform.ToString()) == -1 ||
            System.Array.IndexOf(UnrealTargetPlatform.GetValidPlatformNames(), Target.Platform.ToString()) == -1)
        {
            throw new System.Exception(string.Format("Target platform {0} is not supported", Target.Platform.ToString()));
        }

        // Android is a special case for ARM ABI variants
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            tritonLibName = "libTriton.Runtime.a";
            tritonCodecLibName = "libTriton.Codec.a";
            zfpName = "libzfp.a";

            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "arm64-v8a", tritonLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "armeabi-v7a", tritonLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "x86", tritonLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "arm64-v8a", tritonCodecLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "armeabi-v7a", tritonCodecLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "x86", tritonCodecLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "arm64-v8a", zfpName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "armeabi-v7a", zfpName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyDir, "Android", "x86", zfpName));
        }
        else
        {
            // Directory name maps directly to Target.Platform value
            arch = Target.Platform.ToString();

            var thirdPartyLibPath = Path.Combine(Path.Combine(thirdPartyDir, arch), configuration);
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyLibPath, tritonLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyLibPath, tritonCodecLibName));
            PublicAdditionalLibraries.Add(Path.Combine(thirdPartyLibPath, zfpName));
        }
    }
}