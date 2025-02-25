// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerController.h"

void UMultiplayerController::HostGame()
{
	if (GetWorld())
	{
		GetWorld()->ServerTravel("/Game/HideAndSeek/Levels/DivineInspirationMap?listen");
	}
}

void UMultiplayerController::JoinGame(const FString& Address)
{
	if(APlayerController* PC = GetFirstLocalPlayerController())
	{
		PC->ClientTravel(Address, TRAVEL_Absolute);
	}
}