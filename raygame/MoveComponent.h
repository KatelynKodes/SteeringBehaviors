#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent :
	public Component
{
public:
	MoveComponent(const char* name = "MovementComponent") : Component::Component(name) {};

	MathLibrary::Vector2 getVelocity() { return m_velocity; };
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; };

	float getMaxSpeed() { return m_maxSpeed; }
	void setMaxSpeed(float speed) { m_maxSpeed = speed; }


	void update(float deltaTime) override;
private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
};

