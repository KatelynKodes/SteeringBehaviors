#include "ChaseEnemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "SteeringComponent.h"

void ChaseEnemy::start()
{
	Actor::start();

	m_moveComponent = addComponent<MoveComponent>();
	addComponent(new SpriteComponent("Images/enemy.png"));
	m_moveComponent->setMaxSpeed(500);
}

void ChaseEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	for (int i = 0; i < m_SteeringComponents.getLength(); i++)
		m_force = m_force + m_SteeringComponents[i]->calculateForce();

	if (m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();


	m_moveComponent->setVelocity(m_moveComponent->getVelocity() + m_force * deltaTime);
}

void ChaseEnemy::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);

	if (!steeringComponent)
		m_SteeringComponents.addItem(steeringComponent);
}
