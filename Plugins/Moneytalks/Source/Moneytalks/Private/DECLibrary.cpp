///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2021 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DECLibrary.h"
#include "Moneytalks_Shared.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FDecimal UDECLibrary::MakeDecimal_Int32(int32 Value) {
	FDecimal D(Value); return D;
}

FDecimal UDECLibrary::MakeDecimal_Int64(int64 Value) {
	FDecimal D(Value); return D;
}

FDecimal UDECLibrary::MakeDecimal_String(FString Value) {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// FDecimal -> Conversions

int32 UDECLibrary::DEC_DecimalToInt(UPARAM(ref)FDecimal &DEC) {
	return DEC.ToInt32();
}

int64 UDECLibrary::DEC_DecimalToInt64(FDecimal &DEC) {
	return DEC.ToInt64();
}

float UDECLibrary::DEC_DecimalToFloat(UPARAM(ref)FDecimal &DEC) {
	return DEC.ToFloat();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////