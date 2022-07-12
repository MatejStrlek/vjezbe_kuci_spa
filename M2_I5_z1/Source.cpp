#include <iostream>
#include <fstream>
#include "pravokutnik.h"
#include "merge_sort.h"
using namespace std;

void load(ifstream& in, pravokutnik* pravokutnici) {

	for (int i = 0; i < 1000; i++) {
		in >> pravokutnici[i].a >> pravokutnici[i].b;
	}
}

void print(pravokutnik* pravokutnici) {
	for (int i = 0; i < 1000; i++) {
		cout << pravokutnici[i].a << ", " << pravokutnici[i].b << ", povrsina: " << pravokutnici[i].povrsina() << endl;
	}
}

int main() {

	ifstream in("pravokutnici.txt");
	if (!in)
	{
		cout << "Greska!"
			<< endl;
		return 1;
	}

	pravokutnik* pravokutnici = new pravokutnik[1000];
	load(in, pravokutnici);

	merge_sort(, 1000);
	print(pravokutnici);

	in.close();
	delete[] pravokutnici;

	return 0;
}