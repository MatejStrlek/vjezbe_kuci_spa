#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

void load(ifstream& in, unordered_map<string, int>& m)
{
	string line;
	string key;
	string gender;
	int value;
	while (getline(in, line))
	{
		stringstream ss(line);
		getline(ss, key, ',');

		getline(ss, gender, ',');

		ss >> value;
		m[key] += value;
	}
}

void write(ofstream& out, unordered_map<string, int>& m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << ", " << it->second << endl;
	}
}


int main()
{
	ifstream in1("yob1901.txt");
	ifstream in2("yob2001.txt");
	ofstream out("yobSuma.txt");
	if (!in1 || !in2 || !out)
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
	}

	unordered_map<string, int> m;
	load(in1, m);
	load(in2, m);
	in1.close();
	in2.close();

	write(out, m);
	out.close();

	return 0;
}