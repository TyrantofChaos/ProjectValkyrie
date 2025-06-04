// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectValkyrie.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, ProjectValkyrie, "ProjectValkyrie" );

DEFINE_LOG_CATEGORY(Game);		 	// For General Game Logs   		
DEFINE_LOG_CATEGORY(PlayerLog);    	// For Player Specific Logs
DEFINE_LOG_CATEGORY(CharacterLog); 	// For Character Level Logs
DEFINE_LOG_CATEGORY(EnemyLog);     	// For Enemy Specific Logs 
DEFINE_LOG_CATEGORY(GameModeLog);  	// For Game Mode Logs      
DEFINE_LOG_CATEGORY(SpawnLog);     	// For Spawn Errors        