// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/MainGameMode.h"
#include "Gameplay/MainHUD.h"

AMainGameMode::AMainGameMode()
{
	// Set Default HUD Class
	HUDClass = AMainHUD::StaticClass();
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}