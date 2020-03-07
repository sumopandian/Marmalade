

#include "register_types.h"
#include "core/class_db.h"
#include "MaGameloop.h"
#include "MaPlayerMovement.h"

void register_marmalade_types()
{
	ClassDB::register_class<MaGameloop>();
	ClassDB::register_class<MaPlayerMovment>();

#ifdef TOOLS_ENABLED
#endif
}

void unregister_marmalade_types()
{

}
