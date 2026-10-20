#include "../include/game.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, game_title);
	SetTargetFPS(60);
	TextManipulation();
}

Game::~Game()
{
	UnloadFont(font);
	CloseWindow();
}

void Game::Run() {
	while (!WindowShouldClose()) {
		Update(GetFrameTime());
		Draw();
	}
}

void Game::Update(float dt)
{
	(void)dt;
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawTextEx(font, game_title, game_title_Pos, 32, 2, BLACK); // draw text in the canter of the screen 
	DrawFPS(screenWidth - 80 , 10);
	EndDrawing();
}

void Game::TextManipulation()
{
	font = LoadFontEx("../assets/fonts/spacex/SpaceX.ttf", 32, 0, 0);
	
	// title 
	game_title_Size = MeasureTextEx(font, game_title, 32, 2);
	game_title_Pos = {
		(screenWidth / 2) - (game_title_Size.x / 2),
		20
	};

}
