// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HordeManager.generated.h"

class AMonster;

UCLASS()
class HORDESENSE_API AHordeManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHordeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// 获取怪物对象
	AMonster* GetMonster();
	// 怪物死亡时回调
	UFUNCTION()
	void OnDestroyMonster(AMonster* Monster);

	// 生成怪物
	void CreateMonsters();

	// 测试生成逻辑，定时器指定
	UFUNCTION()
	void TestCreate();

protected:
	// 怪物对象池
	UPROPERTY()
	TArray<AMonster*> MonstersArr;
	// 怪物默认位置
	UPROPERTY(EditAnywhere)
	FVector MonsterInitLocation;
	// 怪物默认旋转
	UPROPERTY(EditAnywhere)
	FRotator MonsterInitRotation;
	// 怪物对象类型
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMonster> MonsterClass;
};
