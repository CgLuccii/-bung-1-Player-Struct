#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "raylib.h"
#include <vector>
// Struct Definition
struct Explosion
{
	int gridX, gridY;	//Grid-Position
	int timer;			// Wie lange sichtbar
};

extern std::vector<Explosion> explosions; 

// Funktions-Deklarationen (nur die Signaturen!)
void CreateExplosion(int centerX, int centerY, int range);
void DrawExplosion();


#endif#

