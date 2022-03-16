#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

void Agent::start()
{
	Actor::start();

	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(500);
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Get all the forces in the steering components
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//clamp force if need be
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);
	if (steeringComponent)
		m_steeringComponents.addItem(steeringComponent);
}
