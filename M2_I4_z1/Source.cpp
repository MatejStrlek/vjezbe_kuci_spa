#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

void load(ifstream& in, map<string, string>& m) {
	string value, key, line;

	getline(in, line);
	while (getline(in, line))
	{
		stringstream ss(line);
		getline(ss, value, ';');
		getline(ss, key);
		m[key] = value;	
	}
}

void search(map<string, string>& m) {
	string key;
	cout << "Upisite sifru drzave: ";
	getline(cin, key);

	map<string, string>::iterator result = m.find(key);

	if (result != m.end()) {
		cout << result->second << endl;
	}
	else {
		cout << "Nema te sifre drzave."<<endl;
	}
}

int main() {

	map<string, string> m;
	ifstream in("Sifre_drzava.csv");

	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}
	load(in, m);
	in.close();

	search(m);

	return 0;
}