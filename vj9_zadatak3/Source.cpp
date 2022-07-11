#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void load(ifstream& in, map<char, int>& znakovi)
{
	string line;
	while (getline(in, line))
	{
		for (unsigned i = 0; i < line.length(); i++)
		{
			char c = line[i];
			znakovi[c]++;
		}
	}
}

int main()
{
	ifstream in("Sifre_drzava.csv");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	map<char, int> znakovi;
	load(in, znakovi);
	in.close();

	for (auto it = znakovi.begin(); it != znakovi.end(); ++it)
	{
		cout << it->first << " ima " << it->second << endl;
	}

	return 0;
}