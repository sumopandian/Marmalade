#include "PlayEvent.h"
#include "PlayEventTrigger.h"
#include "PlayEventAction.h"

void PlayEvent::_notification(int p_what)
{
	switch (p_what)
	{
		case NOTIFICATION_UNPARENTED:
		{

		}break;
		case NOTIFICATION_READY:
		{

		}break;
		case NOTIFICATION_PARENTED:
		{

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
