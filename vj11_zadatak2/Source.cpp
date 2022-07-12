#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void prepare_vector(vector<int>& v, unsigned n)
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void write(ofstream& out, vector<int>& v)
{
	for (auto& n : v)
	{
		out << n << endl;
	}
}

bool sort_desc(int a, int b)
{
	return a > b;
}

bool sort_even_first(int a, int b)
{
	return a % 2 == 0 && b % 2 == 1;
}

int main()
{
	ofstream asc("rastuci.txt");
	ofstream desc("padajuci.txt");
	ofstream even_odd("parni_neparni.txt");
	if (!asc || !desc || !even_odd)
	{
		cout << "Nije moguce kreirati datoteke" << endl;
		return 1;
	}

	srand(unsigned(time(nullptr)));
	vector<int> original;
	prepare_vector(original, 100);

	// a)
	vector<int> v(original);
	sort(v.begin(), v.end());
	write(asc, v);

	// b)
	v.assign(original.begin(), original.end());
	// 1. nacin
	//sort(v.rbegin(), v.rend());

	// 2. nacin - definiramo komparator
	//sort(v.begin(), v.end(), sort_desc);

	// 3. nacin - lambda
	sort(v.begin(), v.end(), [](int a, int b)
		{
			return a > b;
		});
	write(desc, v);

	// c)
	// 1. nacin - definiramo komparator
	//v.assign(original.begin(), original.end());
	//sort(v.begin(), v.end(), sort_even_first);

	// 2. nacin - lambda
	//v.assign(original.begin(), original.end());
	//sort(v.begin(), v.end(), [](int a, int b)
	//{
	//	return a % 2 == 0 && b % 2 == 1;
	//});

	// 3. nacin - stable sort - ostaviti sortirani vektor padajuce	
	stable_sort(v.begin(), v.end(), sort_even_first);
	write(even_odd, v);

	asc.close();
	desc.close();
	even_odd.close();

	return 0;
}