// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FMonsterDead, AMonster*, InMonster);

UCLASS()
class HORDESENSE_API AMonster : public ACharacter
{
    GENERATED_BODY()

public:
    AMonster();

protected:
    void TempMonsterDead();
public:
    // 配合对象池的销毁代理
    FMonsterDead OnMonsterDead;
};