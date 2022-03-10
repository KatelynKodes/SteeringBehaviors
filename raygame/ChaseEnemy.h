#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include "Transform2D.h"

class MoveComponent;
class SpriteComponent;
class SteeringComponent;

class ChaseEnemy :
	public Actor
{
public:
	ChaseEnemy(float x, float y) : Actor::Actor(x, y) {};

	void start() override;
	void update(float deltaTime) override;

	void onAddComponent(Component* component) override;

	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float value) { m_maxForce = value; }

private:
	float m_maxForce;
	MathLibrary::Vector2 m_force;
	MoveComponent* m_moveComponent;
	DynamicArray<SteeringComponent*> m_SteeringComponents;
};

