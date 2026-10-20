#include "../include/physics.h"
#include <cmath>

const double G = 6.6743e-11;

double Distance(const Vec2d& a, const Vec2d& b) {
	const double distX = a.x - b.x;
	const double distY = a.y - b.y;

	return std::sqrt(distX * distX + distY * distY);
}

Vec2d CalculateGravityAcceleration(const Vec2d& objectPositon, const CelestialBody& sourceBody)
{
	const double distX = sourceBody.position.x - objectPositon.x;
	const double distY = sourceBody.position.y - objectPositon.y;
	const double distanceSquared = distX * distX + distY * distY;

	if (distanceSquared == 0.0) {
		return Vec2d{ 0.0, 0.0 };
	}

	const double distance = std::sqrt(distanceSquared);
	const double magnitude = (G * sourceBody.mass) / distanceSquared;

	return Vec2d{
		(distX / distance) * magnitude,
		(distY / distance) * magnitude
	};
}
