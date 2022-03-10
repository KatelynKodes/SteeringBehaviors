#pragma once
#include "Actor.h"
#include "Transform2D.h"

class MoveComponent;
class InputComponent;
class SpriteComponent;

class Player :
	public Actor
{
public:
	//Constructors/deconstructors
	Player();
	Player(float x, float y, MathLibrary::Vector2 velocity);
	~Player();

	//Gets velocity and speed
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	//update method
	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:
	MathLibrary::Vector2 m_velocity;
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

