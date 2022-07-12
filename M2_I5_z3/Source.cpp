#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void load(ifstream& in, vector<string>& v) {
	string line;
	while (in >> line) {
		v.push_back(line);
	}
}

bool size_rijeci(string a, string b) {

	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() > b.length();
}

int main() {
	vector<string> v;
	ifstream in("osobe.txt");
	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}
	load(in, v);
	in.close();

	sort(v.begin(), v.end(), size_rijeci);

	for_each(v.begin(), v.end(), [](string name) {
		cout << name << endl;
		});

	return 0;
}