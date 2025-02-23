// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MultiplayerController.generated.h"

/**
 * 
 */
UCLASS()
class HIDEANDSEEK_API UMultiplayerController : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec) // noah here - research Exec keyword in this context
	void HostGame();

	UFUNCTION(Exec)
	void JoinGame(const FString& Address);
};
