#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include <vector>

std::vector <Explosion> explosions;

void CreateExplosion(int centerX, int centerY, int range)
{
	for (int dir = 0;dir < 4;dir++)
	{
		for (int dist = 0;dist <= range;dist++)
		{
			int expX = centerX;
			int expY = centerY;

			if (dir == 0)
			{
				expX += dist; // Rechts
			}
			if (dir == 1)
			{
				expX -= dist; // Links
			}
			if (dir == 2)
			{
				expY += dist; // Unten
			}
			if (dir == 3)
			{
				expY -= dist; // Oben
			}
			if (expX >= 0 && expX < MAP_WIDTH && expY >= 0 && expY < MAP_HEIGHT)
			{
				Explosion e;
				e.gridX = expX;
				e.gridY = expY;
				e.timer = EXPLOSION_TIMER;
				explosions.push_back(e);
			}
		}
	}
}
void DrawExplosion()
{
	for (const Explosion& e : explosions) {
				Color expColor = ORANGE;
				expColor.a = (unsigned char)((e.timer * 255) / EXPLOSION_TIMER); //Transparents mit der Zeit
				DrawRectangle(e.gridX * TILE_SIZE + 5, e.gridY * TILE_SIZE + 5, TILE_SIZE - 10, TILE_SIZE - 10, expColor);

			}
}