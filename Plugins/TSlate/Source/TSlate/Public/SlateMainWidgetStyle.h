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
 * �������ǵ�Style��, ����дSlate��ʱ�����Ǿͷ���ܶ�, ��UE4�༭�������ú���Ҫ���õ�Slate��Դ(����ͼƬ����Ƶ��Font��)
 */
USTRUCT()
struct FMainWidgetStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	//����Ҫ��ôд, ������Ҫ����ģ��ƥ�亯����
	virtual void GetResources(TArray<const FSlateBrush*> & OutBrushes) const;
	virtual const FName GetTypeName() const;
	static const FMainWidgetStyle &GetDefault();
	static const FName TypeName;

	//Slate��ʾͼƬ, ���뽫slate�����õ�ͼƬ
	UPROPERTY(EditAnywhere,Category = "Task")
	FSlateBrush TemplateImage;

	//���뽫slate�����õ�����
	UPROPERTY(EditAnywhere, Category = "Task")
	FSlateFontInfo TemplateFont;

	//���뽫slate�����õ�����
	UPROPERTY(EditAnywhere, Category = "Task")
	FSlateSound TemplateSound;

	//���뽫slate�����õ���ɫ
	UPROPERTY(EditAnywhere, Category = "Task")
	FLinearColor TemplateColor;
};


//�ṩ���༭����->�Ҽ���Դ�����->ѡ��User Interface(���Ǵ���UMG��һ��)->ѡ��Slate Widget Style->��ȥѡSlateMainWidgetStyle(���ǵ�����ȥ��U)
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
