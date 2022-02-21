#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 newPos = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	getOwner()->getTransform()->setLocalPosition(newPos);
}
