#include "player.h"
#include "constants.h"
#include "raylib.h"
#include "enemy.h"
#include "explosions.h"
#include <vector>

std::vector <Enemy> enemy;

void CreateEnemy()
{
	for (int i = 0; i < 3; i++)
	{
		Enemy e;
		e.gridX = GetRandomValue(1, MAP_WIDTH - 2);
		e.gridY = GetRandomValue(1, MAP_HEIGHT - 2);
		e.delay = 0;
		e.color = RED;
		enemy.push_back(e);
	}
}

void MoveAggresive(int e)
{
	enemy[e].delay++;

	if (enemy[e].delay < 60)
	{
		return;
	}
	int dx = 0;
	int dy = 0;

	if (enemy[e].gridX > GetPlayerGridX())
	{
		dx = -1;
	}
	else if (enemy[e].gridX < GetPlayerGridX())
	{
		dx = 1;
	}
	if (enemy[e].gridY > GetPlayerGridY())
	{
		dy = -1;
	}
	else if (enemy[e].gridY < GetPlayerGridY())
	{
		dy = 1;
	}
	int newX = enemy[e].gridX + dx;
	int newY = enemy[e].gridY + dy;
	if (isWalkable(newX, newY))
	{

		enemy[e].gridX = newX;
		enemy[e].gridY = newY;
	}

	enemy[e].delay = 0;
}
void MovePassiv(int e)
{
	enemy[e].delay++;

	if (enemy[e].delay < 60)
	{
		return;
	}
	int dx = 0;
	int dy = 0;

	if (enemy[e].gridX > GetPlayerGridX())
	{
		dx = 1;
	}
	else if (enemy[e].gridX < GetPlayerGridX())
	{
		dx = -1;
	}
	if (enemy[e].gridY > GetPlayerGridY())
	{
		dy = 1;
	}
	else if (enemy[e].gridY < GetPlayerGridY())
	{
		dy = -1;
	}
	int newX = enemy[e].gridX + dx;
	int newY = enemy[e].gridY + dy;
	if (isWalkable(newX, newY))
	{
		
		enemy[e].gridX = newX;
		enemy[e].gridY = newY;
	}

	enemy[e].delay = 0;
}
void MoveRandom(int e)
{
	// Delay-Zähler erhöhen (steuert, wann sich der Enemy bewegt)
	enemy[e].delay++;

	// Wenn noch keine 60 Frames vergangen sind, nichts machen
	if (enemy[e].delay < 60)
	{
		return;
	}
		

	// Zufällige Richtung erzeugen
	// 0 = rechts, 1 = links, 2 = unten, 3 = oben
	int dir = GetRandomValue(0, 3);

	// Variablen für Bewegungsrichtung
	int dx = 0;
	int dy = 0;

	// Richtung anhand der Zufallszahl festlegen
	if (dir == 0) dx = 1;        // rechts
	else if (dir == 1) dx = -1;  // links
	else if (dir == 2) dy = 1;   // unten
	else if (dir == 3) dy = -1;  // oben

	// Neue Zielposition berechnen
	int newX = enemy[e].gridX + dx;
	int newY = enemy[e].gridY + dy;

	// Prüfen, ob das Zielfeld begehbar ist
	if (isWalkable(newX, newY))
	{
		// Enemy auf das neue Feld bewegen
		enemy[e].gridX = newX;
		enemy[e].gridY = newY;
	}

	// Delay zurücksetzen, damit der Timer neu startet
	enemy[e].delay = 0;
}



void MoveEnemy()
{
	MoveRandom(2);
	MovePassiv(1);
	MoveAggresive(0);
}

void DrawEnemy()
{
	for (const Enemy& e : enemy)
	{
		DrawCircle(e.gridX * TILE_SIZE + TILE_SIZE / 2, e.gridY * TILE_SIZE + TILE_SIZE / 2, 20, e.color);
	}
}
void CheckIfEnemyExplodes()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		for (const Explosion& exp : explosions)
		{
			if (enemy[i].gridX == exp.gridX && enemy[i].gridY == exp.gridY)
			{
				enemy.erase(enemy.begin() + i);

				i--;											// Sonst überspringt man das näcshte Element
				break;											// Keine Weiteren Explusionen für diesen Enemy prüfen
			}
		}
	}
}

