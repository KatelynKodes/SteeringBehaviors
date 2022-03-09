#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Engine.h"

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 newPos = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	if (newPos.x > Engine::getScreenWidth())
	{
		newPos.x = 0;
	}
	else if (newPos.x < 0)
	{
		newPos.x = Engine::getScreenWidth();
	}

	if (newPos.y > Engine::getScreenHeight())
	{
		newPos.y = 0;
	}
	else if (newPos.y < 0)
	{
		newPos.y = Engine::getScreenHeight();
	}

	getOwner()->getTransform()->setLocalPosition(newPos);
}
