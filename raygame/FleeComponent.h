#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"

class FleeComponent :
	public Component
{
public:
	FleeComponent(Actor* chaser, float fleeForce, const char* name = "Flee Component");

	void setMoveComponent(MoveComponent* component) { m_movecomponent = component; }

	void setDesiredVelocity();
	MathLibrary::Vector2 getDesiredVelocity() { return m_desiredVelocity; }

	void setSteeringForce();
	MathLibrary::Vector2 getSteeringForce() { return m_steeringForce; }

	void update(float deltaTime) override;

private:
	Actor* m_chaser;
	float m_fleeForce;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MoveComponent* m_movecomponent;
};

