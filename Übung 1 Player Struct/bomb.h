#ifndef BOMB_H
#define BOMB_H
#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"
// Struct Definition
struct Bomb
{
	int gridX, gridY;	// Grid-Position
	int timer;			// Frames bis Explosion
	int range;			// Explusionsreichweite
};

extern std::vector<Bomb> bombs; 

// Funktions-Deklarationen (nur die Signaturen!)
void PlaceBomb(int playerX, int playerY);
void UpdateBomb();
void DrawBomb();


#endif#

