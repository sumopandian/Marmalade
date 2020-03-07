#pragma once
#include "scene/2d/node_2d.h"
#include "scene/2d/physics_body_2d.h"

class MaPlayerMovment : public Node2D
{
	GDCLASS(MaPlayerMovment, Node2D);
public:
	MaPlayerMovment();

protected:
	void _notification(int p_what);
	void updateMovement();

public:
	virtual String get_configuration_warning() const;

private:
	KinematicBody2D*	m_physicsBody;
};
