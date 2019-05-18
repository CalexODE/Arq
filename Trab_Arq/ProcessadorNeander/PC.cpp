#include "PC.h"

PC::PC(ULA u, REGS r, MEM m)
{
	ula = u;
	regs = r;
	mem = m;

	cont = 0;
	EA = 0;
	lastState = false;
}

void PC::FTE()
{
	int intrucao = mem.get(cont);
	cont++;
	int end = mem.get(cont);
	cont++;
	switch(EA)
	{
		case 0: //NOP

		case 1: //STA
			mem.set(end, regs.get(0));
			break;
		case 2: //LDA
			regs.set(regs.get(0), mem.get(end));
			break;
		case 3: //ADD
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(1);
			regs.set(regs.get(0), ula.getS());
			break;
		case 4: //OR
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(4);
			regs.set(regs.get(0), ula.getS());
			break;
		case 5: //AND
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(5);
			regs.set(regs.get(0), ula.getS());
			break;
		case 6: //NOT
			ula.setA(regs.get(0));
			ula.op(3);
			regs.set(regs.get(0), ula.getS());
			break;		
		case 7: //JMP
			cont = mem.get(end);
			break;
		case 8:	//JN
			if(ula.getN())
			{
				cont = mem.get(end);
			}
			break;
		case 9: //JZ
			if(ula.getZ())
			{
				cont = mem.get(end);
			}
			break;
		case 10: //HLT
			lastState=true;
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