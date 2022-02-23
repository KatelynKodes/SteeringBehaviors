#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class SeekComponent;

class ChaseEnemy :
	public Actor
{
public:
	ChaseEnemy();
	ChaseEnemy(float x, float y, const char* name, Actor* chasee, float enemySpeed);
	~ChaseEnemy();

	void start() override;
	void update(float deltaTime) override;

private:
	float m_enemySpeed;
	Actor* m_chasee;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	SeekComponent* m_seekComponent;
};

