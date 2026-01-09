#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include <vector>
// Struct Definition

struct Enemy
{
	int gridX;
	int gridY;
	int delay;
	Color color;
};

extern std::vector<Enemy> enemy; //CHATGBT LÖSUNG ADRIAN FRAGEN

// Funktions-Deklarationen (nur die Signaturen!)

void CreateEnemy();
void MoveEnemy();
void MoveAggresive(int e);
void MovePassiv(int e);
void MoveRandom(int e);
void DrawEnemy();
void CheckIfEnemyExplodes();
#endif

