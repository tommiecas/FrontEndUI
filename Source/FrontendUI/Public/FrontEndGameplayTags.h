#pragma once

#include "NativeGameplayTags.h"

namespace FrontEndGameplayTags
{
	// Front End Widget Stack
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_WidgetStack_Model);
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_WidgetStack_GameMenu);
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_WidgetStack_GameHUD);
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_WidgetStack_FrontEnd);

	//Front End Widgets
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_Widget_PressAnyKeyScreen);
	FRONTENDUI_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrontEnd_Widget_MainMenuScreen);
}