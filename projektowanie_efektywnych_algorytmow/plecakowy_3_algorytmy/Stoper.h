#include "b.h"
#ifndef _stoper_h_
#define _stoper_h_

class Stoper
{
private:
	double PCFreq;
	__int64 CounterStart;
public:

	Stoper();
	~Stoper();

	void Start();
	double Stop();
};

#endif