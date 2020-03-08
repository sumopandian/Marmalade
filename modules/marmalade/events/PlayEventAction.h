#pragma once
#include "PlayEventChild.h"

//The actual action an event executes
class PlayEventAction : PlayEventChild
{
	GDCLASS(PlayEventAction, PlayEventChild);
public:

	//Called by the event system when an event is successfully triggered
	virtual bool ExecuteAction() {}

protected:

};
