#include <iostream>
#include "Podaci.h"
using namespace std;

int main() {

	Podaci mijenjac;

	cout << mijenjac.to_string() << endl;

	for (int i = 0; i < 5; i++)
	{
		mijenjac.prema_gore();
		cout << mijenjac.to_string() << endl;
	}

	mijenjac.prema_dolje();
	cout << mijenjac.to_string();

	return 0;
}