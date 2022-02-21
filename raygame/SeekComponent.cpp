#include "SeekComponent.h"

SeekComponent::SeekComponent()
{
	m_target = nullptr;
	m_seekForce = 0;
}

SeekComponent::SeekComponent(const char* name, Actor* target, float seekForce) : Component::Component(name)
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
		
	}
}
