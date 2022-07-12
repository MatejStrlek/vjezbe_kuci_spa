#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

void load(ifstream& in, vector<string>& v)
{
	string ime;
	while (getline(in, ime))
	{
		v.push_back(ime);
	}
}

void print(vector<string>& v)
{
	for (auto& s : v)
	{
		cout << s << endl;
	}
}

bool sort_by_length(string a, string b)
{
	return a.length() < b.length();
}

int main()
{
	ifstream in("osobe.txt");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<string> v;
	load(in, v);
	in.close();

	stable_sort(v.begin(), v.end(), sort_by_length);

	print(v);

	return 0;
}