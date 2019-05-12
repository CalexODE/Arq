#ifndef PC_H
#define PC_H

#include "REGS.h"
#include "ULA.h"

class PC
{
	public:
		int EA;
		int PE;
		bool lastState;
		ULA ula;
		REGS regs;

		PC(ULA ula, REGS regs);
		void FTE();
		void updateState();
		bool getLastState();
};

#endif