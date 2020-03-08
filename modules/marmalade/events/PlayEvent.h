#pragma once
#include "scene/2d/node_2d.h"
#include "PlayEventChild.h"

//Class that acts as the root for all the things that make up an event. Actual event , actions , triggers etc are parented under this.
class PlayEvent : public Node2D
{
	GDCLASS(PlayEvent, Node2D);

protected:
	void _notification(int p_what);

public:
	virtual String get_configuration_warning() const;
};
