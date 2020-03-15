#include "MaPlayerInput.h"
#include "core/input_map.h"
#include "core/os/keyboard.h"
#include "modules/marmalade/core/debug.h"

MaInputState MaInputState::Empty;

MaPlayerInput::MaPlayerInput()
{
}

Ref<InputEventKey> CreateKeyMap(const KeyList& KeyEnum)
{
	Ref<InputEventKey> key;
	key.instance();
	key->set_scancode(KeyEnum);
	return key;
}

void MaPlayerInput::OnInputEvent(const Ref<InputEvent>& inputEvent)
{
	for (auto localMap = m_inputMaps.front(); localMap; localMap = localMap->next())
	{
		if (InputMap* p_inputMap = InputMap::get_singleton())
		{
			const String& action = localMap->key();
			if (p_inputMap->action_has_event(action, inputEvent))
			{
				bool	pressed;
				float	strength;

				if (p_inputMap->event_get_action_status(inputEvent, action, &pressed, &strength))
				{
					MaInputState& state = localMap->get();
					
					state.m_pressed		= pressed;
					state.m_strength	= strength;
					
					debug_print(LogLevel::Verbose ,"Action processed:" + action + " , pressed:" + ( (pressed)?"true":"false") + ", strength:" + rtos(strength));
				}
			}
		}
	}
}

void MaPlayerInput::SetupDefaultInputActions()
{
	if (InputMap *p_inputMap = InputMap::get_singleton())
	{
		//Up keys
		{
			p_inputMap->add_action(MaPlayerActions::Move_Up);
			
			p_inputMap->action_add_event(MaPlayerActions::Move_Up, CreateKeyMap(KeyList::KEY_UP));
			p_inputMap->action_add_event(MaPlayerActions::Move_Up, CreateKeyMap(KeyList::KEY_W));

			m_inputMaps.insert(MaPlayerActions::Move_Up, MaInputState());
		}

		//Down keys
		{
			p_inputMap->add_action(MaPlayerActions::Move_Down);

			p_inputMap->action_add_event(MaPlayerActions::Move_Down, CreateKeyMap(KeyList::KEY_DOWN));
			p_inputMap->action_add_event(MaPlayerActions::Move_Down, CreateKeyMap(KeyList::KEY_S));

			m_inputMaps.insert(MaPlayerActions::Move_Down, MaInputState());
		}

		//Left keys
		{
			p_inputMap->add_action(MaPlayerActions::Move_Left);

			p_inputMap->action_add_event(MaPlayerActions::Move_Left, CreateKeyMap(KeyList::KEY_LEFT));
			p_inputMap->action_add_event(MaPlayerActions::Move_Left, CreateKeyMap(KeyList::KEY_A));

			m_inputMaps.insert(MaPlayerActions::Move_Left, MaInputState());
		}

		//Right keys
		{
			p_inputMap->add_action(MaPlayerActions::Move_Right);

			p_inputMap->action_add_event(MaPlayerActions::Move_Right, CreateKeyMap(KeyList::KEY_RIGHT));
			p_inputMap->action_add_event(MaPlayerActions::Move_Right, CreateKeyMap(KeyList::KEY_D));

			m_inputMaps.insert(MaPlayerActions::Move_Right, MaInputState());
		}
	}
}
