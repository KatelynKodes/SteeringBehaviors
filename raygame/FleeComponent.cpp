#include "FleeComponent.h"

FleeComponent::FleeComponent(Actor* chaser, float fleeForce, const char* name) : Component::Component(name)
{
	m_chaser = chaser;
	m_fleeForce = fleeForce;
}

void FleeComponent::setDesiredVelocity()
{
	m_desiredVelocity = (getOwner()->getTransform()->getLocalPosition() - m_chaser->getTransform()->getLocalPosition()).normalize() * m_fleeForce;
}

void FleeComponent::setSteeringForce()
{
	m_steeringForce = m_desiredVelocity - m_currVelocity;
}

void FleeComponent::update(float deltaTime)
{
	if (m_chaser)
	{
		setDesiredVelocity();
		setSteeringForce();

		m_currVelocity = m_currVelocity + (getSteeringForce() * deltaTime);
		m_movecomponent->setVelocity(m_currVelocity * deltaTime);
	}
}
