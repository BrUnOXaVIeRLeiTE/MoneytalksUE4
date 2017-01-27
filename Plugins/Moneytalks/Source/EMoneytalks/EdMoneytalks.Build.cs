using UnrealBuildTool;

public class EdMoneytalks : ModuleRules {
	public EdMoneytalks(TargetInfo Target) {
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"Slate",
				"Engine",
				"Projects",
				"UnrealEd",
				"SlateCore",
				"InputCore",
				"CoreUObject",
				"PropertyEditor",
				"EditorStyle",
				"Moneytalks"
			}
		);
		//
		PrivateIncludePaths.AddRange(new string[] {"EMoneytalks/Private"});
		PublicIncludePaths.AddRange(new string[] {"EMoneytalks/Public"});
	}
}