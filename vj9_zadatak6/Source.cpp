#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void load(ifstream& in, multimap<int, string>& racuni)
{
	string line;
	int id_kupca;
	string broj_racuna;
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		ss >> id_kupca >> broj_racuna;
		//racuni.insert(pair<int, string>(id_kupca, broj_racuna));
		racuni.emplace(id_kupca, broj_racuna);
		//racuni[id_kupca] = broj_racuna; // ovo ne radi na multimapi jer imamo visestruke kljuceve!
	}
}

void search(multimap<int, string>& racuni)
{
	bool dalje;
	do
	{
		int id_kupca;
		cout << "Unesite sifru kupca:";
		cin >> id_kupca;

		//pair<multimap<int, string>::iterator, multimap<int, string>::iterator> found = racuni.equal_range(id_kupca);
		auto found = racuni.equal_range(id_kupca);

		if (found.first != found.second)
		{
			cout << "Pronadjeni racuni:" << endl;
			for (auto it = found.first; it != found.second; ++it)
			{
				cout << it->second << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "Nema racuna za trazenog kupca" << endl;
		}

		cout << "Dalje (1=da, 0=ne)? ";
		cin >> dalje;
	} while (dalje);
}

int main()
{
	ifstream in("Racuni.csv");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	multimap<int, string> racuni;
	load(in, racuni);
	in.close();

	search(racuni);

	return 0;
}
