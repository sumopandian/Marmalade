#pragma once
#include "PlayEventChild.h"

//The trigger for the ensuing event. There can be multiple triggers for a event if need.
class PlayEventTrigger : public PlayEventChild
{
	GDCLASS(PlayEventTrigger, PlayEventChild);
public:

	//returns true if the trigger conditions are met
	virtual bool CheckTriggerCondition() { return false; }	

	//called for triggers that are retriggerable
	virtual void Reset() {}
	
};
