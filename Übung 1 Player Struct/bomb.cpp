#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"


std::vector <Bomb> bombs;

void PlaceBomb(int playerX, int playerY)
{
	if (IsKeyPressed(KEY_SPACE) && bombs.size() <= 2)
	{
		Bomb b;
		b.gridX = playerX;
		b.gridY = playerY;
		b.timer = 180;
		b.range = 2;
		bombs.push_back(b);
	}
}
void UpdateBomb()
{
	for (int i = 0; i < bombs.size(); i++)
	{
		bombs[i].timer--;

		if (bombs[i].timer <= 0)
		{
			// hier später Explosion
			CreateExplosion(bombs[i].gridX, bombs[i].gridY, bombs[i].range);
			bombs.erase(bombs.begin() + i);
			i--;
			//break;
		}
	}
	for (int i = 0; i < explosions.size(); i++)
	{
		explosions[i].timer--;
		if (explosions[i].timer <= 0)
		{
			explosions.erase(explosions.begin() + i);
			i--;
		}
	}
}
void DrawBomb()
{
	for (const Bomb& b : bombs)
	{
		Color bombColor = (b.timer < 60) ? RED : BLACK;
		DrawCircle(b.gridX * TILE_SIZE + TILE_SIZE / 2, b.gridY * TILE_SIZE + TILE_SIZE / 2, 20, bombColor);
		DrawText(TextFormat("%.1f", b.timer / 60.0f),
			b.gridX * TILE_SIZE + TILE_SIZE / 2 - 10,
			b.gridY * TILE_SIZE + TILE_SIZE / 2 - 8, 16, WHITE);
	}
}