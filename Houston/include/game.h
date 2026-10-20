#pragma once
#include "raylib.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	Font font;
	Vector2 game_title_Size;
private:

	void Update(float dt);
	void Draw();

	float screenWidth = 1920;
	float screenHeight = 1080;

	const char* game_title = "Houston, We Have a Problem";
};