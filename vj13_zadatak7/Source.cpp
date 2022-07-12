#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;

void load(ifstream& in, unordered_set<string>& s)
{
	string line;
	string key;
	while (getline(in, line))
	{
		stringstream ss(line);
		getline(ss, key, ',');
		s.insert(key);
	}
}

void print_nonexistent(ifstream& in, unordered_set<string>& s)
{
	int n = 0;
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		string key;
		getline(ss, key, ',');
		if (s.find(key) == s.end())
		{
			cout << ++n << ": " << key << endl;
		}
	}
}

int main()
{
	ifstream in1("yob2001.txt");
	ifstream in2("yob1901.txt");
	if (!in1 || !in2)
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
	}

	unordered_set<string> s;
	load(in1, s);
	in1.close();
	print_nonexistent(in2, s);
	in2.close();

	return 0;
}