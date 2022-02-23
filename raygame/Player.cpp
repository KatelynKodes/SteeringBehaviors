#include "Player.h"
#include "MoveComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

Player::Player()
{
}

Player::Player(float x, float y, const char* name, MathLibrary::Vector2 velocity) : Actor::Actor(x,y,name)
{
	m_velocity = velocity;
}

Player::~Player()
{
}

void Player::start()
{
	Actor::start();
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * m_moveComponent->getMaxSpeed());

	Actor::update(deltaTime);
}

void Player::draw()
{
	Actor::draw();
}
