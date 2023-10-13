// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"//������ �ӵ��� ������ �ϱ����� �⺻���� �ּ����� ���̺귯���� ������ ���
#include "GameFramework/Actor.h"//AActor Ŭ���� ��� ����

//*generated.h �𸮾� Ŭ���� ���� ó���ϴ� ���-�𸮾� Ŭ���� ���� �⺻ ��Ģ
//��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ� �ڵ带 �־���� �Ѵ�.
//�ݵ�� ��� #include �������� ��ġ
#include "Move_leftRight.generated.h"



UCLASS()// �𸮾� Ŭ���� ����
//UE5CODE_API: �� Ŭ������ UE5CODE_API ��⿡ ���Եȴ�.
class UE5CODE_API AMove_leftRight : public AActor// public AActor : AActor�� ����� ��� �ްڴ�.
{
	GENERATED_BODY()//�𸮾� �ڵ� ���� �Լ�-�𸮾� Ŭ���� ���� �⺻ ��Ģ
	

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
	//UPROPERTY(EditeAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;//������Ʈ�ǿ��� ��Ʈ������Ʈ �κ�


	UPROPERTY(visibleAnywhere, BlueprintReadWrite)//�׻� ���� ���� �������� �ۼ�. 
	UStaticMeshComponent* StaticMesh;//������Ʈ�ǿ��� ����ƽ�޽úκ�

	float LocX;
	bool IsMoveRight;
	bool Isplay;
};
