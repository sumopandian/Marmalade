#pragma once
#include "PlayEventTrigger.h"

//A simple area trigger that returns true when the area node assigned is being overlapped
class AreaEventTrigger : public PlayEventTrigger
{
	GDCLASS(AreaEventTrigger, PlayEventTrigger);
public:
		
	virtual bool CheckTriggerCondition() override;
	
	void set_Area2D(const NodePath& p_Area2D);
	NodePath get_Area2D() const;

protected:
	void	_notification(int p_what);
	static void _bind_methods();
	
private:
	void _body_shape_entered(ObjectID body_id, Node* body, int body_shape, int area_shape);
	void _body_shape_exited(ObjectID body_id, Node* body, int body_shape, int area_shape);

	NodePath	m_Area2DPath;
	bool		m_IsOverlapping = false;

};
