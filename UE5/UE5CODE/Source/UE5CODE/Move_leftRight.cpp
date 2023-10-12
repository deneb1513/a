// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_leftRight.h"

// Sets default values
AMove_leftRight::AMove_leftRight() :LocX(0), IsMoveRight(true)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//CreateDefaultSubobject : new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	//TEXT : 언리얼에서 사용하는 문자형 중에 하나
	//<USceneComponent>(TEXT("SceneRoot")) //USceneComponent객체를 "SceneRoot"라는 이름으로 동적으로 생성
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	//<UStaticMeshComponent>(TEXT("myMesh")) //UStaticMeshComponent객체를 "myMesh"라는 이름으로 동적으로 생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("myMesh"));

	SetRootComponent(Scene);//Scene을 Root Component로 올리겠다.
	//RootComponent=Scene; //Scene을 Root Component로 올리겠다. //위와 동일한 처리방식

	//AttachToComponent : Component 붙이는 기능
	//Scene에 붙인다, 현재 좌표값을 Scene 기준에 Relative(상대) 좌표계로
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent에 붙인다, 현재 좌표값에 RootComponent 기준에 Relative(상대) 좌표계로
	//StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//UAsset 가져오기
	//ConstructorHelpers::FObjectFinder : 오브젝트 에셋을 찾는다.
	//<UStaticMesh> 찾을 에셋 타입
	//sm : 찾아서 넣을 객체 이름
	//TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'")) 괄호 안에 넣을 스테틱메시는 UE5에서 메시 우클릭-레퍼런스 복사 해서 붙혀넣어준다.
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	//if (sm.Succeeded())//에셋을 불러오기 성공 여부 확인
	//{
	//	StaticMesh->SetStaticMesh(sm.Object);//SetStaticMeshComponent에 StaticMesh 적용
	//}
}

AMove_leftRight::~AMove_leftRight()
{
}

// Called when the game starts or when spawned
void AMove_leftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMove_leftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//오버라이드 한 함수인 경우 부모 함수를 실행한다.
	IsMoveRight; //움직일 방향

	//LocX += 1;// 오른쪽 이동

	//LocX -= 1;//왼쪽으로 이동
	//SetRelativeLocation : 상대적인 위치값을 설정한다.
	//FVector : 언리얼에서 사용하는 3차원 좌표 변수
	StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
	if (IsMoveRight == true)
	{
		LocX += 1;
		if (LocX >= 20)//float형은 크기비교를 하는게 좋다. ==을 쓰면 에러가 발생할 수도 있음
		{
			IsMoveRight = false;
		}
	}
	else if (IsMoveRight == false)
	{
		LocX -= 1;
		if (LocX <= -20)
		{
			IsMoveRight = true;
		}
	}
}

