// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"//컴파일 속도를 빠르게 하기위해 기본적인 최소한의 라이브러리만 포함한 헤더
#include"Public/Tools/InterfacePlayObj.h"//Actor가 상속받는것이기 때문에 Actor위에 적어주는것
#include "GameFramework/Actor.h"//AActor 클래스 헤더 파일


//*generated.h 언리얼 클래스 생성 처리하는 헤더-언리얼 클래스 생성 기본 규칙
//모든 언리어 클래스가 생성되려면 아래 코드를 넣어줘야 한다.
//반드시 모든 #include 마지막에 배치
#include "Move_leftRight.generated.h"//generated.h가 제일 마지막에 온다.



UCLASS()// 언리얼 클래스 선언
//UE5CODE_API: 이 클래스는 UE5CODE_API 모듈에 포함된다.
class UE5CODE_API AMove_leftRight : public AActor, public IInterfacePlayObj// public AActor : AActor의 기능을 상속 받겠다.
{
	GENERATED_BODY()//언리얼 코드 생성 함수-언리얼 클래스 생성 기본 규칙
	

public:	
	// Sets default values for this actor's properties
	AMove_leftRight();
	~AMove_leftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void EventOverlap(bool isBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool IsPlay);// 블루프린트 호출용 함수명 선언

	virtual void Code_DoPlay_Implementation(bool IsPlay) override;// c++에서 실행될 함수

public:
	//UPROPERTY(EditeAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;//컴포넌트탭에서 루트컴포넌트 부분


	UPROPERTY(visibleAnywhere, BlueprintReadWrite)//항상 내가 만든 변수위에 작성. 
	UStaticMeshComponent* StaticMesh;//컴포넌트탭에서 스태틱메시부분

	float m_LocX;
	bool m_IsMoveRight;
	bool m_Isplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch>m_Switch;
};
