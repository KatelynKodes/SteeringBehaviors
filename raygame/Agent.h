#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>

class SteeringComponent;
class MoveComponent;

class Agent :
	public Actor
{
public:
	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float value) { m_maxForce = value; }
	MoveComponent* getMoveComponent() { return m_moveComponent; }

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_force;
};

