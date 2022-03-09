#include "WanderComponent.h"
#include "Actor.h"
#include <stdlib.h>

WanderComponent::WanderComponent(float wanderRadius, float circleOffset, const char* name) : Component::Component(name)
{
	m_wanderRadius = wanderRadius;
	setCirclePos(getOwner()->getTransform()->getLocalPosition());
	m_circleOffset = MathLibrary::Vector2(circleOffset, 0);
}

WanderComponent::WanderComponent(const char* name)
{
	MathLibrary::Vector2 ownerSize = getOwner()->getTransform()->getScale();
	m_wanderRadius = ownerSize.x > ownerSize.y ? ownerSize.x : ownerSize.y;

	setCirclePos(getOwner()->getTransform()->getLocalPosition());
}

MathLibrary::Vector2 WanderComponent::getIntendedDirection()
{
	randPointX = rand() % 100 + (-100);
	randPointY = rand() % 100 + (-100);
	MathLibrary::Vector2 direction = MathLibrary::Vector2(randPointX, randPointY);
	return direction;
}

void WanderComponent::update(float deltaTime)
{
	setCirclePos(getOwner()->getTransform()->getLocalPosition() + m_circleOffset);

	getIntendedDirection();

}
