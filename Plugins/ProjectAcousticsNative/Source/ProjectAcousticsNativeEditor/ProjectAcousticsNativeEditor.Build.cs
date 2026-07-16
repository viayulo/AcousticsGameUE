// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

using UnrealBuildTool;
using System.IO;

public class ProjectAcousticsNativeEditor : ModuleRules
{
    public ProjectAcousticsNativeEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.Default;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
        PrivatePCHHeaderFile = "Public/AcousticsNativeEditorModule.h";

        PublicIncludePaths.AddRange([]);

        PrivateIncludePaths.AddRange([
            "../Source/ProjectAcousticsNative/Public"
        ]);

        PublicDependencyModuleNames.AddRange([
            "Core",
            "ProjectAcoustics",
            "ProjectAcousticsNative",
            // Adding Source Control module to list of public dependencies to use
            // source control operations during the prebake and bake process.
            "SourceControl"
        ]);

        PrivateDependencyModuleNames.AddRange([
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "AssetDefinition"
        ]);

        DynamicallyLoadedModuleNames.AddRange([]);
    }
}
