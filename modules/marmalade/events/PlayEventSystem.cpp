#include "PlayEventSystem.h"
#include "PlayEvent.h"
#include "PlayEventChild.h"
#include "PlayEventAction.h"
#include "PlayEventTrigger.h"
#include "core/object.h"

PlayEventSystem::PlayEventSystem()
{

}

PlayEventSystem::~PlayEventSystem()
{
	Clear();
}

int		PlayEventSystem::AddEvent(PlayEvent* event)
{
	if (!event)
	{
		print_error("The supplied Add event is null");
	}
	m_EventGroups.push_back(ExtractEventGroup(event));

	//Simply return the index as the ID
	return m_EventGroups.size() - 1;
}

void	PlayEventSystem::RemoveEvent(int eventId)
{

	if (eventId >= 0 && eventId < m_EventGroups.size())
	{
		//This is costly loops through the elements and rearranges it. Maybe move to the update  to keep the indexs in check
		m_EventGroups.remove(eventId);
	}
}

void PlayEventSystem::Clear()
{
	m_EventGroups.clear();
}

void PlayEventSystem::ProcessEvents()
{
	for (int idx = 0; idx < m_EventGroups.size(); idx++)
	{
		PlayEventGroup& Event = m_EventGroups.get(idx);

		Vector<PlayEventTrigger*>&	Triggers	= Event.m_data.m_PlayEventTriggers;

		bool bTriggered = false;

		for (int trigIdx = 0; trigIdx < Triggers.size(); trigIdx++)
		{
			PlayEventTrigger* Trigger = Triggers[trigIdx];
			if (Trigger)
			{
				bTriggered = bTriggered || Trigger->CheckTriggerCondition();
				//Do we want to push this to an inactive list once the trigger condition is fulfilled or keep it in the loop ?
			}
		}

		if (bTriggered)
		{
			Vector<PlayEventAction*>& Actions = Event.m_data.m_PlayEventActions;
			for (int actIdx = 0; actIdx < Actions.size(); actIdx++)
			{
				PlayEventAction* Action = Actions[actIdx];
				if (Action && !Action->HasActionActivated())
				{
					Action->ExecuteAction();
				}
			}
		}
	}
}

PlayEventGroup PlayEventSystem::ExtractEventGroup(PlayEvent* event)
{
	//The is assuming the PlayEvent is the root for the actions and triggers. Also their lifecycle are the same. Otherwise there might be unexpected results.

	int childCount = event->get_child_count();

	if (childCount < 2)
	{
		print_error("There needs to be 2 or more PlayEventChild to a play event. Atleast one PlayEventTrigger and one PlayEventAction");
		return PlayEventGroup();
	}

	PlayEventGroup Group = PlayEventGroup();

	Group.m_data.m_PlayEvent = event;

	for (int idx = 0; idx < childCount; idx++)
	{
		Node* childNode = event->get_child(idx);

		PlayEventChild* childEvent = Object::cast_to<PlayEventChild>(childNode);
		
		if (childEvent)
		{
			if (PlayEventAction* action = Object::cast_to<PlayEventAction>(childNode))
			{
				Group.m_data.m_PlayEventActions.push_back(action);
			}
			if (PlayEventTrigger* trigger = Object::cast_to<PlayEventTrigger>(childNode))
			{
				Group.m_data.m_PlayEventTriggers.push_back(trigger);
			}
		}	
	}

	return Group;
}
