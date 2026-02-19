// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SuperliminalPSXEditorTarget : TargetRules
{
	public SuperliminalPSXEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		//BuildEnvironment = TargetBuildEnvironment.Unique;

		ExtraModuleNames.AddRange( new string[] { "SuperliminalPSX" } );
	}
}
