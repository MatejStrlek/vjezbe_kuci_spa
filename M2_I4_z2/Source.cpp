#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void load(ifstream& in, map<char, int>& m)
{
	string line;
	while (getline(in, line))
	{
		for (int16_t i = 0; i < line.length(); i++)
		{
			char c = line[i];
			m[c]++;
		}
	}
}

int main() {
	map<char, int> m;
	ifstream in("Sifre_drzava.csv");
	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}
	load(in, m);
	in.close();

	for (auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << " : " << it->second << endl;

	return 0;
}