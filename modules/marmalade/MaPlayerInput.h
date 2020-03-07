#pragma once
#include "core/map.h"
#include "core/os/input_event.h"

namespace MaPlayerActions
{
	static const String Move_Up		= "Move_Up";
	static const String Move_Down	= "Move_Down";
	static const String Move_Left	= "Move_Left";
	static const String Move_Right	= "Move_Right";
}

struct MaInputState
{
	MaInputState()
		:m_pressed(false)
		,m_strength(0.0f)
	{

	}

	void Reset()
	{
		m_pressed	= false;
		m_strength	= 0.0f;
	}

	bool	m_pressed;
	float	m_strength;

	static MaInputState Empty;
};

class MaPlayerInput
{
public:
	MaPlayerInput();

	void OnInputEvent(const Ref<InputEvent>& inputEvent);

	//Create your own input mappings
	void SetupDefaultInputActions();

	bool HasInputState(const String& action) const
	{
		return m_inputMaps.has(action);
	}

	const MaInputState& GetInputState(const String& action) const
	{
		if (HasInputState(action))
		{
			return m_inputMaps[action];
		}
		return MaInputState::Empty;
	}

private:

	Map<String, MaInputState>	m_inputMaps;
};
