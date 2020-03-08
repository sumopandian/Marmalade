#pragma once
#include "scene/main/scene_tree.h"
#include "core/vector.h"

class PlayEvent;
class PlayEventAction;
class PlayEventTrigger;

class PlayEventGroup
{
public:
	PlayEventGroup();
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

	void InitFromTree(SceneTree* Tree);
	void Clear();

	void ProcessEvents();

	const PlayEventSystem& GetInstance()
	{
		static PlayEventSystem Instance;
		return Instance;
	}

private:
	Vector<PlayEventGroup>	m_EventGroups;
};
