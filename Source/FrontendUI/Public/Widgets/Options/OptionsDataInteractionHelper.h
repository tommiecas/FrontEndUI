
#pragma once

#include "CoreMinimal.h"
#include "PropertyPathHelpers.h"

class UFrontEndGameUserSettings;
/**
 * 
 */
class FRONTENDUI_API FOptionsDataInteractionHelper
{
public:
	FOptionsDataInteractionHelper(const FString& InSetterOrGetterFuncPath);

	FString GetValueAsString() const;
	void SetValueFromString(const FString& InStringValue);

private:
	FCachedPropertyPath CachedDynamicFunctionPath;
	TWeakObjectPtr<UFrontEndGameUserSettings> CachedWeakGameUserSettings;
};