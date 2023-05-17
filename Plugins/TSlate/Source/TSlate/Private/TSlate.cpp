// Copyright Epic Games, Inc. All Rights Reserved.

#include "TSlate.h"
#include "TSlateStyle.h"
#include "TSlateCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "SlateMain.h"

static const FName TSlateTabName("TSlate");

#define LOCTEXT_NAMESPACE "FTSlateModule"

void FTSlateModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTSlateStyle::Initialize();
	FTSlateStyle::ReloadTextures();

	FTSlateCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTSlateCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTSlateModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTSlateModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TSlateTabName, FOnSpawnTab::CreateRaw(this, &FTSlateModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTSlateTabTitle", "TSlate"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FTSlateModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTSlateStyle::Shutdown();

	FTSlateCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TSlateTabName);
}

TSharedRef<SDockTab> FTSlateModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add 123code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTSlateModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("TSlate.cpp"))
		);

	// return SNew(SDockTab)
	// 	.TabRole(ETabRole::NomadTab)
	// 	[
	// 		// Put your tab content here!
	// 		// SNew(SBox)
	// 		// .HAlign(HAlign_Center)
	// 		// .VAlign(VAlign_Center)
	// 		// [
	// 		// 	SNew(STextBlock)
	// 		// 	.Text(WidgetText)
	// 		// ]
	// 		SNew(SButton)
	// 		.Text(LOCTEXT("","Button"))
	// 		.OnClicked(FOnClicked::CreateRaw(this,&FTSlateModule::TestClicker))
	// 	];
	
	MyMainSlate = SNew(SMainSlate);
	return SNew(SDockTab)
		[
			MyMainSlate->AsShared()
		];
}

FReply FTSlateModule::TestClicker()
{
	UE_LOG(LogTemp,Error,TEXT("TestClicker"));
	return FReply::Handled();
}

void FTSlateModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TSlateTabName);
}

void FTSlateModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FTSlateCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTSlateCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTSlateModule, TSlate)