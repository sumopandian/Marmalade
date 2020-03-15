#include "WorldDialogueAction.h"
#include "modules/marmalade/core/debug.h"

WorldDialogueAction::WorldDialogueAction()
	: PlayEventAction()
{

}

void WorldDialogueAction::ExecuteAction()
{
	PlayEventAction::ExecuteAction();
	debug_print( LogLevel::Log ,"Action:" + m_Dialogue);
}

void WorldDialogueAction::Reset()
{
	PlayEventAction::Reset();
}

void WorldDialogueAction::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("set_Dialogue","dialogue"), &WorldDialogueAction::set_Dialogue);
	ClassDB::bind_method(D_METHOD("get_Dialogue"), &WorldDialogueAction::get_Dialogue);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "world_dialogue"), "set_Dialogue", "get_Dialogue");
}

void WorldDialogueAction::set_Dialogue(const String& p_Dialogue)
{
	m_Dialogue = p_Dialogue;
}

String WorldDialogueAction::get_Dialogue() const
{
	return m_Dialogue;
}
