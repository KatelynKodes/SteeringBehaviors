#include "SeekComponent.h"

SeekComponent::SeekComponent()
{
	m_target = nullptr;
}

SeekComponent::SeekComponent(const char* name, Actor* target) : Component::Component(name)
{
	m_target = target;
}

void SeekComponent::setDesiredVelocity(float speed)
{
	m_desiredVelocity = (m_target->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition()).normalize() * speed;
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
