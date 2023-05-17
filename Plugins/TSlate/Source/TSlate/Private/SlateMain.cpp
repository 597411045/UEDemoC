#include "SlateMain.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Widgets/Layout/SScrollBox.h"
#include <TSlateStyle.h>

#define LOCTEXT_NAMESPACE "SlateMain"

static int32 nDynamicAddNum = 0;

void SMainSlate::Construct(const FArguments& InArgs)
{
	//计数器
	nDynamicAddNum = 0;
	//初始化checkbox数组, 默认给3个值
	CheckBoxArray.SetNum(3);

	//获取自定义样式
	MyCustomWidgetStyle = &FTSlateStyle::Get().GetWidgetStyle<FMainWidgetStyle>(TEXT("MyCustomWidgetStyleBP"));

	//链式编程 维护很麻烦...
	ChildSlot
	[
		SAssignNew(CanvasPanel_0, SConstraintCanvas)

		+ SConstraintCanvas::Slot()
		.Anchors(0.f)	//对应UMG这个文本控件上的Anchors属性，拷贝过来即可
		.Offset(FMargin(600, 0.f, 100, 100))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(SImage)
			.Image(&MyCustomWidgetStyle->TemplateImage)
			.ColorAndOpacity(FSlateColor(MyCustomWidgetStyle->TemplateColor))
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<Mesh合并界面>文本
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)	//对应UMG这个文本控件上的Anchors属性，拷贝过来即可
		.Offset(FMargin(20.0, 12.f, 600, 72))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SMainSlate_TextBlock1", "Mesh合并界面"))
			.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 53))
			.ColorAndOpacity(FSlateColor(FLinearColor(1, 0, 0.361307, 1)))
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<Level中的模型列表>文本
		+SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(132, 128, 350.0, 40))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SMainSlate_TextBlock2", "Level中的模型列表"))
			.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			.ColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1)))
		]

		//对应左侧的ScrollBox
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(132, 180.0, 369, 625))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SAssignNew(MyScrollBoxLeft, SScrollBox)
			.Orientation(Orient_Vertical)
			.ScrollBarAlwaysVisible(true)

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)

			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox_TextBlock1", "场景中模型_1"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox_TextBlock2", "场景中模型_2"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox_TextBlock3", "场景中模型_3"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox_TextBlock4", "场景中模型_4"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox_TextBlock5", "场景中模型_5"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<Level中的模型列表>文本
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(764.0, 128, 350.0, 40))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SMainSlate_TextBlock3", "预览->按材质合并之后的"))
			.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			.ColorAndOpacity(FSlateColor(FLinearColor(1, 1, 1, 1)))
		]

		//对应中间的ScrollBox
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(764, 180.0, 370.0, 625))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SAssignNew(MyScrollBoxRight, SScrollBox)
			.Orientation(Orient_Vertical)
			.ScrollBarAlwaysVisible(true)

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)

			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox2_TextBlock1", "预览->按材质合并之后的模型_1"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox2_TextBlock2", "预览->按材质合并之后的模型_2"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox2_TextBlock3", "预览->按材质合并之后的模型_3"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox2_TextBlock4", "预览->按材质合并之后的模型_4"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]

			+ SScrollBox::Slot()
			.Padding(0.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				//链式编程里面不能写for, 所以我就new5个吧。。。
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_SVerticalBox2_TextBlock5", "预览->按材质合并之后的模型_5"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]


		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<Button_458>
		+SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(584.0, 468.0, 100.0, 40))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.ContentPadding(0.f)
			.OnClicked(this, &SMainSlate::OnFirstSButton_OnClicked)	//事件绑定的技巧, 转到定义, 看那边的代理是怎么定义的, 把参数和返回值拿过来定义一个函数即可
			.OnPressed(this, &SMainSlate::OnFirstSButton_OnPressed)
			.OnReleased(this, &SMainSlate::OnFirstSButton_OnReleased)
			.OnHovered(this, &SMainSlate::OnFirstSButton_OnHovered)
			.OnUnhovered(this, &SMainSlate::OnFirstSButton_OnUnhovered)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_Button_Text1", "---->"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<Button_Merge>
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(1520.0, 888.0, 225.0, 90))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.ContentPadding(0.f)
			.OnClicked(this, &SMainSlate::OnFirstSButton_OnClicked)	//事件绑定的技巧, 转到定义, 看那边的代理是怎么定义的, 把参数和返回值拿过来定义一个函数即可
			.OnPressed(this, &SMainSlate::OnFirstSButton_OnPressed)
			.OnReleased(this, &SMainSlate::OnFirstSButton_OnReleased)
			.OnHovered(this, &SMainSlate::OnFirstSButton_OnHovered)
			.OnUnhovered(this, &SMainSlate::OnFirstSButton_OnUnhovered)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_Button_Text2", "一键合并"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 30))
			]
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<CheckBox_1>
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(1260.0, 172.0, 600.0, 40.0))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SAssignNew(CheckBoxArray[0], SCheckBox)
			.IsChecked(false)
			.IsEnabled(true)
			.OnCheckStateChanged(this, &SMainSlate::MyOnCheckStateChanged<0>)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_checkbox_Text1", "按材质合并成SingleMesh"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<CheckBox_2>
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(1260.0, 264.0, 600.0, 40.0))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SAssignNew(CheckBoxArray[1], SCheckBox)
			.IsChecked(false)
			.IsEnabled(true)
			.OnCheckStateChanged(this, &SMainSlate::MyOnCheckStateChanged<1>)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_checkbox_Text2", "按材质合并成InstanceMesh"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]

		//对应UMG(WidgetBlueprint'/Game/Blogs_Slate/ReferUMGBP.ReferUMGBP')中的<CheckBox_3>
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(1260.0, 360.0, 600.0, 40.0))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SAssignNew(CheckBoxArray[2], SCheckBox)
			.IsChecked(false)
			.IsEnabled(true)
			.OnCheckStateChanged(this, &SMainSlate::MyOnCheckStateChanged<2>)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("SMainSlate_checkbox_Text2", "按材质合并成HeighInstanceMesh"))
				.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
			]
		]

		//测试动画的
		+ SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(100, 600, 200, 200))	//这个可能会迷惑, 第一个参数在这是PositionX, 第二个参数在这是PositionY, 第三个参数在这是SizeX, 第四个参数在这是SizeY.找不到设置坐标的同学注意看这里
		.Alignment(FVector2D(0.f, 0.f))	//同样的, 对应Alignment是个FVector2D
		.AutoSize(false)			//对应AutoSize
		.ZOrder(0)
		[
			SNew(SMyAnimationSlate)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.ContentPadding(0.f)
				.OnClicked(this, &SMainSlate::OnFirstSButton_OnClicked)	//事件绑定的技巧, 转到定义, 看那边的代理是怎么定义的, 把参数和返回值拿过来定义一个函数即可
				.OnPressed(this, &SMainSlate::OnFirstSButton_OnPressed)
				.OnReleased(this, &SMainSlate::OnFirstSButton_OnReleased)
				.OnHovered(this, &SMainSlate::OnFirstSButton_OnHovered)
				.OnUnhovered(this, &SMainSlate::OnFirstSButton_OnUnhovered)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("SMainSlate_ButtonSlateAnimation_Text3333", "测试Slate动画"))
					.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
				]
			]
		]
	];
}


