// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateBrush.h"
#include "Fonts/SlateFontInfo.h"
#include "Sound/SlateSound.h"
#include "Math/Color.h"
#include "SlateMainWidgetStyle.generated.h"

/**
 * 定制我们的Style类, 这样写Slate的时候我们就方便很多, 在UE4编辑器中设置好想要设置的Slate资源(比如图片、音频、Font等)
 */
USTRUCT()
struct FMainWidgetStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	//必须要这么写, 方法是要进行模板匹配函数的
	virtual void GetResources(TArray<const FSlateBrush*> & OutBrushes) const;
	virtual const FName GetTypeName() const;
	static const FMainWidgetStyle &GetDefault();
	static const FName TypeName;

	//Slate演示图片, 你想将slate上设置的图片
	UPROPERTY(EditAnywhere,Category = "Task")
	FSlateBrush TemplateImage;

	//你想将slate上设置的字体
	UPROPERTY(EditAnywhere, Category = "Task")
	FSlateFontInfo TemplateFont;

	//你想将slate上设置的声音
	UPROPERTY(EditAnywhere, Category = "Task")
	FSlateSound TemplateSound;

	//你想将slate上设置的颜色
	UPROPERTY(EditAnywhere, Category = "Task")
	FLinearColor TemplateColor;
};


//提供给编辑器内->右键资源浏览器->选择User Interface(就是创建UMG那一栏)->选择Slate Widget Style->再去选SlateMainWidgetStyle(我们的类名去掉U)
UCLASS()
class USlateMainWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "MyWidgetStyle", meta = (ShowOnlyInnerProperties))
	FMainWidgetStyle MyWidgetStyle;
	
	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&MyWidgetStyle);
	}
};
