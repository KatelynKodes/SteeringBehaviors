#include "ABDecision.h"

void BooleanDecision::makeDecision(Agent* actor, float deltaTime)
{
	if (checkCondition(actor, deltaTime))
	{
		if (m_left)
			m_left->makeDecision(actor, deltaTime);
	}
	else
	{
		if(m_right)
			m_right->makeDecision(actor, deltaTime);
	}
}

BooleanDecision::BooleanDecision(Decision* leftchild, Decision* rightChild)
{
	m_left = leftchild;
	m_right = rightChild;
}
