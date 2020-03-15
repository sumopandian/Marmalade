#include "debug.h"
#include "core/os/os.h"
#include <stdio.h>


void debug_print_internal(const LogLevel::Type& MessageLevel, String inString)
{
	switch (MessageLevel)
	{
	case LogLevel::Log: print_line(inString); break;
	case LogLevel::Error: print_error(inString); break;
	case LogLevel::Verbose: print_verbose(inString); break;
	default:
		break;
	}
}
