#include "ULA.h"

void ULA::setA(float a)
{
	this->a = a;
}

void ULA::setB(float b)
{
	this->b = b;
}

float ULA::getS(void)
{
	return this->s;
}

void ULA::ulaOp(int op)
{
	switch(op)
	{
		case 1:
			s = a + b;
			break;
		case 2:
			s = a - b;
			break;
		default:
			break;
	}
}