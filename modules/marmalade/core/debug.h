#pragma once
#include "core/print_string.h"

#define NOOP ((void)0)

namespace LogLevel
{
	enum Type
	{
		Error = 0,		
		Log,	
		Verbose
	};
}

extern void debug_print_internal(const LogLevel::Type& MessageLevel, String inString);


#if DEBUG_ENABLED
#define debug_print( logLevel, debugStr ) debug_print_internal( logLevel, debugStr )
#else
#define debug_print( logLevel, debugStr ) NOOP
#endif
