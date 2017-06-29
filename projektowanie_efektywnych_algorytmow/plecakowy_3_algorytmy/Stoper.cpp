#include "b.h"
#include "Stoper.h"
#include <Windows.h>

Stoper::Stoper()
{
	PCFreq = 0.0;
	CounterStart = 0;
}

Stoper::~Stoper()
{

}

void Stoper::Start()
{
	LARGE_INTEGER li;
	if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart)/1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double Stoper::Stop()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart-CounterStart)/PCFreq;
}