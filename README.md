# MONEYTALKS PLUGIN -- UNREAL ENGINE 4

* This Plugin implements data types to represent Decimals and Money values compatible with the Unreal Engine environment.
* All Currency types introduced are IEEE 754 compliant, C++ Classes to represent accurate world currencies defined by ISO 4217.
* The FDecimal type can store up to 10^24 (29 signed digits): 99,999,999,999,999,999,999,999,999,999;
* The FDecimal struct can be used by both C++ and Blueprint objects and actors in Unreal.

* Replication and Serialization are handled by converting from Decimal to a subset of TCHAR* packs to maintain precision.
* Implementation is based on Intel RDFP Math Library: Copyright(C) 2011, Intel Corporation. All rights reserved.



## How to Use (Blueprints):

* Add new Property to Blueprint.
* Change Property type to 'Decimal'.
* Use operator nodes and operators from category 'Variables | Decimal'.



## C++ Example:

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
