/// Copyright 2021 (C) Bruno Xavier B. Leite

using UnrealBuildTool;
using System.IO;
using System;

public class Moneytalks : ModuleRules {
	public Moneytalks(ReadOnlyTargetRules Target) : base(Target) {
        PrivatePCHHeaderFile = "Public/Moneytalks_Shared.h";
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;
		//
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"CoreUObject",
				"Engine",
				"Core"
			}///
		);//
		//
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"Private"));
		//
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"../ThirdParty/Include"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"../ThirdParty/Include"));
		//
		if (Target.Platform == UnrealTargetPlatform.Win64) {
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory,"../ThirdParty/x64/RDFPMathLib.lib"));
		} else {
			throw new NotImplementedException("RDFP-Math-Lib: Target platform is not supported by this implementation of Intel Math Library just yet: "+Target.Platform.ToString());
		}///
		//
		if (PublicDefinitions.Contains("WITH_ANTI_CHEAT")) {PublicDependencyModuleNames.Add("SCUE4");}
	}///
}