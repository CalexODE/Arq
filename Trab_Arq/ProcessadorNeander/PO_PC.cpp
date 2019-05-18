#include "PC.h"

int main()
{
	ULA *ula = new ULA();
    REGS *regs =  new REGS();
    MEM *mem = new MEM();
    PC *pc = new PC(*ula, *regs, *mem);

    for(int clock=0; clock < 500; clock++)
    {
    	pc->FTE();
    	pc->updateState();
    	if (pc->getLastState() == true)
    	{
    		break;
    	}
    }
}