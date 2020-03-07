#pragma once
#include "scene/main/scene_tree.h"
#include "MaPlayerInput.h"

class MaGameloop : public SceneTree
{
	GDCLASS(MaGameloop, SceneTree);

public:
	virtual void input_event(const Ref<InputEvent> &p_event) override;
	virtual void input_text(const String &p_text) override;
	virtual void init() override;
	virtual bool iteration(float p_time) override;
	virtual bool idle(float p_time) override;
	virtual void finish() override;

	const MaPlayerInput& GetPlayerInput() { return m_playerInput; }

	static MaGameloop* GetGameLoop()
	{
		return Object::cast_to<MaGameloop>(get_singleton());
	}

protected:
	static void _bind_methods();

private:
	MaPlayerInput	m_playerInput;
};

