// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateMainWidgetStyle.h"

const FName FMainWidgetStyle::TypeName(TEXT("MainWidgetStyle"));

void FMainWidgetStyle::GetResources(TArray<const FSlateBrush*> & OutBrushes) const
{

}

const FName FMainWidgetStyle::GetTypeName() const
{
	return TypeName;
}

const FMainWidgetStyle & FMainWidgetStyle::GetDefault()
{
	//C++11 magic staic
	static FMainWidgetStyle MyWidgetStyle;
	return MyWidgetStyle;
}

