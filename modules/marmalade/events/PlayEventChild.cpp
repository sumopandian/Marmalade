#include "PlayEventChild.h"
#include "PlayEvent.h"


void PlayEventChild::_notification(int p_what)
{

}

String PlayEventChild::get_configuration_warning() const
{
	if (!Object::cast_to<PlayEvent>(get_parent())) {
		return TTR("The node can only be a child of PlayEvent node for it to work properly.");
	}
	return String();
}
