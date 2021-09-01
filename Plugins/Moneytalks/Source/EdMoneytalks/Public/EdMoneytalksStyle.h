/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//			Copyright 2021 (C) Bruno Xavier Leite1
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SlateBasics.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FEMoneytalksStyle {
private:
	static TSharedPtr<FSlateStyleSet>Instance;
	static TSharedRef<FSlateStyleSet>Create();
public:
	static void Shutdown();
	static void Initialize();
	static void ReloadTextures();
public:
	static FName GetStyleSetName();
	static const ISlateStyle &Get();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////