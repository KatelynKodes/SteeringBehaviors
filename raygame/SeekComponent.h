#pragma once
#include "Component.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

class SeekComponent :
	public Component
{
public:
	SeekComponent();
	SeekComponent(const char* name, Actor* target, float seekForce);

	void setMoveComponent(MoveComponent* component) { m_moveComponent = component; }

	void setDesiredVelocity();
	MathLibrary::Vector2 getDesiredVelocity() { return m_desiredVelocity; }
	void setSteeringForce();
	MathLibrary::Vector2 getSteeringForce() { return m_steeringForce; }

	void update(float deltaTime) override;
private:
	float m_seekForce;
	Actor* m_target;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MoveComponent* m_moveComponent;
};

