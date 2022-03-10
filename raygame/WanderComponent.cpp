#include "WanderComponent.h"
#include "MoveComponent.h"
#include "Actor.h"
#include <stdlib.h>
#include<time.h>

WanderComponent::WanderComponent(float wanderRadius, float circleDistance, float wanderForce) : SteeringComponent::SteeringComponent(nullptr, wanderForce)
{
	m_wanderRadius = wanderRadius;
	m_circleDistance = circleDistance;
}

MathLibrary::Vector2 WanderComponent::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0,0 };

	//find the agents position and heading
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getMoveComponent()->getVelocity().getNormalized();

	//Move the circle position away from the owner
	m_circlePos = ownerPos + (heading * m_circleDistance);

	//find a random vector in the circle
	float randNum1 = (rand() & 201) - 100;
	float randNum2 = (rand() & 201) - 100;

	MathLibrary::Vector2 randDir = MathLibrary::Vector2(randNum1, randNum2).normalize() * m_wanderRadius;

	//Add the random vector to the circle position to get a new random point on the circle
	m_target = randDir + m_circlePos;

	//Seek to the random point
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPos) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getMoveComponent()->getVelocity();
	return MathLibrary::Vector2();
}
