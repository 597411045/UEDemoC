// Copyright Epic Games, Inc. All Rights Reserved.

#include "TSlateCommands.h"

#define LOCTEXT_NAMESPACE "FTSlateModule"

void FTSlateCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "TSlate", "Bring up TSlate window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
