#pragma once
#include "raylib.h"
#include "earth.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	Font font;
	Vector2 game_title_Size;
	Vector2 game_title_Pos;
private:

	void Update(float dt);
	void Draw();
	void TextManipulation();

	float screenWidth = 1920;
	float screenHeight = 1080;

	const char* game_title = "Houston, We Have a Problem";
};
