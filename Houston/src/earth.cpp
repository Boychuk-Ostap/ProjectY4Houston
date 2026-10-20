#include "../include/earth.h"

CelestialBody CreateEarth()
{
	CelestialBody earth{};
	earth.position = { 0.0, 0.0 }; // metres
	earth.velocity = { 0.0, 0.0 }; // m/s but stays zero
	earth.mass = 5.972e24; // kg
	earth.radius = 6371000.0; // metres
	return earth;
}

double AltitudeAboveEarth(const Vec2d& objectPosition, const CelestialBody& earth)
{
	return Distance(objectPosition, earth.position) - earth.radius;
}
