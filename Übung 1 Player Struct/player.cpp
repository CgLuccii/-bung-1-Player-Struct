#include "player.h"
#include "constants.h"
#include "raylib.h"

extern Player player;

Player InitPlayer(int startX, int startY) 
{
	Player p;
	p.gridX = startX;
	p.gridY = startY;
	p.currentLife = 3;
	p.color = BLUE;
	return p;
}

void MovePlayer(Player& player)
{
	if (IsKeyPressed(KEY_W) && isWalkable(player.gridX + 0, player.gridY - 1) == true)
	{
		player.gridY--;
	}
	if (IsKeyPressed(KEY_S) && isWalkable(player.gridX + 0, player.gridY + 1) == true)
	{
		player.gridY++;
	}

	if (IsKeyPressed(KEY_A) && isWalkable(player.gridX - 1, player.gridY + 0) == true)
	{
		player.gridX--;
	}
	if (IsKeyPressed(KEY_D) && isWalkable(player.gridX + 1, player.gridY + 0) == true)
	{
		player.gridX++;
	}
}

int checkTile(int TargetGridX, int TargetGridY)
{
	switch (Level1[TargetGridX][TargetGridY])
	{

	case FLOOR:        return 0;
	case WALL:         return 1;
	case DESTRUCTIBLE: return 2;
	case POWERUP:	   return 3;
	default:		   return 4;
	}
}


bool isWalkable(int TargetGridX, int TargetGridY)
{
	if (checkTile(TargetGridX, TargetGridY) == 1|| checkTile(TargetGridX, TargetGridY) == 2)
	{
		return false;
	}
	return true;
}


void DrawPlayer(Player& player)
{
	DrawCircle(player.gridX * TILE_SIZE + TILE_SIZE / 2, player.gridY * TILE_SIZE + TILE_SIZE / 2, 20, player.color);
	DrawText(TextFormat("Life: %d", player.currentLife), 20, 20, 20, BLACK);

}
int GetPlayerGridX()
{
	return player.gridX;
}
int GetPlayerGridY()
{
	return player.gridY;
}

