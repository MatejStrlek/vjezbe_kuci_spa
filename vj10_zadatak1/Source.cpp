#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_sorted_ascending(vector<int>& v)
{
	for (unsigned i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			return false;
		}
	}
	return true;
}

void print(vector<int>& v)
{
	for (auto& n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v{ 9, 8, 1, 3, 6, 2, 4, 10, 5, 7 };

	// 1. nacin - vlastita funkcija za provjeru je li vektor sortiran rastuce
	//while (!is_sorted_ascending(v)) 
	//{
	//	next_permutation(v.begin(), v.end());
	//}

	// 2. nacin - ugradjena funkcija za provjeru je li vektor sortiran rastuce
	//while (!is_sorted(v.begin(), v.end())) {
	//	next_permutation(v.begin(), v.end());
	//}

	// 3.nacin - next_permutation:
	//	Vraca true ako postoji veca leksikografska permutacija
	//		Najveca leksikografska permutacija su elementi sortirani padajuce
	//	Inace vraca false i elemente preslaguje u najmanju permutaciju
	//		Najmanja leksikografska permutacija su element sortirani rastuce
	while (next_permutation(v.begin(), v.end()));
	print(v);

	// dodatak - prev_permutation - inverzna logika
	while (prev_permutation(v.begin(), v.end()));
	print(v);

	return 0;
}