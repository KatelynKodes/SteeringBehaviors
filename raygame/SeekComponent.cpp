#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	setSteeringForce(500);

	MathLibrary::Vector2 targetDir = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 desiredVelocity = targetDir.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - 
	return seekForce;
}
