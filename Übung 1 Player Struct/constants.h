#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int MAP_WIDTH = 18;
const int MAP_HEIGHT = 15;
const int TILE_SIZE = 64;
const int EXPLOSION_TIMER = 30;



enum TileType
{
	FLOOR = 0,
	WALL = 1,
	DESTRUCTIBLE = 2,
	POWERUP = 3,
};
const int Level1[MAP_WIDTH][MAP_HEIGHT] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,2,0,0,0,0,2,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,2,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,2,0,0,0,0,2,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,2,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

#endif