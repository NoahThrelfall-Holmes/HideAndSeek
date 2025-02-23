// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAction("HostGame", IE_Pressed, this, &AMyPlayerController::OnHostGame);
	//InputComponent->BindAction("JoinGame", IE_Pressed, this, &AMyPlayerController::OnJoinGame);
}

void AMyPlayerController::OnHostGame()
{
	if(GetWorld())
	{
		GetWorld()->ServerTravel("/Game/HideAndSeek/Levels/DivineInspirationMap?listen");
	}
}

void AMyPlayerController::OnJoinGame()
{
	ClientTravel("127.0.0.1", TRAVEL_Absolute);
}
