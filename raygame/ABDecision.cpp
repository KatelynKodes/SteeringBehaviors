#include "ABDecision.h"

void BooleanDecision::makeDecision(Agent* actor, float deltaTime)
{
	if (checkCondition(actor, deltaTime))
	{
		if (m_true)
			m_true->makeDecision(actor, deltaTime);
	}
	else
	{
		if(m_false)
			m_false->makeDecision(actor, deltaTime);
	}
}

BooleanDecision::BooleanDecision(Decision* truechild, Decision* falseChild)
{
	m_true = truechild;
	m_false = falseChild;
}
