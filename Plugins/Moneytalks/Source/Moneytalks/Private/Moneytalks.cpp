/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2016 (C) Bruno Xavier B. Leite			//
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Moneytalks.h"
#include "Moneytalks_Shared.h"

#include <sstream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UMT::UMT(const FObjectInitializer& OBJ) : Super(OBJ) {
	static ConstructorHelpers::FObjectFinder<UDataTable>DTC(*FString::Printf(TEXT("/%s/%s"),CASH_PLUGIN_NAME,TEXT("Data/CurrencySymbols.CurrencySymbols")));
	//
	if (DTC.Succeeded()) {Currency = DTC.Object;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float FDecimal::ToFloat() const {
	return bid128_to_binary32(Internal,IDEC_nearesteven,(_IDEC_flags*)&IDEC_Flag);
}

double FDecimal::ToDouble() const {
	return bid128_to_binary64(Internal,IDEC_nearesteven,(_IDEC_flags*)&IDEC_Flag);
}

uint32 FDecimal::ToUInt32() const {
	return bid128_to_uint32_ceil(Internal,(_IDEC_flags*)&IDEC_Flag);
}

int32 FDecimal::ToInt32() const {
	return bid128_to_int32_ceil(Internal,(_IDEC_flags*)&IDEC_Flag);
}

uint64 FDecimal::ToUInt64() const {
	return bid128_to_uint64_ceil(Internal,(_IDEC_flags*)&IDEC_Flag);
}

int64 FDecimal::ToInt64() const {
	return bid128_to_int64_ceil(Internal,(_IDEC_flags*)&IDEC_Flag);
}

float FDecimal::ToFloat(const DEC_RoundingMode &Mode) {
	switch (Mode) {
		case DEC_RoundingMode::DFLRound:
			return bid128_to_binary32(Internal,IDEC_dflround,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::Downward:
			return bid128_to_binary32(Internal,IDEC_downward,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::NearestAway:
			return bid128_to_binary32(Internal,IDEC_nearestaway,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::NearestEven:
			return bid128_to_binary32(Internal,IDEC_nearesteven,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::TowardZero:
			return bid128_to_binary32(Internal,IDEC_towardzero,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::Upward:
			return bid128_to_binary32(Internal,IDEC_upward,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

double FDecimal::ToDouble(const DEC_RoundingMode &Mode) {
	switch (Mode) {
		case DEC_RoundingMode::DFLRound:
			return bid128_to_binary64(Internal,IDEC_dflround,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::Downward:
			return bid128_to_binary64(Internal,IDEC_downward,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::NearestAway:
			return bid128_to_binary64(Internal,IDEC_nearestaway,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::NearestEven:
			return bid128_to_binary64(Internal,IDEC_nearesteven,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::TowardZero:
			return bid128_to_binary64(Internal,IDEC_towardzero,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_RoundingMode::Upward:
			return bid128_to_binary64(Internal,IDEC_upward,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

uint32 FDecimal::ToUInt32(const DEC_BaseMode &Mode) {
	switch (Mode) {
		case DEC_BaseMode::Ceil:
			return bid128_to_uint32_ceil(Internal,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_BaseMode::Floor:
			return bid128_to_uint32_floor(Internal,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

uint64 FDecimal::ToUInt64(const DEC_BaseMode &Mode) {
	switch (Mode) {
		case DEC_BaseMode::Ceil:
			return bid128_to_uint64_ceil(Internal,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_BaseMode::Floor:
			return bid128_to_uint64_floor(Internal,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

int32 FDecimal::ToInt32(const DEC_BaseMode &Mode) {
	switch (Mode) {
		case DEC_BaseMode::Ceil:
			return bid128_to_int32_ceil(Internal,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_BaseMode::Floor:
			return bid128_to_int32_floor(Internal,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

int64 FDecimal::ToInt64(const DEC_BaseMode &Mode) {
	switch (Mode) {
		case DEC_BaseMode::Ceil:
			return bid128_to_int64_ceil(Internal,(_IDEC_flags*)&IDEC_Flag); break;
		case DEC_BaseMode::Floor:
			return bid128_to_int64_floor(Internal,(_IDEC_flags*)&IDEC_Flag); break;
	default: break;} return 0;
}

FString FDecimal::ToString() {
	char Buffer[1024];
	bid128_to_string(Buffer,Internal,(_IDEC_flags*)&IDEC_Flag);
	//
	std::string Token;
	std::string STR(Buffer);
	std::istringstream ISS(STR);
	//
	getline(ISS,Token,'E');
	if (Token.c_str()==nullptr) {return TEXT("0");}
	//
	const auto Base = FString(ANSI_TO_TCHAR(Token.c_str())); FString P;
	Base.Split(TEXT("+"),NULL,&P,ESearchCase::IgnoreCase,ESearchDir::FromStart);
	//
	if (P.Len()>0) {return P;} return Base;
}

FString FDecimal::ToDecorated(const FString &Integral) {
	char Buffer[1024];
	bid128_to_string(Buffer,Internal,(_IDEC_flags*)&IDEC_Flag);
	//
	std::string Token;
	std::string STR(Buffer);
	std::istringstream ISS(STR);
	//
	getline(ISS,Token,'E');
	if (Token.c_str()==nullptr) {return TEXT("0");}
	//
	const auto Base = FString(ANSI_TO_TCHAR(Token.c_str())); FString P;
	Base.Split(TEXT("+"),NULL,&P,ESearchCase::IgnoreCase,ESearchDir::FromStart);
	//
	FString BASE, PARSE, SIGN;
	if (P.Len()>0) {BASE = P;} else {BASE = Base;}
	if (BASE[0]==TCHAR('-')) {SIGN.AppendChar(TCHAR('-')); BASE = BASE.Replace(TEXT("-"),TEXT(""),ESearchCase::IgnoreCase);}
	//
	int32 I=0;
	for (const auto C : BASE.Reverse()) {
		I++; PARSE.Append(&C,1);
		if (I>2) {
			PARSE.Append(*Integral,1);
	I=0;}}
	//
	return SIGN+PARSE.Reverse();
}

FText FDecimal::ToCurrency(const EDEC_DisplayFormat &Culture, const FString &Currency, const FString &Integral, const FString &Fractional) {
	auto BASE = ToString();
	//
	FString PARSE, SIGN, CUR, FA, FB, RET;
	if (BASE[0]==TCHAR('-')) {SIGN.AppendChar(TCHAR('-')); BASE = BASE.Replace(TEXT("-"),TEXT(""),ESearchCase::IgnoreCase);}
	//
	int32 I=0;
	for (const auto C : BASE.Reverse()) {
		I++; PARSE.Append(&C,1);
		if (I>2) {
			PARSE.Append(*Integral,1);
		I=0;}
	}///
	//
	PARSE = PARSE.Reverse();
	PARSE.Append(Fractional+TEXT("00"));
	CUR = FGetCurrencySymbol(Currency);
	//
	switch (Culture) {
		case EDEC_DisplayFormat::PrefixNoSpace:
			RET = CUR+SIGN+PARSE; break;
		case EDEC_DisplayFormat::PrefixWithSpace:
			RET = CUR+FString(TEXT(" "))+SIGN+PARSE; break;
		case EDEC_DisplayFormat::PostfixNoSpace:
			RET = SIGN+PARSE+CUR; break;
		case EDEC_DisplayFormat::PostfixWithSpace:
			RET = SIGN+PARSE+FString(TEXT(" "))+CUR; break;
	default: break;}
	//
	return FText::FromString(RET);
}

FText FDecimal::GetValueOfPercentage(const FDecimal &Percentage) {
	const auto X = (*this);
	auto Y = Percentage;
	auto P = Y / DEC(100);
	//
	Y = P * X;
	auto R = Y.ToDouble();
	//
	auto RET = FString::Printf(TEXT("%.2f"),R).Replace(TEXT("."),TEXT(","));
	return FText::FromString(RET);
}

FText FDecimal::GetPercentageOfValue(const FDecimal &Value) {
	auto X = (*this);
	auto Y = Value;
	auto P = Y / X;
	//
	P = P * DEC(100);
	auto R = P.ToDouble();
	//
	return FText::FromString(FString::Printf(TEXT("%.2f"),R)+TEXT("%"));
}

FDecimal FDecimal::GetPercentage(const FDecimal &Percentage) {
	if (Percentage<=DEC(0)) {return DEC(0);}
	//
	const auto X = (*this);
	//
	auto Y = Percentage;
	auto P = Y / DEC(100);
	//
	Y = P * X;
	//
	return Y;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FDecimal::Construct(FString Low, FString Mid, FString High) {
	std::string A, B, C, X;
	//
	A = TCHAR_TO_ANSI(*Low);
	B = TCHAR_TO_ANSI(*Mid);
	C = TCHAR_TO_ANSI(*High);
	//
	if (Low!=NOTEXT) {X=A;}
	if (Mid!=NOTEXT) {X+=B;}
	if (High!=NOTEXT) {X+=C;}
	//
	Internal = bid128_from_string((char*)X.c_str(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
}

void FDecimal::Unpack(FString &Low, FString &Mid, FString &High) {
	FString S =  ToString();
	//
	FString A, B, C;
	int32 I = 0;
	//
	for (const auto CH : S) {
		if (I<10) {A.Append(&CH,1);}
		if (I>=10&&I<20) {B.Append(&CH,1);}
		if (I>=20&&I<30) {C.Append(&CH,1);}
	I++;}
	//
	Low	= *A;
	Mid	= *B;
	High = *C;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////