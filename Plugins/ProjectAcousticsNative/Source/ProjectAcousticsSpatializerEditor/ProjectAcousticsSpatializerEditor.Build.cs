// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

using UnrealBuildTool;
using System.IO;

public class ProjectAcousticsSpatializerEditor : ModuleRules
{
    public ProjectAcousticsSpatializerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.Default;
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
        PrivatePCHHeaderFile = "Public/AcousticsSpatializerEditorModule.h";

        PublicIncludePaths.AddRange([]);

        PrivateIncludePaths.AddRange([
            "ProjectAcousticsSpatializer/Private"
        ]);

        PublicDependencyModuleNames.AddRange([
            "Core",
            "ProjectAcousticsSpatializer"
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