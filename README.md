# MONEYTALKS PLUGIN -- UNREAL ENGINE 4

* This Plugin implements for you accurate data types to represent Decimals and Money values compatible with the Unreal Engine environment.
* All Currency types introduced are IEEE 754 compliant, C++ Classes to represent accurate world currencies defined by ISO 4217.
* The FDecimal type can store up to 10^24 (29 signed digits): 99.999.999.999.999.999.999.999.999.999;
* The FDecimal type can be used on both C++ and Blueprint objects and actors.
* Replication and Serialization are handled by converting from Decimal to a subset of TCHAR* packs to maintain absolute precision.
* The FDecimal type introduced is optionally compatible with the FSafe Structs from the SCUE4 Anti-Cheat system:
  https://www.unrealengine.com/marketplace/scue4-anti-cheat-solution
* Implementation is based on Intel RDFP Math Library: Copyright(C) 2011, Intel Corporation. All rights reserved.


## Why not use Float or Double to store in-game currency?

* Because floats and doubles cannot accurately represent the 'Base 10' multiples used for money representation.
  The problem with floats is that the majority of money-like numbers don't have exact representation as integer times power of two.
  Representing money as a double or float will probably look good at first as the software rounds off the tiny errors, but as you perform
  more additions, subtractions, multiplications, divisions on inexact numbers, you'll lose more and more precision as the errors add up.
  This makes floats and doubles inadequate for dealing with money values, where perfect accuracy for multiples of Base 10 is required.
  While using Int32 or Int64 you are limited by size and cannot accurately represent real-world monetary numbers.
  The FDecimal have large precision of 128 Bits to guarantee your players will not lose any in-game currency during regular transactions.
  This is invaluable for games where the player must be able to store large amounts of money, such as RPG tiles.

  
## Why Intel's Decimal Floating-Point Math Library?

* Decimal floating-point operations were a necessity from the beginnings of the modern age of computing.
  However, the lack of a good standard for decimal computations has led to the existence of numerous proprietary software packages for
  decimal or decimal-like computation, most based on fixed-point decimal types, and each with its own characteristics and capabilities.
  A turning point for decimal computation is the revision of the IEEE Standard 754-2008 for Binary Floating-Point Arithmetic
  as an important addition to it is the definition of decimal floating-point arithmetic. The primary motivation was that decimal
  arithmetic makes numerical calculations more human-friendly. Results will be as people expect them, identical to what would be obtained
  using pencil and paper. Decimal arithmetic also provides a robust, reliable framework for financial applications that are often subject
  to legal requirements concerning rounding and precision of the results in the areas of banking, telephone billing, tax calculation,
  currency conversion, insurance, or accounting in general. The binary floating-point arithmetic that computers use does not always
  satisfy the existing accuracy requirements. For example, (7.00 / 10000.0) * 10000.0 calculated in single precision is 6.9999997504,
  and not 7.00. Similar examples can be found for double precision, or any other binary floating-point format. The underlying cause is
  that most decimal fractions, such as 0.1, cannot be represented exactly in binary floating-point format. The IEEE 754 standard proposal
  attempts to resolve such issues by defining all the rules for decimal floating-point arithmetic in a way that can be adopted and
  implemented on all computing systems in software, hardware, or a combination of the two.
  Intel's implementation will run on any platform based on Linux™, Windows™, HP-UX™, Solaris™, or OSX™.
  

### Example Usage:

```csharp
PublicDependencyModuleNames.AddRange(new string[] {"Moneytalks","Core","CoreUObject","Engine","InputCore"});
```

```cpp

UCLASS()
class MYGAME_API AMyPlayerState : public APlayerState
{

	GENERATED_BODY()
	
	AMyPlayerState();
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Test", EditAnywhere, BlueprintReadWrite)
	FDecimal MyDecimal;
	
};


```

```cpp

void AMyPlayerState::BeginPlay()
{

	Super::BeginPlay();

	MyDecimal = MAX_DECIMAL;
	int32 MyInt = MAX_int32;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(0,100.f,FColor::Purple,FString::Printf(TEXT("25 Percent of %s is ::"),*MyDecimal.ToString()));
		GEngine->AddOnScreenDebugMessage(1,100.f,FColor::Purple,*MyDecimal.GetValueOfPercentage(DEC(25)).ToString());

		GEngine->AddOnScreenDebugMessage(2,100.f,FColor::Blue,FString::Printf(TEXT("%i out of %s is ::"),MyInt,*MyDecimal.ToString()));
		GEngine->AddOnScreenDebugMessage(3,100.f,FColor::Blue,*MyDecimal.GetPercentageOfValue(DEC(MyInt)).ToString());

		FString A, B, C;
		MyDecimal.Unpack(A,B,C);
		FDecimal DE; DE.Construct(A,B,C);

		GEngine->AddOnScreenDebugMessage(4,100.f,FColor::Green,FString::Printf(TEXT("UNPACK:::  %s A | %s B | %s C"),*A,*B,*C));
		GEngine->AddOnScreenDebugMessage(5,100.f,FColor::Yellow,FString::Printf(TEXT("CONSTRUCT:::  %s"),*DE.ToDecorated()));
}

void AMyPlayerState::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	MyDecimal--;
	const auto M = MyDecimal.ToCurrency(EDEC_DisplayFormat::PrefixWithSpace,TEXT("BRL"));

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1,-1,FColor::Emerald,FString::Printf(TEXT("%s"),*M.ToString()),true,FVector2D(3,3));

}


```


----------


THE MIT LICENSE

Copyright 2017 Bruno Xavier Leite

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.