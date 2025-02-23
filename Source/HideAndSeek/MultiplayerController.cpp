// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerController.h"

void UMultiplayerController::HostGame()
{
	GetWorld()->ServerTravel("/Game/Maps/YourMap?listen");
}

void UMultiplayerController::JoinGame(const FString& Address)
{
	if(APlayerController* PC = GetFirstLocalPlayerController())
	{
		PC->ClientTravel(Address, TRAVEL_Absolute);
	}
}