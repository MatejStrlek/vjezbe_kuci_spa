#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

void init(array<int, 100>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i + 1;
	}
}

bool prime(int& broj) {
	for (int i = 2; i <= broj / 2; i++) {
		if (broj % i == 0)
		{
			return false;
		}
	}
	return broj != 1;
}

void print_if_prime(int& broj) {
	if (prime(broj))
		cout << broj << endl;
}

int main() {

	array<int, 100> arr;
	init(arr);

	//reverse(arr.begin(), arr.end());
	for_each(arr.rbegin(), arr.rend(), print_if_prime);

	return 0;
}