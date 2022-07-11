#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void load(ifstream& in, map<int, vector<string>>& racuni)
{
	string line;
	int id_kupca;
	string broj_racuna;
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		ss >> id_kupca >> broj_racuna;
		racuni[id_kupca].push_back(broj_racuna);
	}
}

void search(map<int, vector<string>>& racuni)
{
	bool dalje;
	int broj;
	do
	{
		int id_kupca;
		cout << "Unesite sifru kupca:";
		cin >> id_kupca;

		map<int, vector<string>>::iterator found = racuni.find(id_kupca);

		if (found != racuni.end())
		{
			cout << "Pronadjeni racuni:" << endl;
			for (auto it = found->second.begin(); it != found->second.end(); ++it)
			{
				cout << *it << " ";
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

	map<int, vector<string>> racuni;
	load(in, racuni);
	in.close();

	search(racuni);

	return 0;
}