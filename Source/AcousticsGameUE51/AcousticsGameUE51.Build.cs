// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class AcousticsGameUE51 : ModuleRules
{
	public AcousticsGameUE51(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange([
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore"
		]);

		PrivateDependencyModuleNames.AddRange([]);
	}
}
