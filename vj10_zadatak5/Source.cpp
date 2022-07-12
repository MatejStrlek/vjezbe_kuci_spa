#include <iostream>
#include <fstream>
#include "selection_sort.h"
#include "pravokutnik.h"

using namespace std;

void load(ifstream& in, pravokutnik* pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++) {
		in >> pravokutnici[i].a >> pravokutnici[i].b;
	}
}

void print(ofstream& out, pravokutnik* pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		out << pravokutnici[i].a << " " << pravokutnici[i].b << endl;
	}
}

int main()
{
	ifstream in("pravokutnici.txt");
	ofstream out("pravokutnici_sortirano.txt");
	if (!in || !out)
	{
		cout << "Greska pri pristupu datotekama" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 1000;

	pravokutnik* pravokutnici = new pravokutnik[BROJ_ELEMENATA];
	load(in, pravokutnici, BROJ_ELEMENATA);
	in.close();

	selection_sort(pravokutnici, BROJ_ELEMENATA);
	print(out, pravokutnici, BROJ_ELEMENATA);

	out.close();
	delete[] pravokutnici;

	return 0;
}