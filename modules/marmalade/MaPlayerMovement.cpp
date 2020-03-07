#include "MaPlayerMovement.h"
#include "MaGameloop.h"

MaPlayerMovment::MaPlayerMovment()
{
	m_physicsBody = NULL;
}

void MaPlayerMovment::_notification(int p_what)
{
	switch (p_what)
	{
		case NOTIFICATION_UNPARENTED:
		{
			m_physicsBody = NULL;
		}break;
		case NOTIFICATION_READY:
		{
			set_physics_process(true);
		}break;
		case NOTIFICATION_PARENTED:
		{
			m_physicsBody = Object::cast_to<KinematicBody2D>(get_parent());
		}break;
		case NOTIFICATION_PHYSICS_PROCESS:
		{
			updateMovement();
		} break;
	}
}

void MaPlayerMovment::updateMovement()
{
	float deltaTime = get_physics_process_delta_time();

	if (!m_physicsBody || !MaGameloop::GetGameLoop())
	{
		//Need to debug one of these objects gets nulled in between updates
		//print_error("Issue with the game object and parent of movement");
		return;
	}

	Vector2 motion = Vector2();

	const MaPlayerInput& Input = MaGameloop::GetGameLoop()->GetPlayerInput();

	motion.x = Input.GetInputState(MaPlayerActions::Move_Right).m_strength - Input.GetInputState(MaPlayerActions::Move_Left).m_strength;
	motion.y = Input.GetInputState(MaPlayerActions::Move_Down).m_strength - Input.GetInputState(MaPlayerActions::Move_Up).m_strength;
	motion.y *= 0.5;
	motion = motion.normalized() * 160.0f; 
	m_physicsBody->move_and_slide(motion); // Function seems to multiply delta time internally
}


String MaPlayerMovment::get_configuration_warning() const
{
	if (!Object::cast_to<KinematicBody2D>(get_parent())) {
		return TTR("The player movement node needs to be parented unders a KinematicBody2D . Please parent it properly");
	}
	if(GLOBAL_GET("application/run/main_loop_type") != "MaGameloop")
	{
		return TTR("Only works with the game loop set to MaGameLoop. Change the project settings.");
	}
	return String();
}
