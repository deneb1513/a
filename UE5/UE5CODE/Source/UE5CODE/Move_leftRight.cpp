// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_leftRight.h"
#include"Switch.h"

// Sets default values
AMove_leftRight::AMove_leftRight() :m_LocX(0), m_IsMoveRight(true), m_Isplay(false)
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
	
	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &AMove_leftRight::EventOverlap);
}

// Called every frame
void AMove_leftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//�������̵� �� �Լ��� ��� �θ� �Լ��� �����Ѵ�.
	if (m_Isplay == false)
		return;

	//LocX += 1;// ������ �̵�

	//LocX -= 1;//�������� �̵�
	//SetRelativeLocation : ������� ��ġ���� �����Ѵ�.
	//FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
	StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
	if (m_IsMoveRight == true)
	{
		m_LocX += 1;
		if (m_LocX >= 20)//float���� ũ��񱳸� �ϴ°� ����. ==�� ���� ������ �߻��� ���� ����
		{
			m_IsMoveRight = false;
		}
	}
	else if (m_IsMoveRight == false)
	{
		m_LocX -= 1;
		if (m_LocX <= -20)
		{
			m_IsMoveRight = true;
		}
	}
}

void AMove_leftRight::EventOverlap(bool isBegin)
{
	m_Isplay = isBegin;
}

void AMove_leftRight::Code_DoPlay_Implementation(bool IsPlay)
{
	m_Isplay = IsPlay;
}



