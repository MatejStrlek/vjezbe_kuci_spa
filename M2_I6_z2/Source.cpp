#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
T convert(string& s) {
	stringstream c(s);
	T t;
	c >> t;
	return t;
}

void load(ifstream& in, unordered_multimap<string, int>& um) {

	string line, temp;
	string name;
	while (getline(in, line))
	{
		//Emily,F,25055
		stringstream ss(line);
		//Emily
		getline(ss, name, ',');
		//F
		getline(ss, temp, ',');
		//25055
		getline(ss, temp);
		int number = convert<int>(temp);

		um.emplace(name, number);
	}
}

int main() {

	unordered_multimap<string, int> um;
	ifstream in("yob2001.txt");

	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}

	load(in, um);
	in.close();

	for (auto it = um.begin(); it != um.end(); ++it)
	{
		cout << "Ime: " << it->first << ", broj: " << it->second << endl;
	}

	return 0;
}
