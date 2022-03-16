#pragma once

class Agent;

///<summary>
/// Abstract class for all decisions
///</summary>
class Decision
{
public:
	virtual void makeDecision(Agent* Actor, float deltaTime) = 0;

};

