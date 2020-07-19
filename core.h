#pragma once
#include <vector>
#include <string>
#include "sprites.h"


#define EMPTY ' '

#define PLAYER_HBARS 3
#define PLAYER_FIRERATE 2

#define ENEMY_POS_Y 5
#define ENEMY_FIRERATE 25

#define UBULLET 1
#define DBULLET -1
#define UBULLET_CHAR '^'
#define DBULLET_CHAR 'o'
#define UBULLET_OFFSET 0
#define DBULLET_OFFSET 1

#define HBAR_CHAR '|'


struct Vector2 {
	int x;
	int y;
};

typedef std::vector<std::string> sprite_cont;