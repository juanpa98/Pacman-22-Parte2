#include "Enemy.h"
#include "TimeManager.h"
#include "Map.h"


Enemy::Enemy()
{
	spawn = { 0,0 };
	position = spawn;
	direction = { 0,0 };
}

Enemy::Enemy(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn;
	direction = { 0,0 };
}


Enemy::ENEMY_STATE Enemy::Logic(Map* pacman_map, COORD playerPosition)
{
	

	int dir = rand() % 4;
	COORD position_new = position;

	switch (dir)
	{
	case 0:
		position_new.X++;
		break;
	case 1:
		position_new.X--;
		break;
	case 2:
		position_new.Y++;
		break;
	case 3:
		position_new.Y--;
		break;

	default:
		break;
	}
	//Este es el teleporter
	if (position_new.X < 0)
	{
		position_new.X = pacman_map->Width - 1;
	}
	position_new.X %= pacman_map->Width;
	if (position_new.X < 0)
	{
		position_new.X = pacman_map->Height - 1;
	}
	position_new.X %= pacman_map->Height;
	switch (pacman_map->GetTile(position_new.X, position_new.Y))
	{
		case Map::MAP_TILES::MAP_WALL:
		position_new = position;
		break;
	}

	position = position_new;
	
	
	ENEMY_STATE state = ENEMY_STATE::ENEMY_NONE;
	if (position.X == playerPosition.X && position.Y == playerPosition.Y) 
	{
		if (powerup_countdown <= TimeManager::getInstance().time) 
		{
			 
			state = ENEMY_STATE::ENEMY_DEAD;
			
	
		}
		else {

			position = spawn;
			state = ENEMY_STATE::ENEMY_KILLED;
			
		
	

		}
	}
	if (powerup_countdown <= TimeManager::getInstance().time)
	{
		foreground=foreground_attack;
	}
	else {
		foreground = foreground_powerUp;
	}
	return state;
		
	



}

void Enemy::Draw()
{
	//pintar posicion, color y caracter
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void Enemy::PowerUpPicked()
{
	powerup_countdown = TimeManager::getInstance().time + powerup_coiuntdown_time;
}
