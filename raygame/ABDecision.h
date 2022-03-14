#pragma once
#include "Decision.h"

///<summary>
/// A decision that has 2 children attatched
///</summary>
class BooleanDecision :
	public Decision
{
public:
	BooleanDecision(Decision* leftchild = nullptr, Decision* rightChild = nullptr);
	///<summary>
	/// Checks the condition and transitions to a different decision based on the return value
	///</summary>
	///<param name = "agent">the agent that this decision tree is attatched to</param>
	///<param name = "deltaTime">The amount of time between frames.</param>
	virtual void makeDecision(Agent* actor, float deltaTime) override;

	/// <summary>
	/// Checks if a certain has been met and returns the result
	/// </summary>
	///<param name = "agent">the agent that this decision tree is attatched to</param>
	///<param name = "deltaTime">The amount of time between frames.</param>
	virtual bool checkCondition(Agent* actor, float deltaTime) { return false; }

	

private:
	Decision* m_left;
	Decision* m_right;
};

