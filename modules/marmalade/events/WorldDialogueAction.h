#pragma once
#include "PlayEventAction.h"


class WorldDialogueAction : public PlayEventAction
{
	GDCLASS(WorldDialogueAction, PlayEventAction);
public:

	WorldDialogueAction();

	//Called by the event system when an event is successfully triggered on the underlying actions
	virtual void ExecuteAction() override;

	virtual void Reset() override;

protected:
	static void _bind_methods();

	void	set_Dialogue(const String& p_Dialogue);
	String	get_Dialogue() const;

protected:
	String	m_Dialogue;
};
