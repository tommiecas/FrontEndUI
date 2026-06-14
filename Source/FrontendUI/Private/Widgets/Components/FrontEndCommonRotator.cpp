// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Widgets/Components/FrontEndCommonRotator.h"

#include "CommonTextBlock.h"

void UFrontEndCommonRotator::SetSelectedOptionByText(const FText& InTextOption)
{
	const int32 FoundIndex = TextLabels.IndexOfByPredicate(
		[InTextOption](const FText& TextItem)->bool
		{
			return TextItem.EqualTo(InTextOption);
		}
	);

	if (FoundIndex != INDEX_NONE)
	{
		SetSelectedItem(FoundIndex);
	}
	else
	{
		MyText->SetText(InTextOption);
	}
}
