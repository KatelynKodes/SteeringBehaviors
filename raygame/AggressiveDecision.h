#pragma once
#include "ABDecision.h"

class AggressiveDecision :
	public BooleanDecision
{
public:
	AggressiveDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecision(left, right) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};

