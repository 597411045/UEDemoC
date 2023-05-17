// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateCore.h"
#include "Widgets/SCompoundWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Animation/CurveSequence.h"
#include "SlateMainWidgetStyle.h"


//Slot�������Ҫ, ��۾���˵�����������������Ӷ��ٸ��ӿؼ�����������������дSlate�ᾭ���̳е���
//SCompoundWidget��һ�����, �̶�һ��, SButton, SBox
//SPanel: ������ ����SVerticalBox, SHorizontalBox
//SLeafWidget:û�в��, ����STextBlock

class SMyAnimationSlate;

//���������þ���ȥ��Slate����ʵ��һ�����UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')
class SMainSlate : public SCompoundWidget /*public SUserWidget*/
{
public:
	//SLATE_BEGIN_ARGS+SLATE_END_ARGS ��ʵ��һ���ṹ��, �ڲ�д�Ķ������൱��д����һ���ṹ������
	SLATE_BEGIN_ARGS(SMainSlate)
	{

	}
	SLATE_END_ARGS()

	//�ⲿִ��SNew����SAssignNewʱ������Construct()
	void Construct(const FArguments& InArgs);

protected:
	//SButton���¼���
	FReply OnFirstSButton_OnClicked();
	void OnFirstSButton_OnPressed();
	void OnFirstSButton_OnReleased();
	void OnFirstSButton_OnHovered();
	void OnFirstSButton_OnUnhovered();


	//SChechBox���¼���
	template<int32 T>
	void MyOnCheckStateChanged(ECheckBoxState emState)
	{
		if (CheckBoxArray.IsValidIndex(T))
		{
			for (int32 i = 0; i < CheckBoxArray.Num(); i++)
			{
				if (i == T)
				{
					if (CheckBoxArray[i].IsValid() || CheckBoxArray[i].Get())
					{
						CheckBoxArray[i]->SetIsChecked(emState);
					}

				}
				else
				{
					if (CheckBoxArray[i].IsValid() || CheckBoxArray[i].Get())
					{
						CheckBoxArray[i]->SetIsChecked(ECheckBoxState::Unchecked);
					}
				}
			}
		}
	}
private:
	//�����Ĳ�, ��������Ĭ�ϴ���UMG���Ĳ�
	TSharedPtr<class SConstraintCanvas> CanvasPanel_0;

	//���SCheckBox������, ѡ�к��ά��Ψһѡ��
	TArray<TSharedPtr<class SCheckBox>> CheckBoxArray;

	//����
	TSharedPtr<class SScrollBox> MyScrollBoxLeft;

	//�Ҳ��
	TSharedPtr<class SScrollBox> MyScrollBoxRight;

	//�Զ������ʽ
	const struct FMainWidgetStyle *MyCustomWidgetStyle;
};


//Slate������ʾ��
class SMyAnimationSlate : public SCompoundWidget /*public SUserWidget*/
{
public:
	//SLATE_BEGIN_ARGS+SLATE_END_ARGS ��ʵ��һ���ṹ��, �ڲ�д�Ķ������൱��д����һ���ṹ������
	SLATE_BEGIN_ARGS(SMyAnimationSlate)
	{
		_Visibility = EVisibility::SelfHitTestInvisible;
	}

	//�ⲿSlot����Ķ�����Ϊ���Slate�����ChildSlot����
	SLATE_DEFAULT_SLOT(FArguments, OutSlots)

	SLATE_END_ARGS()

	//�ⲿִ��SNew����SAssignNewʱ������Construct()
	void Construct(const FArguments& InArgs);

	//������
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	//����뿪
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;

	//��ɫ�仯
	FLinearColor SlateColorChanged();
private:
	//Slate��������
	FCurveSequence MySlateCurveSequence;
};