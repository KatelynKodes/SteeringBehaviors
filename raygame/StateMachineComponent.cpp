#include "StateMachineComponent.h"
#include "Actor.h"
#include "SteeringComponent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"

void StateMachineComponent::start()
{
	Component::start();

	//Get seek component
	m_seekComponent = getOwner()->getComponent<SeekComponent>();
	m_seekForce = m_seekComponent->getSteeringForce(); //Get the steering force

	//GetWander component
	m_wanderComponent = getOwner()->getComponent<WanderComponent>();
	m_wanderForce = m_wanderComponent->getSteeringForce(); //get the wanderforce
	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distFromTarget < m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		//m_seekComponent.setSteeringForce(0);
		//m_wanderComponent.setSteeringForce(0);
	case WANDER:
		//m_seekComponent.setSteeringForce(0);
		//m_wanderComponent.setSteeringForce(0);

		if (targetInRange)
		{
			setCurrentState(SEEK);
		}
	case SEEK:
		if (!targetInRange)
		{
			setCurrentState(WANDER);
		}
	default:
		break;
	}
}

