// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "EnhancedInputComponent.h"

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
	//if(GetWorld())
	//{
	//	GetWorld()->ServerTravel("/Game/HideAndSeek/Levels/DivineInspirationMap?listen");
	//}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Host Game Pressed!"));
	}
}

void AMyPlayerController::OnJoinGame()
{
	//ClientTravel("127.0.0.1", TRAVEL_Absolute);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Join Game Pressed!"));
	}
}
