#include <iostream>
#include <array>
#include <ctime>
#include <chrono>
using namespace std;

int get_random(int min, int max) {
	return (rand() % (max - min + 1) + min);
}

int main() {
	srand(time(nullptr));
	array<int, 10000> arr;
	int sum = 0, pom;

	auto begin = chrono::high_resolution_clock::now();

	for (int i = 0; i < arr.size(); i++)
	{
		pom = get_random(1, 5);
		arr.fill(pom);

		sum += pom;
	}

	cout << "Prosjek: " << (double)(sum / 10000) << endl;

	auto end = chrono::high_resolution_clock::now();

	cout << "Trajanje: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms." << endl;

	return 0;
}