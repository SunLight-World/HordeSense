// Fill out your copyright notice in the Description page of Project Settings.


#include "Monsters/HordeManager.h"

#include "Kismet/GameplayStatics.h"
#include "Monsters/Monster.h"


// Sets default values
AHordeManager::AHordeManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHordeManager::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHordeManager::TestCreate, 2.f, true);
}

// Called every frame
void AHordeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 从对象池中获取对象
AMonster* AHordeManager::GetMonster()
{
	AMonster* Monster = nullptr;

	// 如果对象池中有元素，就取出来最后一个元素并移除出对象池
	if (MonstersArr.Num() > 0)
	{
		Monster = MonstersArr.Last();
		MonstersArr.Pop();
	}
	// 如果一个都没有，说明对象池被用完了，需要生成一个对象(没有在此处加入到对象池，新生成的这个对象加入对象池的时机是它销毁时)
	// 场景中怪物对象的数量会因为此处不断增加，直到"销毁时的增加"后的数量 >= "获取时的移除"后的数量
	else
	{
		if (MonsterClass)
		{
			Monster = GetWorld()->SpawnActor<AMonster>(MonsterClass, MonsterInitLocation, MonsterInitRotation);
			Monster->OnMonsterDead.BindDynamic(this, &AHordeManager::OnDestroyMonster);
			UE_LOG(LogTemp, Warning, TEXT("类加载成功"))
		}
	}

	return Monster;
}


void AHordeManager::OnDestroyMonster(AMonster* Monster)
{
	// 后续补齐怪物状态改变
	// 。。。

	// 添加到对象池
	MonstersArr.Add(Monster);
}

void AHordeManager::CreateMonsters()
{
	AMonster* Monster = GetMonster();

	FVector CreateLocation = FVector::ZeroVector;
	APawn* Pawn = Cast<APawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (IsValid(Pawn) && IsValid(Monster))
	{
		FVector BaseLocation = Pawn->GetActorLocation();
		FVector RandomDistance = FVector(FMath::RandRange(-100,100), FMath::RandRange(-100, 100), 0);
		Monster->SetActorLocation(BaseLocation + RandomDistance);
	}
}

void AHordeManager::TestCreate()
{
	CreateMonsters();
}
