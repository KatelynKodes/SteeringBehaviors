#pragma once
#include "Component.h"
class SteeringComponent :
	public Component
{
public:
	SteeringComponent() { m_target = nullptr; m_steeringForce = 0; }
	SteeringComponent(Actor* target, float steeringForce);
private:
	float m_steeringForce =0;
	Actor* m_target = nullptr;
};

