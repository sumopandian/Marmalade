#include "PlayEventAction.h"

PlayEventAction::PlayEventAction()
	: m_HasActionActivated(false)
{

}

void PlayEventAction::ExecuteAction()
{
	if (m_HasActionActivated)
	{
		print_error("Trying to activate a trigger that has already been activated for trigger : " + get_class_name() + " , with name:" + get_name());
	}
	m_HasActionActivated = true;
}

void PlayEventAction::Reset()
{
	m_HasActionActivated = false;
}

bool PlayEventAction::HasActionActivated() const
{
	return m_HasActionActivated;
}
