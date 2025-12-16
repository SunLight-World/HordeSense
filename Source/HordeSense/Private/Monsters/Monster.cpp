// Fill out your copyright notice in the Description page of Project Settings.

#include "Monsters/Monster.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Engine.h"

AMonster::AMonster()
{
    // 确保角色可以移动和响应物理
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AMonster::TempMonsterDead()
{
	OnMonsterDead.ExecuteIfBound(this);
}
