#pragma once
#include <string>
using namespace std;

class Podaci
{
public:
	Podaci();
	void prema_gore();
	void prema_dolje();
	string to_string();

private:
	int stanje;
};

