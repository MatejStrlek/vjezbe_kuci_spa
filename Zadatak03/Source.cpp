#include <iostream>
#include "Razlomak.h"
using namespace std;

int main() {

	char nastavak;

	do {

		int brojnik;
		cout << "Unesite brojnik: ";
		cin >> brojnik;
		int nazivnik;
		cout << "Unesite nazivnik: ";
		cin >> nazivnik;

		Razlomak r(brojnik, nazivnik);

		int skalar;
		cout << "Unesite skalar:";
		cin >> skalar;

		cout << r.to_string() << " * " << skalar << " = ";
		r.multiply(skalar);
		cout << r.to_string() << endl;

		cout << "Zelite li nastaviti dalje (DA - D, NE - N): ";
		cin >> nastavak;

	} while (nastavak == 'D' || nastavak == 'd');

	return 0;
}