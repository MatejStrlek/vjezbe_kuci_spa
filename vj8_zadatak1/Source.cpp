#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

vector<int> fill_numbers(unsigned n, int min, int max)
{
	srand(time(nullptr));
	vector<int> v;
	for (unsigned i = 0; i < n; i++)
	{
		v.push_back(generate_random(min, max));
	}
	return v;
}

void print(vector<int>& v)
{
	// rfor -> tab (range for)
	for (auto& n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

void insert(vector<int>& v)
{
	bool dalje;
	int n;
	do
	{
		cout << "Unesite broj: ";
		cin >> n;
		v.push_back(n);
		// svaki puta kada ubacimo element, moramo ga smjestiti na pravo mjesto
		// reheapification upward:
		push_heap(v.begin(), v.end());
		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);
}

int main()
{
	vector<int> numbers = fill_numbers(10, 1, 100);

	cout << "vektor: ";
	print(numbers);

	// kreiranje heap-a organizacije unutar vektora:
	make_heap(numbers.begin(), numbers.end());
	cout << "vektor kao hrpa: ";
	print(numbers);

	insert(numbers);
	cout << "vektor nakon inserta: ";
	print(numbers);

	while (!numbers.empty())
	{
		cout << numbers.front() << " - ";
		// prvo moramo element staviti na kraj
		// reheapification downard:
		pop_heap(numbers.begin(), numbers.end());
		// sada ga mozemo izbaciti
		numbers.pop_back();
		print(numbers);
	}

	return 0;
}