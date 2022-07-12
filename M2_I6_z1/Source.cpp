#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

	unordered_multiset<int> ums;
	bool odabir;

	do
	{
		for (size_t i = 1; i <= 22; i++)
		{
			ums.insert(i);
		}
		for (size_t i = 0; i < ums.bucket_count(); i++)
		{
			cout << i << ": " << ums.bucket_size(i) << endl;
		}

		cout << "Broj bucketa: " << ums.bucket_count() << endl;
		cout << "Broj elemenata: " << ums.size() << endl;

		cout << "Zelite li nastaviti?(1 - DA, 0 - NE)" << endl;
		cin >> odabir;
	} while (odabir);

	return 0;
}