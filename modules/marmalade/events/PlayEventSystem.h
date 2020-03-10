#pragma once
#include "scene/main/scene_tree.h"
#include "core/vector.h"

class PlayEvent;
class PlayEventAction;
class PlayEventTrigger;

class PlayEventGroup
{
public:
	PlayEventGroup() {};
	//[TODO] Everything here is a raw pointer make sure properly handle and check how the lifecycle is managed for each

public:
	struct Data
	{
		PlayEvent*					m_PlayEvent = nullptr;
		Vector<PlayEventAction*>	m_PlayEventActions;
		Vector<PlayEventTrigger*>	m_PlayEventTriggers;
	};

	PlayEventGroup::Data m_data;
};

class PlayEventSystem
{
public:

	PlayEventSystem();
	virtual ~PlayEventSystem();

	//returns the event Id is succeeded or returns -1 if failed
	int		AddEvent(PlayEvent* event);
	void	RemoveEvent(int eventId);
	
	void Clear();
	void ProcessEvents();

	static PlayEventSystem& GetInstance()
	{
		static PlayEventSystem Instance;
		return Instance;
	}

private:

	PlayEventGroup ExtractEventGroup(PlayEvent* event);

	Vector<PlayEventGroup>	m_EventGroups;
};
