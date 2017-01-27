using UnrealBuildTool;
using System.IO;
using System;

public class Moneytalks : ModuleRules {
	public Moneytalks(TargetInfo Target) {
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"Engine",
				"CoreUObject"
			}
		);
		//
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"../ThirdParty/Include"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"../ThirdParty/Include"));
		//
		switch (Target.Platform) {
			case UnrealTargetPlatform.Win32:
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory,"../ThirdParty/x86/RDFPMathLib.lib"));
				break;
			case UnrealTargetPlatform.Win64:
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory,"../ThirdParty/x64/RDFPMathLib.lib"));
				break;
			case UnrealTargetPlatform.PS4:
			case UnrealTargetPlatform.Mac:
			case UnrealTargetPlatform.IOS:
			case UnrealTargetPlatform.Linux:
			case UnrealTargetPlatform.HTML5:
			case UnrealTargetPlatform.Android:
			case UnrealTargetPlatform.XboxOne:
			default:
				throw new NotImplementedException("RDFPMathLib: Target platform is not supported by this Intel Math Library just yet: "+Target.Platform.ToString());
		}
		//
		if (Definitions.Contains("WITH_ANTI_CHEAT")) {PublicDependencyModuleNames.Add("SCUE4");}
	}
}