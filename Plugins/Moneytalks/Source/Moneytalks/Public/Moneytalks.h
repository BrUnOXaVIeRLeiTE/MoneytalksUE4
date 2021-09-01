/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2021 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DECIMAL
#define __DECIMAL

#ifdef WIN32
  #define LX "%I64x"
#else
  #ifdef HPUX_OS
	#define LX "%llx"
  #else
	#define LX "%Lx"
  #endif
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
	#include "IntelRDFPMathLib/bid_conf.h"
	#include "IntelRDFPMathLib/bid_functions.h"
	#include "IntelRDFPMathLib/bid_internal.h"
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if BID_BIG_ENDIAN
  #define HIGH_128W 0
  #define LOW_128W  1
#else
  #define HIGH_128W 1
  #define LOW_128W  0
#endif

#if defined _MSC_VER
  #if defined(_M_IX86) && !defined(__INTEL_COMPILER)
	#define ALIGN(n)
  #else
	#define ALIGN(n)__declspec(align(n))
  #endif
#else
  #define ALIGN(n)__attribute__((aligned(n)))
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// IDEC Rounding Mode
typedef enum IDEC_RoundingMode {
	IDEC_nearesteven	= 0,
	IDEC_downward		= 1,
	IDEC_upward			= 2,
	IDEC_towardzero		= 3,
	IDEC_nearestaway	= 4,
	IDEC_dflround		= 5
};

/// IDEC Exception Flags
typedef enum IDEC_BitFlag {
	IDEC_allflagsclear	= 0x00,
	IDEC_invalid		= 0x01,
	IDEC_zerodivide		= 0x04,
	IDEC_overflow		= 0x08,
	IDEC_underflow		= 0x10,
	IDEC_inexact		= 0x20
};

static unsigned int IDEC_Flag = (IDEC_zerodivide|IDEC_overflow);
static IDEC_RoundingMode IDEC_Mode = IDEC_RoundingMode::IDEC_nearesteven;

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if defined(WITH_ANTI_CHEAT)
 #include "SCUE4.h"
#endif

#include "MoneyTable.h"
#include "Moneytalks.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Types Definitions

