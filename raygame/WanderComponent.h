#pragma once
#include "Component.h"
#include "MoveComponent.h"

class Transform2D;
class SeekComponent;

class WanderComponent :
	public Component
{
public:
	WanderComponent(float wanderRadius, const char* name = "WanderComponent");
	WanderComponent(const char* name = "WanderComponent");

	MathLibrary::Vector2 getIntendedDirection();

	void update(float deltaTime) override;
private:
	float m_wanderRadius;
	float m_wanderDistance;
	MathLibrary::Vector2 m_intendedDirection;
	SeekComponent* m_seekComponent;
};

