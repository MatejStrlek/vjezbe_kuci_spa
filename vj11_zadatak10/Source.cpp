#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void load(ifstream& in, vector<int>& v)
{
	int n;
	while (in >> n)
	{
		v.push_back(n);
	}
}

void search(vector<int>& v)
{
	bool dalje;
	int upit;
	do
	{
		cout << "Upisite broj koji zelite traziti: ";
		cin >> upit;

		if (binary_search(v.begin(), v.end(), upit))
		{
			cout << "Broj " << upit << " postoji" << endl;
		}
		else
		{
			cout << "Broj " << upit << " ne postoji" << endl;
		}

		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);
}

int main()
{
	ifstream in("puno_malih_brojeva1.txt");
	if (!in)
	{
		cout << "Greska pri otvaranju datoteka" << endl;
		return 1;
	}

	vector<int> v;
	load(in, v);
	in.close();

	// kolekcija mora biti sortirana prije koristenja binary_search-a!
	sort(v.begin(), v.end());

	search(v);

	return 0;
}