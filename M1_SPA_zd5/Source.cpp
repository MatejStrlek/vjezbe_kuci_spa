#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void print(int& n) {
	cout << n << " ";
}

void load(ifstream& in, vector<int>& v) {
	int n;

	while (in >> n)
	{
		v.push_back(n);
	}

}

int main() {

	ifstream in("brojevi.txt");
	vector<int> v;

	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}

	load(in, v);
	in.close();

	for_each(v.begin(), v.end(), [&](int n) {
		cout << n << " ";
		});
	cout << endl;

	list<int> l(v.begin(), v.end());

	int multipiler = 3;
	for_each(l.begin(), l.end(), [&multipiler](int& n) {
		n *= multipiler;
		});

	for_each(l.begin(), l.end(), print);

	return 0;
}