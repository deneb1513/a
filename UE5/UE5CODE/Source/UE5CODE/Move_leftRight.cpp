// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_leftRight.h"

// Sets default values
AMove_leftRight::AMove_leftRight() :LocX(0), IsMoveRight(true)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	//TEXT : �𸮾󿡼� ����ϴ� ������ �߿� �ϳ�
	//<USceneComponent>(TEXT("SceneRoot")) //USceneComponent��ü�� "SceneRoot"��� �̸����� �������� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	//<UStaticMeshComponent>(TEXT("myMesh")) //UStaticMeshComponent��ü�� "myMesh"��� �̸����� �������� ����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("myMesh"));

	SetRootComponent(Scene);//Scene�� Root Component�� �ø��ڴ�.
	//RootComponent=Scene; //Scene�� Root Component�� �ø��ڴ�. //���� ������ ó�����

	//AttachToComponent : Component ���̴� ���
	//Scene�� ���δ�, ���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ���
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent�� ���δ�, ���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ���
	//StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//UAsset ��������
	//ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	//<UStaticMesh> ã�� ���� Ÿ��
	//sm : ã�Ƽ� ���� ��ü �̸�
	//TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'")) ��ȣ �ȿ� ���� ����ƽ�޽ô� UE5���� �޽� ��Ŭ��-���۷��� ���� �ؼ� �����־��ش�.
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	//if (sm.Succeeded())//������ �ҷ����� ���� ���� Ȯ��
	//{
	//	StaticMesh->SetStaticMesh(sm.Object);//SetStaticMeshComponent�� StaticMesh ����
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
	Super::Tick(DeltaTime);//�������̵� �� �Լ��� ��� �θ� �Լ��� �����Ѵ�.
	IsMoveRight; //������ ����

	//LocX += 1;// ������ �̵�

	//LocX -= 1;//�������� �̵�
	//SetRelativeLocation : ������� ��ġ���� �����Ѵ�.
	//FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
	StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
	if (IsMoveRight == true)
	{
		LocX += 1;
		if (LocX >= 20)//float���� ũ��񱳸� �ϴ°� ����. ==�� ���� ������ �߻��� ���� ����
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

