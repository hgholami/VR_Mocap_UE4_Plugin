// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class UnrealBody : ModuleRules
{
	public UnrealBody(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableExceptions = true;
		
        PublicIncludePaths.AddRange(
			new string[] { 
				// ... add public include paths required here ...
				Path.Combine(ModuleDirectory, "Public")
			}
		);

        PrivateIncludePaths.AddRange(
			new string[] { 
				// ... add other private include paths required here ...
				Path.Combine(ModuleDirectory, "Private")
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Sockets",
				"Networking",
				"Engine",
				"InputCore"
				// ... add other public dependencies that you statically link with here ...
			}
		);

        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.AddRange(
            new string[] {
                "UnrealEd",
                "EditorStyle",
                "DesktopWidgets",
                "DesktopPlatform"
            });
        }


        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore"
				// ... add private dependencies that you statically link with here ...
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
    }
}
