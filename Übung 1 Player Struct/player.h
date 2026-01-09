#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "constants.h"

// Struct Definition
struct Player
{
	int gridX;
	int gridY;
	int currentLife;
	Color color;
};

// Funktions-Deklarationen (nur die Signaturen!)
Player InitPlayer(int startX, int startY);
//void UpdatePlayer(Player& player);
//void DrawPlayer(const Player& player, int tileSize);
void MovePlayer(Player& player);
void DrawPlayer(Player& player);
int checkTile(int gridX, int gridY);
bool isWalkable(int TargetGridX, int TargetGridY);
int GetPlayerGridX();
int GetPlayerGridY();
#endif
