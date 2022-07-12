#include <iostream>
#include <fstream>
#include <chrono>
#include "shell_sort.h"
using namespace std;

void load(ifstream& in, int* brojevi, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		in >> brojevi[i];
	}
}

void sort_shell(int* radno_polje, const int BROJ_ELEMENATA)
{
	auto begin = chrono::high_resolution_clock::now();
	shell_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Shell sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}


int main()
{
	ifstream in("puno_brojeva1.txt");
	if (!in)
	{
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}

	const int BROJ_ELEMENATA = 100000;
	int* brojevi = new int[BROJ_ELEMENATA];
	load(in, brojevi, BROJ_ELEMENATA);
	in.close();

	sort_shell(brojevi, BROJ_ELEMENATA);

	delete[] brojevi;

	return 0;
}