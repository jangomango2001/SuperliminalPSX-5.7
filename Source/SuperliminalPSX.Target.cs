// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SuperliminalPSXTarget : TargetRules
{
	public SuperliminalPSXTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		//BuildEnvironment = TargetBuildEnvironment.Unique;

		ExtraModuleNames.AddRange( new string[] { "SuperliminalPSX" } );
	}
}
