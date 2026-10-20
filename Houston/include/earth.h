#pragma once
#include "physics.h"

CelestialBody CreateEarth();

double AltitudeAboveEarth(
	const Vec2d& objectPosition,
	const CelestialBody& earth
);