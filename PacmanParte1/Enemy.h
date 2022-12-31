#pragma once
#include <stdlib.h>
#include <time.h>
#include "Map.h"


class Enemy
{
public:
	COORD spawn;
	COORD position;
	COORD direction;

private:
	float powerup_countdown = 0;
	char character = 'E';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
	
	ConsoleUtils::CONSOLE_COLOR foreground_attack = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR foreground_powerUp = ConsoleUtils::CONSOLE_COLOR::CYAN;


	const float powerup_coiuntdown_time = 15;

public:
	enum ENEMY_STATE { ENEMY_NONE, ENEMY_KILLED, ENEMY_DEAD };
	Enemy(COORD _spawn);
	Enemy();
	// una booleana que me diga si he colisionado con el jugador
	ENEMY_STATE Logic(Map* pacman_map, COORD playerPosition);
	void Draw();
	void PowerUpPicked();

};