#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"
const int SCREEN_WIDTH;
const int SCREEN_HEIGHT;
const int MAP_WIDTH;
const int MAP_HEIGHT;
const int TILE_SIZE;
const int EXPLOSION_TIMER;


/*enum TileType
{
	FLOOR = 0,
	WALL = 1,
	DESTRUCTIBLE = 2,
	POWERUP = 3,
};

int gameMap[MAP_HEIGHT][MAP_WIDTH] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,2,0,0,0,0,0,0,2,0,0,0,1},
{1,0,1,0,1,2,1,0,1,2,1,0,1,0,1},
{1,2,0,0,0,0,0,0,0,0,0,0,0,2,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
{1,2,0,0,0,0,0,0,0,0,0,0,0,2,1},
{1,0,1,0,1,2,1,0,1,2,1,0,1,0,1},
{1,0,0,2,0,0,0,0,0,0,2,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};*/