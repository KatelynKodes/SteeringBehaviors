#include "SeekComponent.h"
#include "Transform2D.h"

SeekComponent::SeekComponent(Actor* target, float seekForce, const char* name) : Component::Component(name)
{
	m_target = target;
	m_seekForce = seekForce;
}

void SeekComponent::setDesiredVelocity()
{
	m_desiredVelocity = (m_target->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition()).normalize() * m_seekForce;
}

void SeekComponent::setSteeringForce()
{
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
}

void SeekComponent::update(float deltaTime)
{
	if (m_target != nullptr)
	{
		setDesiredVelocity();
		setSteeringForce();

		m_currentVelocity = m_currentVelocity + (getSteeringForce() * deltaTime);

		m_moveComponent->setVelocity(m_currentVelocity * deltaTime);
	}
}
