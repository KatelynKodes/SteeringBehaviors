#include "Enemy.h"
#include "Transform2D.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "DecisionComponent.h"
#include "AggressiveDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "WanderDecision.h"
#include "SeekDecision.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target): Agent(x,y,maxForce,maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	AggressiveDecision* aggresive = new AggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggresive);

	addComponent(new DecisionComponent(inRange));

	getTransform()->setScale({ 50,50 });
	setMaxForce(200);
	addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* wanderComponent = new WanderComponent(100, 100, 100);
	addComponent(wanderComponent);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(m_target);
	addComponent(seekComponent);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	MathLibrary::Vector2 direction = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();

	return distance <= 300 && acos(MathLibrary::Vector2::dotProduct(direction, getTransform()->getForward())) < 1;
}
