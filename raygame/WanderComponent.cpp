#include "WanderComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <stdlib.h>

WanderComponent::WanderComponent(float wanderRadius, const char* name) : Component::Component(name)
{
	m_wanderRadius = wanderRadius;
}

WanderComponent::WanderComponent(const char* name)
{
	MathLibrary::Vector2 ownerSize = getOwner()->getTransform()->getScale();
	m_wanderRadius = ownerSize.x > ownerSize.y ? ownerSize.x : ownerSize.y;
}

MathLibrary::Vector2 WanderComponent::getIntendedDirection()
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2()
	return MathLibrary::Vector2();
}

void WanderComponent::update(float deltaTime)
{
}
