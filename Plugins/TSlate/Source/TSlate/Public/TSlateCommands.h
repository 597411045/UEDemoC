// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TSlateStyle.h"

class FTSlateCommands : public TCommands<FTSlateCommands>
{
public:

	FTSlateCommands()
		: TCommands<FTSlateCommands>(TEXT("TSlate"), NSLOCTEXT("Contexts", "TSlate", "TSlate Plugin"), NAME_None, FTSlateStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};