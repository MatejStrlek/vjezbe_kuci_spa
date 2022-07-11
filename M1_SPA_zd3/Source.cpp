#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Huron.h";
using namespace std;

template <typename T>
T convert(string temp) {
	stringstream ss(temp);

	T a;

	ss >> a;

	return a;
}

void load_data(ifstream& in, vector<Huron>& v) {

	string line, temp;
	int god;
	double vodostaj;
	getline(in, line);

	while (getline(in, line))
	{
		getline(in, temp, ',');

		getline(in, temp, ',');
		god = convert<int>(temp);

		getline(in, temp);
		vodostaj = convert<double>(temp);

		v.emplace_back(god, vodostaj);
	}

}

int main() {

	ifstream in("LakeHuron.csv");
	vector<Huron> v;
	
	if (!in) {
		cout << "Error!" << endl;
		return 1;
	}

	load_data(in, v);

	in.close();

	/*for_each(v.begin(), v.end(), [&](Huron h) {
		cout <<h.to_string() << endl;
		});*/

	int god = 0;
	double vodostaj_max = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).get_vodostaj() > vodostaj_max) {
			vodostaj_max = v[i].get_vodostaj();
			god = v[i].get_godina();
		}
	}

	cout << "Najvisi vodostaj je bio " << god << " godine, iznosio je " << vodostaj_max << endl;

	return 0;
}