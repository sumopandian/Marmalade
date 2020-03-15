#include "PlayEvent.h"
#include "PlayEventTrigger.h"
#include "PlayEventAction.h"
#include "PlayEventSystem.h"
#include "modules/marmalade/core/debug.h"

void PlayEvent::_notification(int p_what)
{
	switch (p_what)
	{
		case NOTIFICATION_ENTER_TREE:
		{
			debug_print(LogLevel::Verbose , "Event: NOTIFICATION_ENTER_TREE");
			m_eventID = PlayEventSystem::GetInstance().AddEvent(this);
		}break;
		case NOTIFICATION_EXIT_TREE:
		{
			debug_print(LogLevel::Verbose ,"Event: NOTIFICATION_EXIT_TREE");
			if (m_eventID != -1)
			{
				PlayEventSystem::GetInstance().RemoveEvent(m_eventID);
			}
		}break;

		case NOTIFICATION_UNPARENTED:
		{
			debug_print(LogLevel::Verbose ,"Event: NOTIFICATION_UNPARENTED");
		}break;
		case NOTIFICATION_READY:
		{
			debug_print(LogLevel::Verbose ,"Event: NOTIFICATION_READY");
		}break;
		case NOTIFICATION_PARENTED:
		{
			debug_print(LogLevel::Verbose ,"Event: NOTIFICATION_PARENTED");
		}break;
	}	
}

String PlayEvent::get_configuration_warning() const
{
	bool hasTrigger = false;
	bool hasAction	= false;

	int childCount = get_child_count();

	for (int idx = 0; idx < childCount; idx++)
	{
		if (Node* p_node = get_child(idx))
		{
			if (cast_to<PlayEventAction>(p_node))
			{
				hasAction	= true;
			}
			if (cast_to<PlayEventTrigger>(p_node))
			{
				hasTrigger	= true;
			}
		}
	}

	if (!hasAction || !hasTrigger) {
		return TTR("Requires atleast one action and one trigger for an event to function properly");
	}

	return String("");
}
