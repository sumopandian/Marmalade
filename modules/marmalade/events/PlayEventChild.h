#pragma once
#include "core/node_path.h"
#include "core/vector.h"
#include "scene/2d/node_2d.h"

//Event children like actions , triggers are to be inherited from this.
class PlayEventChild : public Node2D
{
	GDCLASS(PlayEventChild, Node2D);

protected:
	void _notification(int p_what);

public:
	virtual String get_configuration_warning() const;
};
