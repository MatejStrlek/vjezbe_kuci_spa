#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> set;
	int current = 1;
	int limit = 20;
	bool dalje;
	do
	{
		while (current <= limit)
		{
			set.insert(current++);
		}
		limit += 20;

		for (unsigned i = 0; i < set.bucket_count(); i++)
		{
			cout << "Bucket: " << i << ": " << set.bucket_size(i) << " elemenata" << endl;
		}

		cout << "Broj elemenata: " << set.size() << endl;
		cout << "Broj bucketa: " << set.bucket_count() << endl;

		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
		system("cls");

	} while (dalje);

	return 0;
}