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

#include "MoneytalksPrivatePCH.h"
#include "DECLibrary.h"

FDecimal UDECLibrary::MakeLiteralDecimal(int32 Value) {
	FDecimal D(Value); return D;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FString UDECLibrary::ToString(UPARAM(ref)FDecimal &Decimal) {
	return Decimal.ToString();
}

FString UDECLibrary::ToDecorated(UPARAM(ref)FDecimal &Decimal, const FString &Integral) {
	return Decimal.ToDecorated(Integral);
}

FText UDECLibrary::ToCurrency(UPARAM(ref)FDecimal &Decimal, const EDEC_DisplayFormat &Culture, const FString &Currency, const FString &Integral, const FString &Fractional) {
	return Decimal.ToCurrency(Culture,Currency,Integral,Fractional);
}

FText UDECLibrary::GetValueOfPercentage(UPARAM(ref)FDecimal &Decimal, const FDecimal &Percentage) {
	return Decimal.GetValueOfPercentage(Percentage);
}

FText UDECLibrary::GetPercentageOfValue(UPARAM(ref)FDecimal &Decimal, const FDecimal &Value) {
	return Decimal.GetPercentageOfValue(Value);
}

FDecimal UDECLibrary::GetPercentage(UPARAM(ref)FDecimal &Decimal, const FDecimal &Percentage, int32 &Integer) {
	Integer = Decimal.GetPercentage(Percentage).ToInt32();
	return Decimal.GetPercentage(Percentage);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// FDecimal -> FDecimal

bool UDECLibrary::DEC_GetDecimalEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC == *&D);
}

bool UDECLibrary::DEC_GetDecimalNotEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC != *&D);
}

bool UDECLibrary::DEC_GetDecimalGreaterDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC > *&D);
}

bool UDECLibrary::DEC_GetDecimalSmallerDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC < *&D);
}

bool UDECLibrary::DEC_GetDecimalGreaterEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC >= *&D);
}

bool UDECLibrary::DEC_GetDecimalSmallerEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	return (*&DEC <= *&D);
}

FDecimal UDECLibrary::DEC_SetDecimalEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	*&DEC = *&D; return *&DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalPlusDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	(*&DEC + *&D); return DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalMinusDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	(*&DEC - *&D); return DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalTimesDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	(*&DEC * *&D); return DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalDivideDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	(*&DEC / *&D); return DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalIncreaseDEC(UPARAM(ref)FDecimal &DEC) {
	(++ *&DEC); return *&DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalDecreaseDEC(UPARAM(ref)FDecimal &DEC) {
	(-- *&DEC); return *&DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalPlusEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	*&DEC = (*&DEC += *&D); return *&DEC;
}

FDecimal UDECLibrary::DEC_GetDecimalMinusEqualDEC(UPARAM(ref)FDecimal &DEC, UPARAM(ref)FDecimal &D) {
	*&DEC = (*&DEC -= *&D); return *&DEC;
}

/// FDecimal -> Conversions

int32 UDECLibrary::DEC_DecimalToInt(UPARAM(ref)FDecimal &DEC) {
	return DEC.ToInt32();
}

float UDECLibrary::DEC_DecimalToFloat(UPARAM(ref)FDecimal &DEC) {
	return DEC.ToFloat();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////