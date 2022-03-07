#pragma once
#include "Transform2D.h"
#include "Component.h"


class SeekComponent;

class WanderComponent :
	public Component
{
public:
	WanderComponent(float wanderRadius, float circleOffset, const char* name = "WanderComponent");
	WanderComponent(const char* name = "WanderComponent");


	void setCircleOffset(MathLibrary::Vector2 value) { m_circleOffset = value; }
	void setCircleOffset(float xpos) { m_circleOffset = MathLibrary::Vector2(xpos, 0); }

	void setCirclePos(MathLibrary::Vector2 value) { m_circlePos = value; }
	void setCirclePos(float xpos, float ypos) { m_circlePos = MathLibrary::Vector2(xpos, ypos); }

	MathLibrary::Vector2 getIntendedDirection();

	void update(float deltaTime) override;

protected:
	void setSeekComponent(SeekComponent* seekComponent) { m_seekComponent = seekComponent; };

private:
	float m_wanderRadius;
	float randPointX;
	float randPointY;
	MathLibrary::Vector2 m_circleOffset;
	MathLibrary::Vector2 m_circlePos;
	MathLibrary::Vector2 m_intendedDirection;
	SeekComponent* m_seekComponent;
};

