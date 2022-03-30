#include <iostream>
#include "Lampa.h";
using namespace std;

int main() {

	Lampa lampa1;
	lampa1.set_model("Najjaci");
	lampa1.set_proizvodjac("Ikea");
	lampa1.set_broj_sijalica(50);
	lampa1.set_snaga_sijalica(50);

	cout << lampa1.to_string() << endl;

	Lampa lampa2("Spansko");
	lampa2.set_proizvodjac("Lidl");
	lampa2.set_broj_sijalica(40);
	lampa2.set_snaga_sijalica(30);

	cout << lampa2.to_string() << endl;

	return 0;
}