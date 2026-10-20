#pragma once

struct Vec2d {
	double x;
	double y;
};

struct CelestialBody {
	Vec2d position;
	Vec2d velocity;
	double mass;
	double radius;
};

extern const double G;

double Distance(const Vec2d& a, const Vec2d& b);

Vec2d CalculateGravityAcceleration(
	const Vec2d& objectPositon, // pilled thing pos (moon)
	const CelestialBody& sourceBody // what pull the moon (earth)
);