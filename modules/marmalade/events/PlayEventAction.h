#pragma once
#include "PlayEventChild.h"

//The actual action an event executes
class PlayEventAction : public PlayEventChild
{
	GDCLASS(PlayEventAction, PlayEventChild);
public:

	PlayEventAction();

	//Called by the event system when an event is successfully triggered on the underlying actions
	virtual void ExecuteAction();

	virtual void Reset();

	bool HasActionActivated() const;

private:
	bool	m_HasActionActivated;

};
