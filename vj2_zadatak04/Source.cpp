#include <iostream>
#include "Pravokutnik.h"
using namespace std;

int main() {


	try
	{
		Pravokutnik p(5, 7);
		cout << p.oblik('*', '-', true);
		cout << endl;
		cout << p.oblik('^', '#', false);
	}
	catch (const exception& e)
	{
		cout << "Greska: " << e.what() << endl;
	}

	return 0;
}