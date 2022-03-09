#pragma once
#include "Transform2D.h"
#include "SeekComponent.h"

class WanderComponent :
	public SeekComponent
{
public:
	WanderComponent(float wanderRadius, float circleOffset, float wanderForce, const char* name = "WanderComponent");
	WanderComponent(const char* name = "WanderComponent");

	MathLibrary :: Vector2 setSteeringForce()override;

	void update(float deltaTime) override;

private:
	float m_wanderRadius = 0;
	float m_circleDistance = 0;
	float m_wanderAngle = 0;
	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePos;
};

