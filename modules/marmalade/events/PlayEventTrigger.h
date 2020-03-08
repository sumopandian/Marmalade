#pragma once
#include "PlayEventChild.h"

//The trigger for the ensuing event. There can be multiple triggers for a event if need.
class PlayEventTrigger : PlayEventChild
{
	GDCLASS(PlayEventTrigger, PlayEventChild);
public:

	PlayEventTrigger();

	//returns true if the trigger conditions are met
	virtual bool CheckTriggerCondition() { return false; }

	//called by the event system to say the trigger is activated
	virtual void ActivateTrigger();

	//called for triggers that are retriggerable
	virtual void Reset();

	bool HasTriggerdActivated() const;

protected:

private:
	bool	m_HasTriggerActivated;
};
