#include "../include/camera.h"

Vector2 WorldToScreen(const Vec2d& worldPosition, const GameCamera& camera, int screenWidth, int screenHeight)
{
	const double relativeX = worldPosition.x - camera.target.x;
	const double relativeY = worldPosition.y - camera.target.y;
	
	const double screenX = (screenWidth / 2.0) + relativeX * camera.pixelsPerMeter;
	const double screenY = (screenHeight / 2.0) - relativeY * camera.pixelsPerMeter;
	
	return Vector2{
		static_cast<float>(screenX),
		static_cast<float>(screenY)
	};

}
