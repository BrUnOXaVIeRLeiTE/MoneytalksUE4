///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2016 (C) Bruno Xavier B. Leite			//
//////////////////////////////////////////////////////////////
/*
	BY EXECUTING, READING, EDITING, COPYING OR KEEPING FILES FROM THIS SOFTWARE SOURCE CODE,
	YOU AGREE TO THE FOLLOWING TERMS IN ADDITION TO EPIC GAMES MARKETPLACE EULA:
	- YOU HAVE READ AND AGREE TO EPIC GAMES TERMS: https://publish.unrealengine.com/faq
	- YOU AGREE DEVELOPER RESERVES ALL RIGHTS TO THE SOFTWARE PROVIDED, GRANTED BY LAW.
	- YOU AGREE YOU'LL NOT CREATE OR PUBLISH DERIVATIVE SOFTWARE TO THE MARKETPLACE.
	- YOU AGREE DEVELOPER WILL NOT PROVIDE SOFTWARE OUTSIDE MARKETPLACE ENVIRONMENT.
	- YOU AGREE DEVELOPER WILL NOT PROVIDE PAID OR EXCLUSIVE SUPPORT SERVICES.
	- YOU AGREE DEVELOPER PROVIDED SUPPORT CHANNELS, ARE UNDER HIS SOLE DISCRETION.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Moneytalks.h"
#include "DECLibrary.generated.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class MONEYTALKS_API UDECLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
public:
	
	////////////////////////////////////////////////////////////
	/// Accessors
	
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FDecimal MakeLiteralDecimal(int32 Value);

	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FString ToString(UPARAM(ref)FDecimal &Decimal);

	/** Converts this Decimal number to a formatted number string.
	@ Integral: Symbol used to split integral groups. */
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FString ToDecorated(UPARAM(ref)FDecimal &Decimal, const FString &Integral = TEXT("."));

	/**	Converts this Decimal number to a FText representation:
	@ Currency: ISO-4217 Currency Code or any Prefix String.
	@ Integral: Symbol used to split integral groups.
	@ Fractional: Symbol used to split the monetary fractions.
	Note: ISO Currency Codes may return Unicode symbols. */
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FText ToCurrency(UPARAM(ref)FDecimal &Decimal, const EDEC_DisplayFormat &Culture = EDEC_DisplayFormat::PrefixNoSpace, const FString &Currency = TEXT(""), const FString &Integral = TEXT("."), const FString &Fractional = TEXT(","));

	/** Returns Decimal Percent of this Decimal. Equation:
	@ X = This.
	@ P% = Y / 100
	@ Y = P% * X
	@ Return Y */
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FText GetValueOfPercentage(UPARAM(ref)FDecimal &Decimal, const FDecimal &Percentage);

	/** Returns Percentage between Value and this Decimal. Equation:
	@ X = This.
	@ P% = Y / X
	@ Return P% * 100
	Note: May fail when Y > Max Int32. */
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FText GetPercentageOfValue(UPARAM(ref)FDecimal &Decimal, const FDecimal &Value);

	/** Returns Decimal Percent of this Decimal. Equation:
	@ X = This.
	@ P% = Y / 100
	@ Y = P% * X
	@ Return Y */
	UFUNCTION(BlueprintCallable, Category = "Variables|Decimal")
	static FDecimal GetPercentage(UPARAM(ref)FDecimal &Decimal, const FDecimal &Percentage, int32 &Integer);

	////////////////////////////////////////////////////////////
	/// Operators

	/// FDecimal -> FDecimal

	/** Get:: Decimal == Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "== (Decimal)", CompactNodeTitle = "==", Keywords = "Get Decimal EQUAL =="))
	static bool DEC_GetDecimalEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal != Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "!= (Decimal)", CompactNodeTitle = "!=", Keywords = "Get Decimal NOT !="))
	static bool DEC_GetDecimalNotEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal > Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "> (Decimal)", CompactNodeTitle = ">", Keywords = "Get Decimal GREATER >"))
	static bool DEC_GetDecimalGreaterDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal < Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "< (Decimal)", CompactNodeTitle = "<", Keywords = "Get Decimal LESS <"))
	static bool DEC_GetDecimalSmallerDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal >= Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = ">= (Decimal)", CompactNodeTitle = ">=", Keywords = "Get Decimal GREATER EQUAL >="))
	static bool DEC_GetDecimalGreaterEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal <= Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "<= (Decimal)", CompactNodeTitle = "<=", Keywords = "Get Decimal LESS EQUAL <="))
	static bool DEC_GetDecimalSmallerEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Set:: Decimal = Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "= (Decimal)", CompactNodeTitle = "=", Keywords = "Set Decimal EQUAL ="))
	static FDecimal DEC_SetDecimalEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal + Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "+ (Decimal)", CompactNodeTitle = "+", Keywords = "Get Decimal PLUS +"))
	static FDecimal DEC_GetDecimalPlusDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal - Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "- (Decimal)", CompactNodeTitle = "-", Keywords = "Get Decimal MINUS -"))
	static FDecimal DEC_GetDecimalMinusDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal * Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "* (Decimal)", CompactNodeTitle = "*", Keywords = "Get Decimal TIMES *"))
	static FDecimal DEC_GetDecimalTimesDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal / Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "/ (Decimal)", CompactNodeTitle = "/", Keywords = "Get Decimal DIVIDE /"))
	static FDecimal DEC_GetDecimalDivideDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal ++ */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "++ (Decimal)", CompactNodeTitle = "++", Keywords = "Get Decimal ADD PLUS ++"))
	static FDecimal DEC_GetDecimalIncreaseDEC(UPARAM(ref)FDecimal &DEC);

	/** Get:: Decimal -- */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "-- (Decimal)", CompactNodeTitle = "--", Keywords = "Get Decimal LESS --"))
	static FDecimal DEC_GetDecimalDecreaseDEC(UPARAM(ref)FDecimal &DEC);

	/** Get:: Decimal += Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "+= (Decimal)", CompactNodeTitle = "+=", Keywords = "Get Decimal PLUS EQUAL +="))
	static FDecimal DEC_GetDecimalPlusEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/** Get:: Decimal -= Decimal */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "-= (Decimal)", CompactNodeTitle = "-=", Keywords = "Get Decimal MINUS EQUAL -="))
	static FDecimal DEC_GetDecimalMinusEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D);

	/// FDecimal Conversions

	/** Decimal to Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "To Int", CompactNodeTitle = "Dec to Int", Keywords = "Decimal Int"))
	static int32 DEC_DecimalToInt(UPARAM(ref)FDecimal &DEC);

	/** Decimal to Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Decimal", meta = (DisplayName = "To Float", CompactNodeTitle = "Dec to Float", Keywords = "Decimal Float"))
	static float DEC_DecimalToFloat(UPARAM(ref)FDecimal &DEC);

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////