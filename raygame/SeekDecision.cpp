#include "SeekDecision.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Enemy.h"
#include "Agent.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	SeekComponent* seek = agent->getComponent<SeekComponent>();
	WanderComponent* wander = agent->getComponent<WanderComponent>();

	if (seek)
		seek->setSteeringForce(57);

	if (wander)
		wander->setSteeringForce(0);
}
