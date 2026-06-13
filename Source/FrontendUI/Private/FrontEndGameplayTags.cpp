#include "FrontEndGameplayTags.h"

namespace FrontEndGameplayTags
{
	// Front End Widget Stack
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_WidgetStack_Model,"FrontEnd.WidgetStack.Model");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_WidgetStack_GameMenu,"FrontEnd.WidgetStack.GameMenu");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_WidgetStack_GameHUD,"FrontEnd.WidgetStack.GameHUD");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_WidgetStack_FrontEnd,"FrontEnd.WidgetStack.FrontEnd");

	// Front End Widgets
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_Widget_PressAnyKeyScreen, "FrontEnd.Widget.PressAnyKeyScreen");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_Widget_MainMenuScreen, "FrontEnd.Widget.MainMenuScreen");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_Widget_OptionsScreen, "FrontEnd.Widget.OptionsScreen");
	UE_DEFINE_GAMEPLAY_TAG(FrontEnd_Widget_ConfirmScreen,"FrontEnd.Widget.ConfirmScreen");
}