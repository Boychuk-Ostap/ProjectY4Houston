#pragma once
#include "raylib.h"
#include "physics.h"

struct GameCamera
{
	Vec2d target; // what we look at
	double pixelsPerMeter; // zoom 
	float rotation; 
};

Vector2 WorldToScreen(
	const Vec2d& worldPosition,
	const GameCamera& camera,
	int screenWidth,
	int screenHeight
);