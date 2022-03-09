#pragma once
#include "Component.h"

enum State
{
	IDLE,
	WANDER,
	SEEK
};

class SeekComponent;
class WanderComponent;

class StateMachineComponent :
	public Component
{
public:
	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void update(float deltaTime)override;
	void start() override;

private:
	State m_currentState;
	SeekComponent* m_seekComponent = nullptr;
	WanderComponent* m_wanderComponent = nullptr;
	float m_seekForce = 0;
	float m_wanderForce = 0;
	float m_seekRange = 0;
};

