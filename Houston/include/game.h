#pragma once
#include "raylib.h"
#include "earth.h"
#include "camera.h"


class Game
{
public:
	Game();
	~Game();

	void Run();

	CelestialBody earth{};

	GameCamera camera{};
	const char* cameraMode = "Fixed on Earth";

	Font font;
	Vector2 game_title_Size;
	Vector2 game_title_Pos;
private:

	void Update(float dt);
	
	void Draw();
	void DrawEarth();
	void DrawHub();

	void TextManipulation();

	float screenWidth = 1920;
	float screenHeight = 1080;

	const char* game_title = "Houston, We Have a Problem";
};
