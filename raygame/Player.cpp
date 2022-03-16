#include "Player.h"
#include "MoveComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

Player::Player()
{
}

Player::Player(float x, float y, const char* name, MathLibrary::Vector2 velocity) : Actor(x, y, name)
{
	m_velocity = velocity;
}

Player::~Player()
{
}

void Player::start()
{
	Actor::start();
	addComponent(new InputComponent());
	addComponent(new MoveComponent());
	getComponent<MoveComponent>()->setMaxSpeed(500);
	addComponent(new SpriteComponent("Images/player.png"));
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * m_moveComponent->getMaxSpeed());
}

void Player::draw()
{
	Actor::draw();
}