UENUM(BlueprintType, meta = (DisplayName = "ISO-4217 Codes"))
enum class EDEC_ISO4217 : uint8 {
	NUL, 	//	No Currency
	AED, 	//	United Arab Emirates dirham 
	AFN, 	//	Afghan afghani 
	ALL, 	//	Albanian lek 
	AMD, 	//	Armenian dram 
	ANG, 	//	Netherlands Antillean guilder 
	AOA, 	//	Angolan kwanza 
	ARS, 	//	Argentine peso 
	AUD, 	//	Australian dollar 
	AWG, 	//	Aruban florin 
	AZN, 	//	Azerbaijani manat 
	BAM, 	//	Bosnia and Herzegovina convertible mark 
	BBD, 	//	Barbados dollar 
	BDT, 	//	Bangladeshi taka 
	BGN, 	//	Bulgarian lev 
	BHD, 	//	Bahraini dinar 
	BIF, 	//	Burundian franc 
	BMD, 	//	Bermudian dollar 
	BND, 	//	Brunei dollar 
	BOB, 	//	Boliviano 
	BOV, 	//	Bolivian Mvdol (funds code) 
	BRL, 	//	Brazilian real 
	BSD, 	//	Bahamian dollar 
	BTN, 	//	Bhutanese ngultrum 
	BWP, 	//	Botswana pula 
	BYN, 	//	New Belarusian ruble 
	BYR, 	//	Belarusian ruble 
	BZD, 	//	Belize dollar 
	CAD, 	//	Canadian dollar 
	CDF, 	//	Congolese franc 
	CHE, 	//	WIR Euro (complementary currency) 
	CHF, 	//	Swiss franc 
	CHW, 	//	WIR Franc (complementary currency) 
	CLF, 	//	Unidad de Fomento (funds code) 
	CLP, 	//	Chilean peso 
	CNY, 	//	Chinese yuan 
	COP, 	//	Colombian peso 
	COU, 	//	Unidad de Valor Real (UVR) (funds code)[7] 
	CRC, 	//	Costa Rican colon 
	CUC, 	//	Cuban convertible peso 
	CUP, 	//	Cuban peso 
	CVE, 	//	Cape Verde escudo 
	CZK, 	//	Czech koruna 
	DJF, 	//	Djiboutian franc 
	DKK, 	//	Danish krone 
	DOP, 	//	Dominican peso 
	DZD, 	//	Algerian dinar 
	EGP, 	//	Egyptian pound 
	ERN, 	//	Eritrean nakfa 
	ETB, 	//	Ethiopian birr 
	EUR, 	//	Euro 
	FJD, 	//	Fiji dollar 
	FKP, 	//	Falkland Islands pound 
	GBP, 	//	Pound sterling 
	GEL, 	//	Georgian lari 
	GHS, 	//	Ghanaian cedi 
	GIP, 	//	Gibraltar pound 
	GMD, 	//	Gambian dalasi 
	GNF, 	//	Guinean franc 
	GTQ, 	//	Guatemalan quetzal 
	GYD, 	//	Guyanese dollar 
	HKD, 	//	Hong Kong dollar 
	HNL, 	//	Honduran lempira 
	HRK, 	//	Croatian kuna 
	HTG, 	//	Haitian gourde 
	HUF, 	//	Hungarian forint 
	IDR, 	//	Indonesian rupiah 
	ILS, 	//	Israeli new shekel 
	INR, 	//	Indian rupee 
	IQD, 	//	Iraqi dinar 
	IRR, 	//	Iranian rial 
	ISK, 	//	Icelandic króna 
	JMD, 	//	Jamaican dollar 
	JOD, 	//	Jordanian dinar 
	JPY, 	//	Japanese yen 
	KES, 	//	Kenyan shilling 
	KGS, 	//	Kyrgyzstani som 
	KHR, 	//	Cambodian riel 
	KMF, 	//	Comoro franc 
	KPW, 	//	North Korean won 
	KRW, 	//	South Korean won 
	KWD, 	//	Kuwaiti dinar 
	KYD, 	//	Cayman Islands dollar 
	KZT, 	//	Kazakhstani tenge 
	LAK, 	//	Lao kip 
	LBP, 	//	Lebanese pound 
	LKR, 	//	Sri Lankan rupee 
	LRD, 	//	Liberian dollar 
	LSL, 	//	Lesotho loti 
	LYD, 	//	Libyan dinar 
	MAD, 	//	Moroccan dirham 
	MDL, 	//	Moldovan leu 
	MGA, 	//	Malagasy ariary 
	MKD, 	//	Macedonian denar 
	MMK, 	//	Myanmar kyat 
	MNT, 	//	Mongolian tögrög 
	MOP, 	//	Macanese pataca 
	MRO, 	//	Mauritanian ouguiya 
	MUR, 	//	Mauritian rupee 
	MVR, 	//	Maldivian rufiyaa 
	MWK, 	//	Malawian kwacha 
	MXN, 	//	Mexican peso 
	MXV, 	//	Mexican Unidad de Inversion (UDI) (funds code) 
	MYR, 	//	Malaysian ringgit 
	MZN, 	//	Mozambican metical 
	NAD, 	//	Namibian dollar 
	NGN, 	//	Nigerian naira 
	NIO, 	//	Nicaraguan córdoba 
	NOK, 	//	Norwegian krone 
	NPR, 	//	Nepalese rupee 
	NZD, 	//	New Zealand dollar 
	OMR, 	//	Omani rial 
	PAB, 	//	Panamanian balboa 
	PEN, 	//	Peruvian Sol 
	PGK, 	//	Papua New Guinean kina 
	PHP, 	//	Philippine peso 
	PKR, 	//	Pakistani rupee 
	PLN, 	//	Polish złoty 
	PYG, 	//	Paraguayan guaraní 
	QAR, 	//	Qatari riyal 
	RON, 	//	Romanian leu 
	RSD, 	//	Serbian dinar 
	RUB, 	//	Russian ruble 
	RWF, 	//	Rwandan franc 
	SAR, 	//	Saudi riyal 
	SBD, 	//	Solomon Islands dollar 
	SCR, 	//	Seychelles rupee 
	SDG, 	//	Sudanese pound 
	SEK, 	//	Swedish krona/kronor 
	SGD, 	//	Singapore dollar 
	SHP, 	//	Saint Helena pound 
	SLL, 	//	Sierra Leonean leone 
	SOS, 	//	Somali shilling 
	SRD, 	//	Surinamese dollar 
	SSP, 	//	South Sudanese pound 
	STD, 	//	São Tomé and Príncipe dobra 
	SVC, 	//	Salvadoran colón 
	SYP, 	//	Syrian pound 
	SZL, 	//	Swazi lilangeni 
	THB, 	//	Thai baht 
	TJS, 	//	Tajikistani somoni 
	TMT, 	//	Turkmenistani manat 
	TND, 	//	Tunisian dinar 
	TOP, 	//	Tongan paʻanga 
	TRY, 	//	Turkish lira 
	TTD, 	//	Trinidad and Tobago dollar 
	TWD, 	//	New Taiwan dollar 
	TZS, 	//	Tanzanian shilling 
	UAH, 	//	Ukrainian hryvnia 
	UGX, 	//	Ugandan shilling 
	USD, 	//	United States dollar 
	USN, 	//	United States dollar (next day) (funds code) 
	UYI, 	//	Uruguay Peso en Unidades Indexadas (URUIURUI) (funds code) 
	UYU, 	//	Uruguayan peso 
	UZS, 	//	Uzbekistan som 
	VEF, 	//	Venezuelan bolívar 
	VND, 	//	Vietnamese dong 
	VUV, 	//	Vanuatu vatu 
	WST, 	//	Samoan tala 
	XAF, 	//	CFA franc BEAC 
	XAG, 	//	Silver (one troy ounce) 
	XAU, 	//	Gold (one troy ounce) 
	XBA, 	//	European Composite Unit (EURCO) (bond market unit) 
	XBB, 	//	European Monetary Unit (E.M.U.-6) (bond market unit) 
	XBC, 	//	European Unit of Account 9 (E.U.A.-9) (bond market unit) 
	XBD, 	//	European Unit of Account 17 (E.U.A.-17) (bond market unit) 
	XCD, 	//	East Caribbean dollar 
	XDR, 	//	Special drawing rights 
	XOF, 	//	CFA franc BCEAO 
	XPD, 	//	Palladium (one troy ounce) 
	XPF, 	//	CFP franc (franc Pacifique) 
	XPT, 	//	Platinum (one troy ounce) 
	XSU, 	//	SUCRE 
	XTS, 	//	Code reserved for testing purposes 
	XUA, 	//	ADB Unit of Account 
	YER, 	//	Yemeni rial 
	ZAR, 	//	South African rand 
	ZMW, 	//	Zambian kwacha 
	ZWL, 	//	Zimbabwean dollar A/10 
};

