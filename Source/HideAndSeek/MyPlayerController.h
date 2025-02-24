// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HIDEANDSEEK_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_HostGame;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_JoinGame;
	
	void OnHostGame();
	void OnJoinGame();

protected:
	virtual void SetupInputComponent() override;
};
