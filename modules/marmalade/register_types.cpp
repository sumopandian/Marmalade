

#include "register_types.h"
#include "core/class_db.h"
#include "MaGameloop.h"
#include "MaPlayerMovement.h"
#include "events/PlayEvent.h"
#include "events/PlayEventChild.h"
#include "events/PlayEventAction.h"
#include "events/PlayEventTrigger.h"
#include "events/AreaEventTrigger.h"
#include "events/WorldDialogueAction.h"

void register_marmalade_types()
{
	ClassDB::register_class<MaGameloop>();
	ClassDB::register_class<MaPlayerMovment>();
	ClassDB::register_class<PlayEvent>();
	ClassDB::register_class<PlayEventChild>();
	ClassDB::register_class<PlayEventAction>();
	ClassDB::register_class<PlayEventTrigger>();
	ClassDB::register_class<AreaEventTrigger>();
	ClassDB::register_class<WorldDialogueAction>();

#ifdef TOOLS_ENABLED
#endif
}

void unregister_marmalade_types()
{

}
