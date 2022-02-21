#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent :
	public Component
{
public:
	MoveComponent(const char* name) : Component::Component(name) {};

	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	float getMaxSpeed() { return m_maxSpeed; }

	void update(float deltaTime) override;
private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
};

