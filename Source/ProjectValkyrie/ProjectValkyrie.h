// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
/*
�	Fatal
�	Error
�	Warning
�	Display
�	Log
�	Verbose
�	VeryVerbose
*/

DECLARE_LOG_CATEGORY_EXTERN(Game, Log, All);			// For General Game Logs
DECLARE_LOG_CATEGORY_EXTERN(PlayerLog, Log, All);		// For Player Specific Logs
DECLARE_LOG_CATEGORY_EXTERN(CharacterLog, Log, All);	// For Character Level Logs
DECLARE_LOG_CATEGORY_EXTERN(EnemyLog, Log, All);		// For Enemy Specific Logs
DECLARE_LOG_CATEGORY_EXTERN(GameModeLog, Log, All);		// For Game Mode Logs
DECLARE_LOG_CATEGORY_EXTERN(SpawnLog, Log, All);		// For Spawn Errors
