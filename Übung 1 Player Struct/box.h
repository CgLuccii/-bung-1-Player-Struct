#ifndef BOX_H
#define BOX_H
#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"
// Struct Definition

struct Box
{
	int gridX, gridY;
};

extern std::vector<Box> boxes; 

// Funktions-Deklarationen (nur die Signaturen!)
void CreateBoxes();
void CheckIfBoxDestroyed();
void DrawBoxes();


#endif#

