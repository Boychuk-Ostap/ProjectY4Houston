#include "../include/game.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, game_title);
	SetTargetFPS(60);
	TextManipulation();

	earth = CreateEarth();

	camera.target = earth.position;
	camera.pixelsPerMeter = 7.0e-5;
	camera.rotation = 0.0f;
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

	DrawEarth();
	DrawHub();

	// top 
	DrawTextEx(font, game_title, game_title_Pos, 32, 2, BLACK); // draw text in the canter of the screen 
	DrawFPS(screenWidth - 80 , 10);
	
	EndDrawing();
}

void Game::DrawEarth()
{
	const Vector2 screenPos = WorldToScreen(earth.position, camera, static_cast<int>(screenWidth), static_cast<int>(screenHeight));

	double screenRadius = earth.radius * camera.pixelsPerMeter;
	if (screenRadius < 4.0) {
		screenRadius = 4.0; // minimum visible marker
	}

	const Color earthColor = { 0, 140, 180, 255 }; // blue-green
	DrawCircleV(screenPos, static_cast<float>(screenRadius), earthColor);
}

void Game::DrawHub()
{
	const double metresPerPixel = 1.0 / camera.pixelsPerMeter;
	int x = 10;
	int y = 20;

	const int line = 20;

	DrawTextEx(font, TextFormat("Earth position: (%.1f, %.1f) m", earth.position.x, earth.position.y),
		Vector2{ (float)x, (float)y}, 25, 1, BLACK);
	y += line;
	DrawTextEx(font, TextFormat("Earth radius: %.0f m", earth.radius),
		Vector2{ (float)x, (float)y }, 25, 1, BLACK);
	y += line;
	DrawTextEx(font, TextFormat("Earth mass: %.3e kg", earth.mass),
		Vector2{ (float)x, (float)y }, 25, 1, BLACK);
	y += line;
	DrawTextEx(font, TextFormat("Camera scale: 1 pixel = %.0f metres", metresPerPixel),
		Vector2{ (float)x, (float)y }, 25, 1, BLACK);
	y += line;
	DrawTextEx(font, TextFormat("Camera mode: %s", cameraMode),
		Vector2{ (float)x, (float)y }, 25, 1, BLACK);
}

void Game::TextManipulation()
{
	font = LoadFontEx("../assets/fonts/spacex/SpaceX.ttf", 64, 0, 0);
	
	// title 
	game_title_Size = MeasureTextEx(font, game_title, 32, 2);
	game_title_Pos = {
		(screenWidth / 2) - (game_title_Size.x / 2),
		20
	};

}
