#include "PC.h"

PC::PC(ULA u, REGS r)
{
	ula = u;
	regs = r;
	EA = 0;
	lastState = false;
}

void PC::FTE()
{
	switch(EA)
	{
		case 0:
		case 1:
		default:
			break;
	}
}

void PC::updateState()
{
	EA = PE;
}

bool PC::getLastState()
{
	return lastState;
}