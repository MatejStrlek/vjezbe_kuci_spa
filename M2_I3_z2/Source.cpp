#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int rand_nesto(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void ubaci(vector<int>& v) {

	for (int i = 0; i < 10; i++)
		v.push_back(rand_nesto(1, 100));
}

void asc(vector<int>& v) {

	for_each(v.begin(), v.end(), [&](int a) {
		cout << a << endl;
		});
}

void desc(vector<int>& v) {

	for_each(v.rbegin(), v.rend(), [&](int a) {
		cout << a << endl;
		});
}

int main() {

	srand(time(nullptr));
	vector<int> v;

	ubaci(v);

	int odabir;

	cout << "Zelite li DESC ili ASC? (1 - DESC, 2 - ASC)" << endl;
	cin >> odabir;

	make_heap(v.begin(), v.end());

	if (odabir == 1)
		asc(v);
	else
		desc(v);


	return 0;
}