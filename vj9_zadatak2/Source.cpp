#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void load(ifstream& in, map<string, string>& drzave)
{
	string line;
	string name;
	string code;
	getline(in, line);
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		getline(ss, name, ';');
		getline(ss, code);
		//drzave.insert(pair<string, string>(code, name));
		//drzave.emplace(code, name);
		drzave[code] = name;
	}
}

void search(map<string, string>& drzave)
{
	bool dalje;
	do
	{
		string code;
		cout << "Unesite sifru drzave:";
		cin >> code;

		//map<string, string>::iterator found = drzave.find(code);
		auto found = drzave.find(code);
		if (found != drzave.end()) {
			cout << found->second << endl;
		}
		else
		{
			cout << "Nema drzave s tom sifrom" << endl;
		}

		cout << "Dalje (1=da, 0=ne)? ";
		cin >> dalje;
	} while (dalje);
}

int main()
{
	ifstream in("Sifre_drzava.csv");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	map<string, string> drzave;
	load(in, drzave);
	in.close();

	search(drzave);

	return 0;
}