UENUM(BlueprintType, meta = (DisplayName = "Decimal Display Format"))
enum class EDEC_DisplayFormat : uint8 {
	PrefixNoSpace,
	PrefixWithSpace,
	PostfixNoSpace,
	PostfixWithSpace
};

UENUM(BlueprintType, meta = (DisplayName = "Decimal Rounding Mode"))
enum class DEC_RoundingMode : uint8 {
	NearestEven,
	Downward,
	Upward,
	TowardZero,
	NearestAway,
	DFLRound
};

UENUM(BlueprintType, meta = (DisplayName = "Decimal Base Mode"))
enum class DEC_BaseMode : uint8 {
	Ceil,
	Floor
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Utilities

UCLASS(ClassGroup = Synaptech, Category = "Synaptech")
class MONEYTALKS_API UMT : public UObject {
	GENERATED_UCLASS_BODY()
public:
	/// Currency Symbols
	UPROPERTY(Category = "DATA|Currencies", EditDefaultsOnly)
	const UDataTable* Currency;
};

/// 10^24 Decimal, 128 Bits Unsigned Integer.
#define MAX_DECIMAL FDecimal("99999999999999999999999999999")

#define DEC(Value) FDecimal(Value)
#define NOTEXT TEXT("")

const static bool FIsNumeral(const TCHAR C) {
	return ((TCHAR('0') <= C)&&(C <= TCHAR('9')));
}

const static FString FStringCutAt(const FString &Input, uint32 Index) {
	FString RET; uint32 I=0;
	for (const auto C : Input) {
		if (I>=Index) {break;} I++;
		RET.Append(&C,1);
	} return RET;
}

const static EDEC_ISO4217 FISOHash(const FString &Code) {
	if (Code == TEXT("AED")) {return EDEC_ISO4217::AED;}
	if (Code == TEXT("AFN")) {return EDEC_ISO4217::AFN;}
	if (Code == TEXT("ALL")) {return EDEC_ISO4217::ALL;}
	if (Code == TEXT("AMD")) {return EDEC_ISO4217::AMD;}
	if (Code == TEXT("ANG")) {return EDEC_ISO4217::ANG;}
	if (Code == TEXT("AOA")) {return EDEC_ISO4217::AOA;}
	if (Code == TEXT("ARS")) {return EDEC_ISO4217::ARS;}
	if (Code == TEXT("AUD")) {return EDEC_ISO4217::AUD;}
	if (Code == TEXT("AWG")) {return EDEC_ISO4217::AWG;}
	if (Code == TEXT("AZN")) {return EDEC_ISO4217::AZN;}
	if (Code == TEXT("BAM")) {return EDEC_ISO4217::BAM;}
	if (Code == TEXT("BBD")) {return EDEC_ISO4217::BBD;}
	if (Code == TEXT("BDT")) {return EDEC_ISO4217::BDT;}
	if (Code == TEXT("BGN")) {return EDEC_ISO4217::BGN;}
	if (Code == TEXT("BHD")) {return EDEC_ISO4217::BHD;}
	if (Code == TEXT("BIF")) {return EDEC_ISO4217::BIF;}
	if (Code == TEXT("BMD")) {return EDEC_ISO4217::BMD;}
	if (Code == TEXT("BND")) {return EDEC_ISO4217::BND;}
	if (Code == TEXT("BOB")) {return EDEC_ISO4217::BOB;}
	if (Code == TEXT("BOV")) {return EDEC_ISO4217::BOV;}
	if (Code == TEXT("BRL")) {return EDEC_ISO4217::BRL;}
	if (Code == TEXT("BSD")) {return EDEC_ISO4217::BSD;}
	if (Code == TEXT("BTN")) {return EDEC_ISO4217::BTN;}
	if (Code == TEXT("BWP")) {return EDEC_ISO4217::BWP;}
	if (Code == TEXT("BYN")) {return EDEC_ISO4217::BYN;}
	if (Code == TEXT("BYR")) {return EDEC_ISO4217::BYR;}
	if (Code == TEXT("BZD")) {return EDEC_ISO4217::BZD;}
	if (Code == TEXT("CAD")) {return EDEC_ISO4217::CAD;}
	if (Code == TEXT("CDF")) {return EDEC_ISO4217::CDF;}
	if (Code == TEXT("CHE")) {return EDEC_ISO4217::CHE;}
	if (Code == TEXT("CHF")) {return EDEC_ISO4217::CHF;}
	if (Code == TEXT("CHW")) {return EDEC_ISO4217::CHW;}
	if (Code == TEXT("CLF")) {return EDEC_ISO4217::CLF;}
	if (Code == TEXT("CLP")) {return EDEC_ISO4217::CLP;}
	if (Code == TEXT("CNY")) {return EDEC_ISO4217::CNY;}
	if (Code == TEXT("COP")) {return EDEC_ISO4217::COP;}
	if (Code == TEXT("COU")) {return EDEC_ISO4217::COU;}
	if (Code == TEXT("CRC")) {return EDEC_ISO4217::CRC;}
	if (Code == TEXT("CUC")) {return EDEC_ISO4217::CUC;}
	if (Code == TEXT("CUP")) {return EDEC_ISO4217::CUP;}
	if (Code == TEXT("CVE")) {return EDEC_ISO4217::CVE;}
	if (Code == TEXT("CZK")) {return EDEC_ISO4217::CZK;}
	if (Code == TEXT("DJF")) {return EDEC_ISO4217::DJF;}
	if (Code == TEXT("DKK")) {return EDEC_ISO4217::DKK;}
	if (Code == TEXT("DOP")) {return EDEC_ISO4217::DOP;}
	if (Code == TEXT("DZD")) {return EDEC_ISO4217::DZD;}
	if (Code == TEXT("EGP")) {return EDEC_ISO4217::EGP;}
	if (Code == TEXT("ERN")) {return EDEC_ISO4217::ERN;}
	if (Code == TEXT("ETB")) {return EDEC_ISO4217::ETB;}
	if (Code == TEXT("EUR")) {return EDEC_ISO4217::EUR;}
	if (Code == TEXT("FJD")) {return EDEC_ISO4217::FJD;}
	if (Code == TEXT("FKP")) {return EDEC_ISO4217::FKP;}
	if (Code == TEXT("GBP")) {return EDEC_ISO4217::GBP;}
	if (Code == TEXT("GEL")) {return EDEC_ISO4217::GEL;}
	if (Code == TEXT("GHS")) {return EDEC_ISO4217::GHS;}
	if (Code == TEXT("GIP")) {return EDEC_ISO4217::GIP;}
	if (Code == TEXT("GMD")) {return EDEC_ISO4217::GMD;}
	if (Code == TEXT("GNF")) {return EDEC_ISO4217::GNF;}
	if (Code == TEXT("GTQ")) {return EDEC_ISO4217::GTQ;}
	if (Code == TEXT("GYD")) {return EDEC_ISO4217::GYD;}
	if (Code == TEXT("HKD")) {return EDEC_ISO4217::HKD;}
	if (Code == TEXT("HNL")) {return EDEC_ISO4217::HNL;}
	if (Code == TEXT("HRK")) {return EDEC_ISO4217::HRK;}
	if (Code == TEXT("HTG")) {return EDEC_ISO4217::HTG;}
	if (Code == TEXT("HUF")) {return EDEC_ISO4217::HUF;}
	if (Code == TEXT("IDR")) {return EDEC_ISO4217::IDR;}
	if (Code == TEXT("ILS")) {return EDEC_ISO4217::ILS;}
	if (Code == TEXT("INR")) {return EDEC_ISO4217::INR;}
	if (Code == TEXT("IQD")) {return EDEC_ISO4217::IQD;}
	if (Code == TEXT("IRR")) {return EDEC_ISO4217::IRR;}
	if (Code == TEXT("ISK")) {return EDEC_ISO4217::ISK;}
	if (Code == TEXT("JMD")) {return EDEC_ISO4217::JMD;}
	if (Code == TEXT("JOD")) {return EDEC_ISO4217::JOD;}
	if (Code == TEXT("JPY")) {return EDEC_ISO4217::JPY;}
	if (Code == TEXT("KES")) {return EDEC_ISO4217::KES;}
	if (Code == TEXT("KGS")) {return EDEC_ISO4217::KGS;}
	if (Code == TEXT("KHR")) {return EDEC_ISO4217::KHR;}
	if (Code == TEXT("KMF")) {return EDEC_ISO4217::KMF;}
	if (Code == TEXT("KPW")) {return EDEC_ISO4217::KPW;}
	if (Code == TEXT("KRW")) {return EDEC_ISO4217::KRW;}
	if (Code == TEXT("KWD")) {return EDEC_ISO4217::KWD;}
	if (Code == TEXT("KYD")) {return EDEC_ISO4217::KYD;}
	if (Code == TEXT("KZT")) {return EDEC_ISO4217::KZT;}
	if (Code == TEXT("LAK")) {return EDEC_ISO4217::LAK;}
	if (Code == TEXT("LBP")) {return EDEC_ISO4217::LBP;}
	if (Code == TEXT("LKR")) {return EDEC_ISO4217::LKR;}
	if (Code == TEXT("LRD")) {return EDEC_ISO4217::LRD;}
	if (Code == TEXT("LSL")) {return EDEC_ISO4217::LSL;}
	if (Code == TEXT("LYD")) {return EDEC_ISO4217::LYD;}
	if (Code == TEXT("MAD")) {return EDEC_ISO4217::MAD;}
	if (Code == TEXT("MDL")) {return EDEC_ISO4217::MDL;}
	if (Code == TEXT("MGA")) {return EDEC_ISO4217::MGA;}
	if (Code == TEXT("MKD")) {return EDEC_ISO4217::MKD;}
	if (Code == TEXT("MMK")) {return EDEC_ISO4217::MMK;}
	if (Code == TEXT("MNT")) {return EDEC_ISO4217::MNT;}
	if (Code == TEXT("MOP")) {return EDEC_ISO4217::MOP;}
	if (Code == TEXT("MRO")) {return EDEC_ISO4217::MRO;}
	if (Code == TEXT("MUR")) {return EDEC_ISO4217::MUR;}
	if (Code == TEXT("MVR")) {return EDEC_ISO4217::MVR;}
	if (Code == TEXT("MWK")) {return EDEC_ISO4217::MWK;}
	if (Code == TEXT("MXN")) {return EDEC_ISO4217::MXN;}
	if (Code == TEXT("MXV")) {return EDEC_ISO4217::MXV;}
	if (Code == TEXT("MYR")) {return EDEC_ISO4217::MYR;}
	if (Code == TEXT("MZN")) {return EDEC_ISO4217::MZN;}
	if (Code == TEXT("NAD")) {return EDEC_ISO4217::NAD;}
	if (Code == TEXT("NGN")) {return EDEC_ISO4217::NGN;}
	if (Code == TEXT("NIO")) {return EDEC_ISO4217::NIO;}
	if (Code == TEXT("NOK")) {return EDEC_ISO4217::NOK;}
	if (Code == TEXT("NPR")) {return EDEC_ISO4217::NPR;}
	if (Code == TEXT("NZD")) {return EDEC_ISO4217::NZD;}
	if (Code == TEXT("OMR")) {return EDEC_ISO4217::OMR;}
	if (Code == TEXT("PAB")) {return EDEC_ISO4217::PAB;}
	if (Code == TEXT("PEN")) {return EDEC_ISO4217::PEN;}
	if (Code == TEXT("PGK")) {return EDEC_ISO4217::PGK;}
	if (Code == TEXT("PHP")) {return EDEC_ISO4217::PHP;}
	if (Code == TEXT("PKR")) {return EDEC_ISO4217::PKR;}
	if (Code == TEXT("PLN")) {return EDEC_ISO4217::PLN;}
	if (Code == TEXT("PYG")) {return EDEC_ISO4217::PYG;}
	if (Code == TEXT("QAR")) {return EDEC_ISO4217::QAR;}
	if (Code == TEXT("RON")) {return EDEC_ISO4217::RON;}
	if (Code == TEXT("RSD")) {return EDEC_ISO4217::RSD;}
	if (Code == TEXT("RUB")) {return EDEC_ISO4217::RUB;}
	if (Code == TEXT("RWF")) {return EDEC_ISO4217::RWF;}
	if (Code == TEXT("SAR")) {return EDEC_ISO4217::SAR;}
	if (Code == TEXT("SBD")) {return EDEC_ISO4217::SBD;}
	if (Code == TEXT("SCR")) {return EDEC_ISO4217::SCR;}
	if (Code == TEXT("SDG")) {return EDEC_ISO4217::SDG;}
	if (Code == TEXT("SEK")) {return EDEC_ISO4217::SEK;}
	if (Code == TEXT("SGD")) {return EDEC_ISO4217::SGD;}
	if (Code == TEXT("SHP")) {return EDEC_ISO4217::SHP;}
	if (Code == TEXT("SLL")) {return EDEC_ISO4217::SLL;}
	if (Code == TEXT("SOS")) {return EDEC_ISO4217::SOS;}
	if (Code == TEXT("SRD")) {return EDEC_ISO4217::SRD;}
	if (Code == TEXT("SSP")) {return EDEC_ISO4217::SSP;}
	if (Code == TEXT("STD")) {return EDEC_ISO4217::STD;}
	if (Code == TEXT("SVC")) {return EDEC_ISO4217::SVC;}
	if (Code == TEXT("SYP")) {return EDEC_ISO4217::SYP;}
	if (Code == TEXT("SZL")) {return EDEC_ISO4217::SZL;}
	if (Code == TEXT("THB")) {return EDEC_ISO4217::THB;}
	if (Code == TEXT("TJS")) {return EDEC_ISO4217::TJS;}
	if (Code == TEXT("TMT")) {return EDEC_ISO4217::TMT;}
	if (Code == TEXT("TND")) {return EDEC_ISO4217::TND;}
	if (Code == TEXT("TOP")) {return EDEC_ISO4217::TOP;}
	if (Code == TEXT("TRY")) {return EDEC_ISO4217::TRY;}
	if (Code == TEXT("TTD")) {return EDEC_ISO4217::TTD;}
	if (Code == TEXT("TWD")) {return EDEC_ISO4217::TWD;}
	if (Code == TEXT("TZS")) {return EDEC_ISO4217::TZS;}
	if (Code == TEXT("UAH")) {return EDEC_ISO4217::UAH;}
	if (Code == TEXT("UGX")) {return EDEC_ISO4217::UGX;}
	if (Code == TEXT("USD")) {return EDEC_ISO4217::USD;}
	if (Code == TEXT("USN")) {return EDEC_ISO4217::USN;}
	if (Code == TEXT("UYI")) {return EDEC_ISO4217::UYI;}
	if (Code == TEXT("UYU")) {return EDEC_ISO4217::UYU;}
	if (Code == TEXT("UZS")) {return EDEC_ISO4217::UZS;}
	if (Code == TEXT("VEF")) {return EDEC_ISO4217::VEF;}
	if (Code == TEXT("VND")) {return EDEC_ISO4217::VND;}
	if (Code == TEXT("VUV")) {return EDEC_ISO4217::VUV;}
	if (Code == TEXT("WST")) {return EDEC_ISO4217::WST;}
	if (Code == TEXT("XAF")) {return EDEC_ISO4217::XAF;}
	if (Code == TEXT("XAG")) {return EDEC_ISO4217::XAG;}
	if (Code == TEXT("XAU")) {return EDEC_ISO4217::XAU;}
	if (Code == TEXT("XBA")) {return EDEC_ISO4217::XBA;}
	if (Code == TEXT("XBB")) {return EDEC_ISO4217::XBB;}
	if (Code == TEXT("XBC")) {return EDEC_ISO4217::XBC;}
	if (Code == TEXT("XBD")) {return EDEC_ISO4217::XBD;}
	if (Code == TEXT("XCD")) {return EDEC_ISO4217::XCD;}
	if (Code == TEXT("XDR")) {return EDEC_ISO4217::XDR;}
	if (Code == TEXT("XOF")) {return EDEC_ISO4217::XOF;}
	if (Code == TEXT("XPD")) {return EDEC_ISO4217::XPD;}
	if (Code == TEXT("XPF")) {return EDEC_ISO4217::XPF;}
	if (Code == TEXT("XPT")) {return EDEC_ISO4217::XPT;}
	if (Code == TEXT("XSU")) {return EDEC_ISO4217::XSU;}
	if (Code == TEXT("XTS")) {return EDEC_ISO4217::XTS;}
	if (Code == TEXT("XUA")) {return EDEC_ISO4217::XUA;}
	if (Code == TEXT("YER")) {return EDEC_ISO4217::YER;}
	if (Code == TEXT("ZAR")) {return EDEC_ISO4217::ZAR;}
	if (Code == TEXT("ZMW")) {return EDEC_ISO4217::ZMW;}
	if (Code == TEXT("ZWL")) {return EDEC_ISO4217::ZWL;}
	//
	return EDEC_ISO4217::NUL;
}

const static FString FGetCurrencySymbol(const FString &Currency) {
	const auto &MT = GetDefault<UMT>();
	//
	FString CUR = Currency.Replace(TEXT(" "),TEXT(""),ESearchCase::IgnoreCase);
	if (CUR.IsValidIndex(3)) {CUR = FStringCutAt(CUR,3);}
	//
	FString SYB = FCurrencySymbol(MT->Currency,*CUR,177);
	if (SYB.Len()>0) {return SYB;} return CUR;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FDecimal

/* Decimal Property.
 Use this data format to store decimal numbers.
 Maximum Value: -999 Septillion up to 999 Septillion (10^24) (29 Digits). */

USTRUCT(BlueprintType)
struct MONEYTALKS_API FDecimal {
	GENERATED_USTRUCT_BODY()
private:
	/// 128 Bits Storage.
	BID_UINT128 Internal;
public:
	/// :: Accessors ::
	//
	double  ToDouble()  const;
	uint32  ToUInt32()  const;
	uint64  ToUInt64()  const;
	int32   ToInt32()   const;
	int64   ToInt64()   const;
	float   ToFloat()   const;
	//
	double  ToDouble(const DEC_RoundingMode &Mode);
	float   ToFloat(const DEC_RoundingMode &Mode);
	uint32  ToUInt32(const DEC_BaseMode &Mode);
	uint64  ToUInt64(const DEC_BaseMode &Mode);
	int32   ToInt32(const DEC_BaseMode &Mode);
	int64   ToInt64(const DEC_BaseMode &Mode);
	//
	FString ToString();
	//
	/** Converts this Decimal number to a formatted number string. */
	FString ToDecorated(const FString &Integral = TEXT("."));
	//
	/**	Converts this Decimal number to a FText representation:
	@ Currency: ISO-4217 Currency Code or any Prefix String.
	@ Integral: Symbol used to split integral groups.
	@ Fractional: Symbol used to split the monetary fractions.
	Note: ISO Currency Codes may return Unicode symbols. */
	FText ToCurrency(const EDEC_DisplayFormat &Culture = EDEC_DisplayFormat::PrefixNoSpace, const FString &Currency = TEXT(""), const FString &Integral = TEXT(","), const FString &Fractional = TEXT("."));
	//
	/** Returns Decimal Percent of this Decimal:
	@ X = This.
	@ P% = Y / 100
	@ Y = P% * X
	@ Return Y */
	FText GetValueOfPercentage(const FDecimal &Percentage);
	//
	/** Returns Percentage between Value and this Decimal:
	@ X = This.
	@ P% = Y / X
	@ Return P% * 100
	Note: Will fail when Y > Max Int32. */
	FText GetPercentageOfValue(const FDecimal &Value);
	//
	/** Returns Decimal Percent of this Decimal:
	@ X = This.
	@ P% = Y / 100
	@ Y = P% * X
	@ Return Y */
	FDecimal GetPercentage(const FDecimal &Percentage);
public:
	/// :: Constructors ::
	//
	FDecimal() {
		Internal = BID_UINT128();
	}///
	//
	FDecimal(const FDecimal &D) {
		Internal = D.Internal;
	}///
	//
	FDecimal(const float F) {
		Internal = binary32_to_bid128(F,IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
	}///
	//
	FDecimal(const double D) {
		Internal = binary64_to_bid128(D,IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
	}///
	//
	FDecimal(const uint32 I) {
		Internal = bid128_from_uint32(I);
	}///
	//
	FDecimal(const uint64 I) {
		Internal = bid128_from_uint64(I);
	}///
	//
	FDecimal(const int32 I) {
		Internal = bid128_from_int32(I);
	}///
	//
	FDecimal(const int64 I) {
		Internal = bid128_from_int64(I);
	}///
	//
	FDecimal(const FString Input) {
		FString PARSE; int32 I=0;
		for (const auto C : Input) {
			if (I==0 && C == TCHAR('-')) {PARSE.AppendChar(C);}
			if (FIsNumeral(C)) {PARSE.AppendChar(C);}
		I++;}
		//
		Internal = bid128_from_string(TCHAR_TO_ANSI(*PARSE),IDEC_Mode,&IDEC_Flag);
	}///
public:
	/// :: Operators ::
	//
	template<class T>
	FORCEINLINE FDecimal & operator = (const T &Value) {
		FDecimal D(Value); Internal = D.Internal; return *this;
	}///
	//
	FORCEINLINE FDecimal & operator = (const FDecimal &D) {
		this->Internal = D.Internal; return *this;
	}///
	//
	friend FORCEINLINE FArchive & operator << (FArchive &Ar, FDecimal &DC) {
		FString L, M, H;
		DC.Unpack(L,M,H);
		//
		Ar << L;
		Ar << M;
		Ar << H;
		//
		if (Ar.IsLoading()) {
			DC.Construct(L,M,H);
		} return Ar;
	}///
	//
	FORCEINLINE bool operator == (const FDecimal &DC) const {
		int32 RET = bid128_quiet_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator != (const FDecimal &DC) const {
		int32 RET = bid128_quiet_not_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator < (const FDecimal &DC) const {
		int32 RET = bid128_quiet_less(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator <= (const FDecimal &DC) const {
		int32 RET = bid128_quiet_less_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator > (const FDecimal &DC) const {
		int32 RET = bid128_quiet_greater(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		return (RET == 0 ? true:false);
	}///
	//
	FORCEINLINE bool operator >= (const FDecimal &DC) const {
		int32 RET = bid128_quiet_greater_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		return (RET == 0 ? true:false);
	}///
	//
	FORCEINLINE bool operator == (const FDecimal &DC) {
		int32 RET = bid128_quiet_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator != (const FDecimal &DC) {
		int32 RET = bid128_quiet_not_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator < (const FDecimal &DC) {
		int32 RET = bid128_quiet_less(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator <= (const FDecimal &DC) {
		int32 RET = bid128_quiet_less_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		if (RET==0) {return true;} return false;
	}///
	//
	FORCEINLINE bool operator > (const FDecimal &DC) {
		int32 RET = bid128_quiet_greater(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		return (RET == 0 ? true:false);
	}///
	//
	FORCEINLINE bool operator >= (const FDecimal &DC) {
		int32 RET = bid128_quiet_greater_equal(Internal,DC.GetRaw(),(_IDEC_flags*)&IDEC_Flag);
		return (RET == 0 ? true:false);
	}///
	//
	FORCEINLINE FDecimal &operator + (const FDecimal &DC) {
		const auto &BID = bid128_add(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator - (const FDecimal &DC) {
		const auto &BID = bid128_sub(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator * (const FDecimal &DC) {
		const auto &BID = bid128_mul(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator / (const FDecimal &DC) {
		const auto &BID = bid128_div(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator += (const FDecimal &DC) {
		const auto &BID = bid128_add(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags *) &IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator -= (const FDecimal &DC) {
		const auto &BID = bid128_sub(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator *= (const FDecimal &DC) {
		const auto &BID = bid128_mul(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator /= (const FDecimal &DC) {
		const auto &BID = bid128_div(Internal,DC.GetRaw(),IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		Internal = BID; return *this;
	}///
	//
	FORCEINLINE FDecimal &operator ++ () {
		BID_UINT128 B;
		//
		B.w[HIGH_128W] = 0x3040000000000000ull; 
		B.w[LOW_128W] = 0x0000000000000001ull;
		//
		Internal = bid128_add(Internal,B,IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		//
		return *this;
	}///
	//
	FORCEINLINE FDecimal &operator -- () {
		BID_UINT128 B;
		//
		B.w[HIGH_128W] = 0x3040000000000000ull; 
		B.w[LOW_128W] = 0x0000000000000001ull;
		//
		Internal = bid128_sub(Internal,B,IDEC_Mode,(_IDEC_flags*)&IDEC_Flag);
		//
		return *this;
	}///
	//
	FORCEINLINE FDecimal &operator ++ (int32 I) {
		return ++(*this);
	}///
	//
	FORCEINLINE FDecimal &operator -- (int32 I) {
		return --(*this);
	}///
	//
	//
	friend FORCEINLINE uint32 GetTypeHash(const FDecimal &DC) {
		return FCrc::MemCrc32(&DC,sizeof(FDecimal));
	}///
public:
	/// :: Utility ::
	//
	BID_UINT128 GetRaw() const {return Internal;}
	//
	void SetRaw(const BID_UINT128 &BID) {Internal = BID;}
	void Construct(FString Low, FString Mid, FString High);
	void Unpack(FString &Low, FString &Mid, FString &High);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////