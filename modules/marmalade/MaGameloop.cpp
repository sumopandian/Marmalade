#include "MaGameloop.h"
#include "events/PlayEventSystem.h"

void MaGameloop::input_event(const Ref<InputEvent> &p_event)
{
	SceneTree::input_event(p_event);

	if (p_event.is_valid())
	{
		m_playerInput.OnInputEvent(p_event);
	}
}

void MaGameloop::input_text(const String &p_text)
{
	SceneTree::input_text(p_text);
}

void MaGameloop::init()
{
	PlayEventSystem::GetInstance().Clear();

	SceneTree::init();
	m_playerInput.SetupDefaultInputActions();	
}

bool MaGameloop::iteration(float p_time)
{
	PlayEventSystem::GetInstance().ProcessEvents();
	return SceneTree::iteration(p_time);
}

bool MaGameloop::idle(float p_time)
{
	return SceneTree::idle(p_time);
}

void MaGameloop::finish()
{
	PlayEventSystem::GetInstance().Clear();
	SceneTree::finish();
}

void MaGameloop::_bind_methods()
{
}