FReply SMainSlate::OnFirstSButton_OnClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("OnFirstSButton_OnClicked"));

	++nDynamicAddNum;

	FString s2 = TEXT("new add") + FString::FromInt(nDynamicAddNum);
	MyScrollBoxLeft->AddSlot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(s2))
		.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
		.ColorAndOpacity(FSlateColor(FLinearColor(1, 0, 1, 1)))
		];

	MyScrollBoxRight->AddSlot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(s2))
		.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 24))
		.ColorAndOpacity(FSlateColor(FLinearColor(1, 1, 0, 1)))
		];

	return FReply::Handled();
}

void SMainSlate::OnFirstSButton_OnPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("OnFirstSButton_OnPressed"));
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("OnFirstSButton_OnPressed"));
}

void SMainSlate::OnFirstSButton_OnReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("OnFirstSButton_OnReleased"));
}

void SMainSlate::OnFirstSButton_OnHovered()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("OnFirstSButton_OnHovered"));
}

void SMainSlate::OnFirstSButton_OnUnhovered()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("OnFirstSButton_OnUnhovered"));
}


void SMyAnimationSlate::Construct(const FArguments& InArgs)
{
	MySlateCurveSequence = FCurveSequence(0.f, 1.f);
	ColorAndOpacity = TAttribute<FLinearColor>::Create(TAttribute<FLinearColor>::FGetter::CreateSP(this, &SMyAnimationSlate::SlateColorChanged));

	ChildSlot
		[
			InArgs._OutSlots.Widget
		];
}

void SMyAnimationSlate::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!MySlateCurveSequence.IsAtEnd())
	{
		if (MySlateCurveSequence.IsInReverse() && MySlateCurveSequence.IsPlaying())
		{
			MySlateCurveSequence.Reverse();
		}
		else if (!MySlateCurveSequence.IsPlaying())
		{
			MySlateCurveSequence.Play(this->AsShared());
		}
	}
}

void SMyAnimationSlate::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	if (!MySlateCurveSequence.IsAtStart())
	{
		if (!MySlateCurveSequence.IsInReverse() && MySlateCurveSequence.IsPlaying())
		{
			MySlateCurveSequence.Reverse();
		}
		else if (!MySlateCurveSequence.IsPlaying())
		{
			MySlateCurveSequence.PlayReverse(this->AsShared());
		}
	}
}

FLinearColor SMyAnimationSlate::SlateColorChanged()
{
	return FLinearColor(1, 1, 1, 1 - MySlateCurveSequence.GetLerp());
}

#undef LOCTEXT_NAMESPACE

