#include "AreaEventTrigger.h"
#include "scene/2d/area_2d.h"
#include "scene/scene_string_names.h"

bool AreaEventTrigger::CheckTriggerCondition()
{
	return m_IsOverlapping;
}

void AreaEventTrigger::set_Area2D(const NodePath& p_Area2D) {
	if (m_Area2DPath == p_Area2D)
		return;
	m_Area2DPath = p_Area2D;;
}

NodePath AreaEventTrigger::get_Area2D() const {
	return m_Area2DPath;
}

void AreaEventTrigger::_notification(int p_what)
{
	if (p_what == NOTIFICATION_READY)
	{
		if (has_node(m_Area2DPath))
		{
			Area2D* area2D = cast_to<Area2D>(get_node(m_Area2DPath));
			if (area2D)
			{
				print_line("Properly assigned area node");
				area2D->connect(SceneStringNames::get_singleton()->body_shape_entered, this, "_body_shape_entered");
				area2D->connect(SceneStringNames::get_singleton()->body_shape_exited, this, "_body_shape_exited");
			}
		}		 
	}
}

void AreaEventTrigger::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("_body_shape_entered","body_id","body","body_shape","area_shape"), &AreaEventTrigger::_body_shape_entered);
	ClassDB::bind_method(D_METHOD("_body_shape_exited","body_id","body","body_shape","area_shape"), &AreaEventTrigger::_body_shape_exited);

	ClassDB::bind_method(D_METHOD("set_Area2D","area2D"), &AreaEventTrigger::set_Area2D);
	ClassDB::bind_method(D_METHOD("get_Area2D"), &AreaEventTrigger::get_Area2D);

	ADD_GROUP("Event", "");
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "area_trigger", PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Area2D"), "set_Area2D", "get_Area2D");
}

void AreaEventTrigger::_body_shape_entered(ObjectID body_id, Node* body, int body_shape, int area_shape)
{
	m_IsOverlapping = true;
	print_line("Overlap Begin");
}

void AreaEventTrigger::_body_shape_exited(ObjectID body_id, Node* body, int body_shape, int area_shape)
{
	m_IsOverlapping = false;
	print_line("Overlap End");
}
