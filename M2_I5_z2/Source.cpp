#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fill_shuffle(vector<int>& v) {

	for (size_t i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

bool parni(int a, int b) {
	return a % 2 == 0 && b % 2 != 0;
}

int main() {

	vector<int> v;

	fill_shuffle(v);

	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int a) {
		cout << a << endl;
		});

	cout << endl;

	sort(v.rbegin(), v.rend());

	for_each(v.begin(), v.end(), [](int a) {
		cout << a << endl;
		});

	cout << endl;

	stable_sort(v.begin(), v.end(), parni);

	for_each(v.begin(), v.end(), [](int a) {
		cout << a << endl;
		});

	return 0;
}