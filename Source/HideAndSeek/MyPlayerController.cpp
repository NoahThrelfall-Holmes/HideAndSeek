// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "EnhancedInputComponent.h"
#include "MultiplayerController.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast to EnhancedInputComponent
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (IA_HostGame)
		{
			// `ETriggerEvent::Triggered` fires **every frame** while the input is held
			// `ETriggerEvent::Started` Fires **once** when input first meets activation criteria
			// `ETriggerEvent::Completed` Fires **once when input is released** (useful for actions like charging attacks)
			EnhancedInput->BindAction(IA_HostGame, ETriggerEvent::Started, this, &AMyPlayerController::OnHostGame);
		}

		if (IA_JoinGame)
		{
			EnhancedInput->BindAction(IA_JoinGame, ETriggerEvent::Started, this, &AMyPlayerController::OnJoinGame);
		}
	}
}

void AMyPlayerController::OnHostGame()
{
	if(UMultiplayerController* GI = Cast<UMultiplayerController>(GetGameInstance()))
	{
		GI->HostGame();
	}
	
	UE_LOG(LogTemp, Log, TEXT("Host Game Pressed!"));
}

void AMyPlayerController::OnJoinGame()
{
	if(UMultiplayerController* GI = Cast<UMultiplayerController>(GetGameInstance()))
	{
		GI->JoinGame("127.0.0.1");
	}

	UE_LOG(LogTemp, Log, TEXT("Join Game Pressed!"));
}
