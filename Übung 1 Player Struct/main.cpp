#include <string>
#include <vector>
#include "raylib.h"
#include "player.h"
#include "constants.h"
#include "enemy.h"
#include "explosions.h"
#include "bomb.h"
#include "box.h"



int delay = 32;

struct Button 
{
	Rectangle rec;		//Rechteck
	Color color;		
};
enum GameState
{
	MENU,
	PLAYING,
	PAUSE,
	GAME_OVER
};
void DrawMap()
{
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			Color tileColor{};
			switch (Level1[x][y]) {
			case FLOOR:
				tileColor = LIGHTGRAY;
				break;
			case WALL:
				tileColor = DARKGRAY;
				break;
			case DESTRUCTIBLE:
				tileColor = BROWN;
				break;
			case POWERUP:
				tileColor = GOLD;
				break;
			}
			DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tileColor);
			DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
		}
	}
}



GameState currentstate = MENU;

Player player = InitPlayer(1, 1);


void CheckPlayerCollisions()
{
	for (const Enemy& e : enemy)
	{
		if (player.gridX == e.gridX && player.gridY == e.gridY)
		{
			player.currentLife--;
			player.gridX = 1;
			player.gridY = 1;
		}
	}
	for (const Explosion& e : explosions)
	{
		if (player.gridX == e.gridX && player.gridY == e.gridY)
		{
			player.currentLife--;
			player.gridX = - 1; // Spieler ist für eine Halbe Sekunde ausserhalb 
			player.gridY = - 1; // des Bildes, damit auch nur ein Leben abgezogen wird
			delay = 31;			// Delay wird auf 31 gesetzt um den Timer zu starten
		}
	}
	if (delay <= 31)			// Halbe Sekunde zählt runter
	{
		delay--;
	}
	if (delay == 0)				
	{
		player.gridX = 1;		//Player Spawnt am spawn 
		player.gridY = 1;
		delay = 32 ;			// Timer wird wieder zurückgesetzt
	}
	//DrawText(TextFormat("Delay: %d", delay), 100, 20, 20, BLACK);

}
void DrawGrid()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);

		}
	}
}

void ResetGame()
{
	boxes.clear();
	CreateBoxes();
}
void CheckLife()
{
	if (player.currentLife <= 0)
	{
		currentstate = GAME_OVER;
		ResetGame();
	}
}
void PlayerRespawn()
{
	CheckLife();
	
		player.currentLife--;
		player.gridX = 1;
		player.gridY = 1;
	


}


int main()
{
	InitWindow(MAP_WIDTH * TILE_SIZE, 50 + MAP_HEIGHT * TILE_SIZE , "Mein Spiel");
	SetTargetFPS(60);

	//ESC Butto weg binden um Pause auf ESC zu haben
	SetExitKey(KEY_NULL);

	// Kisten initialisieren

	CreateBoxes();
	CreateEnemy();

	
	//Inizialisiere Knöpfe in die Liste

	Button playButton{ SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2-150, 200, 50, BLUE };
	Button closeGame{ SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 , 200, 50, RED };
	Button ResetGame{ SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 , 200, 50, RED };


	

	

	while (!WindowShouldClose())
	{
		Vector2 mousePos = GetMousePosition();
		if (CheckCollisionPointRec(mousePos, playButton.rec)&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentstate == MENU)
		{
				currentstate = PLAYING;
		}
		if (CheckCollisionPointRec(mousePos, closeGame.rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentstate == MENU)
		{
			CloseWindow();
			return 0;
		}
		if (CheckCollisionPointRec(mousePos, ResetGame.rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && currentstate == GAME_OVER)
		{
			currentstate = PLAYING;
			player.currentLife = 3;
		}

		if (IsKeyPressed(KEY_ESCAPE) && currentstate == PLAYING) currentstate = PAUSE;
		else if (IsKeyPressed(KEY_ESCAPE) && currentstate == PAUSE) currentstate = PLAYING;

		
		MovePlayer(player);
		MoveEnemy();
		PlaceBomb(player.gridX,player.gridY);
		UpdateBomb();
		// Update - Kisten zerstören
		CheckIfBoxDestroyed();
		CheckPlayerCollisions();
		CheckIfEnemyExplodes();
		CheckLife();
		
		

		// ========DRAW========
		BeginDrawing();
		ClearBackground(WHITE);
		if (currentstate == MENU)
		{
			DrawRectangleRec(playButton.rec,playButton.color);
			DrawRectangleRec(closeGame.rec, closeGame.color);
			DrawText("MAIN MENU", 190, 70, 40, BLACK);
			DrawText("PLAY!", 270, 170, 20, WHITE);
			DrawLine(MAP_WIDTH *TILE_SIZE/2 , 0, MAP_WIDTH * TILE_SIZE / 2 , SCREEN_HEIGHT, BLACK);
		}

		if (currentstate == PLAYING)
		{
			DrawMap();
			//Draw Grid
			DrawGrid();
			//Draw Explosion
			DrawExplosion();
			//Draw Player
			DrawPlayer(player);
			//Draw Enemy
			DrawEnemy();
			//Draw Bomb
			DrawBomb();
			//Draw Boxes
			//DrawBoxes();
		}

		if (currentstate == PAUSE)
		{
			DrawText("Pause", 300, 300, 40, BLACK);
			DrawRectangle(350, 200, 20, 80, BLACK);
			DrawRectangle(380, 200, 20, 80, BLACK);
		}

		if (currentstate == GAME_OVER)
		{
			DrawRectangleRec(ResetGame.rec, ResetGame.color);
		}
		


		EndDrawing();


	}
	return 0;
}




