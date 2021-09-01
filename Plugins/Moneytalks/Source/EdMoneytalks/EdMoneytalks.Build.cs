/// Copyright 2021 (C) Bruno Xavier B. Leite

using UnrealBuildTool;
using System.IO;

public class EdMoneytalks : ModuleRules {
	public EdMoneytalks(ReadOnlyTargetRules Target) : base(Target) {
        PrivatePCHHeaderFile = "Public/EdMoneytalks_Shared.h";
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;
		//
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"Slate",
				"Engine",
				"Projects",
				"UnrealEd",
				"SlateCore",
				"InputCore",
				"Moneytalks",
				"EditorStyle",
				"CoreUObject",
				"PropertyEditor"
			}///
		);//
		//
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"Private"));
	}///
}