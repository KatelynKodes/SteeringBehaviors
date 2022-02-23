#include "ChaseEnemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"

ChaseEnemy::ChaseEnemy()
{
	m_enemySpeed = 0;
	m_chasee = nullptr;
}

ChaseEnemy::ChaseEnemy(float x, float y, const char* name, Actor* chasee, float enemySpeed) : Actor::Actor(x,y,name)
{
	m_enemySpeed = enemySpeed;
	m_chasee = chasee;
}

void ChaseEnemy::start()
{
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(m_enemySpeed);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComponent = dynamic_cast <SeekComponent*>(addComponent(new SeekComponent(m_chasee, 60)));
	m_seekComponent->setMoveComponent(m_moveComponent);
}

void ChaseEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
