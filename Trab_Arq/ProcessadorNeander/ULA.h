#ifndef ULA_H
#define ULA_H

class ULA
{
public:
	float a, b, s;

	ULA();

	void setA(float a);
	void setB(float b);

	float getS(void);
	void ulaOp(int op);
};

#endif