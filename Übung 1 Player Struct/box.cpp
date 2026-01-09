#include <vector>
#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"
#include "box.h"

std::vector <Box> boxes;

void CreateBoxes()
{
	for (int i = 0; i < 15; i++)
	{
		Box b;
		b.gridX = GetRandomValue(1, MAP_WIDTH - 2);
		b.gridY = GetRandomValue(1, MAP_HEIGHT - 2);
		boxes.push_back(b);
	}
}

void CheckIfBoxDestroyed()
{
	for (int i = 0; i < boxes.size(); i++) {
		for (const Explosion& exp : explosions) {
			if (boxes[i].gridX == exp.gridX && boxes[i].gridY ==
				exp.gridY) {
				boxes.erase(boxes.begin() + i);
				i--;
				break;
			}
		}
	}
}

void DrawBoxes()
{
	for (const Box& box : boxes)
	{
		DrawRectangle(box.gridX * TILE_SIZE, box.gridY * TILE_SIZE, TILE_SIZE, TILE_SIZE, BROWN);
	}
}
