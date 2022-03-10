#pragma once
#include "Transform2D.h"
#include "SteeringComponent.h"

class WanderComponent :
	public SteeringComponent
{
public:
	WanderComponent(float wanderRadius, float circleOffset, float wanderForce);

	MathLibrary :: Vector2 calculateForce()override;

private:
	float m_wanderRadius = 0;
	float m_circleDistance = 0;
	float m_wanderAngle = 0;
	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePos;
};

