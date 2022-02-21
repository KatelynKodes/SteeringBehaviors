#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "Actor.h"

class SeekComponent :
	public Component
{
public:
	SeekComponent();
	SeekComponent(const char* name, Actor* target);

	void setDesiredVelocity(float speed);
	void setSteeringForce();

	void update(float deltaTime) override;
private:
	Actor* m_target;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
};

