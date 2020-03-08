#include "PlayEventTrigger.h"

PlayEventTrigger::PlayEventTrigger()
	:PlayEventChild()
	, m_HasTriggerActivated(false)
{

}

void PlayEventTrigger::ActivateTrigger()
{
	if (m_HasTriggerActivated)
	{
		print_error("Trying to activate a trigger that has already been activated for trigger : " + this->get_class_name() + " , with name:" + this->get_name());
	}
	m_HasTriggerActivated = true;
}

void PlayEventTrigger::Reset()
{
	m_HasTriggerActivated = false;
}

bool PlayEventTrigger::HasTriggerdActivated() const
{
	return m_HasTriggerActivated;
}
