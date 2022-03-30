#include <iostream>
#include <fstream>
#include "Pravokutnik.h"
using namespace std;

void input(Pravokutnik pravokutnici[]) {

	for (int i = 0; i < 5; i++)
	{
		cout << "Unos " << i + 1 << ". pravokutnika: " << endl;

		double sirina;
		cout << "sirina: ";
		cin >> sirina;
		pravokutnici[i].set_sirina(sirina);

		double visina;
		cout << "visina: ";
		cin >> visina;
		pravokutnici[i].set_visina(visina);
	}
}

void output(Pravokutnik pravokutnici[], ofstream &fout) {

	for (int i = 0; i < 5; i++)
	{
		cout << pravokutnici[i].to_string() << endl;
	}
}

int main() {

	Pravokutnik pravokutnici[5];

	input(pravokutnici);

	ofstream fout("pravokutnici.txt");

	if (!fout) {
		cout << "Nije moguce kreirati datoteku!" << endl;
		return 1;
	}

	output(pravokutnici, fout);

	fout.close();

	return 0;
}