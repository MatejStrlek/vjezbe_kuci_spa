#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insert(int limit, vector<int>& v, set<int>& s, multiset<int>& ms, map<int, int>& m, multimap<int, int>& mm)
{
	for (unsigned i = 1; i <= limit; i++)
	{
		v.push_back(i);
		s.insert(i);
		ms.insert(i);
		m[i] = i;
		mm.emplace(i, i);
	}
}
void measure(int n, vector<int>& v) {
	auto begin = high_resolution_clock::now();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (*it == n) {
			cout << "Pronadjen u vektoru" << endl;
			break;
		}
	}
	auto end = high_resolution_clock::now();
	cout << "Vector: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}
void measure(int n, set<int>& s) {
	auto begin = high_resolution_clock::now();
	if (s.find(n) != s.end()) {
		cout << "Pronadjen u setu" << endl;
	}
	auto end = high_resolution_clock::now();
	cout << "Set: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}
void measure(int n, multiset<int>& ms) {
	auto begin = high_resolution_clock::now();
	if (ms.find(n) != ms.end()) {
		cout << "Pronadjen u multisetu" << endl;
	}
	auto end = high_resolution_clock::now();
	cout << "Mulitset: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}
void measure(int n, map<int, int>& m) {
	auto begin = high_resolution_clock::now();
	if (m.find(n) != m.end()) {
		cout << "Pronadjen u mapi" << endl;
	}
	auto end = high_resolution_clock::now();
	cout << "Map: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}
void measure(int n, multimap<int, int>& mm) {
	auto begin = high_resolution_clock::now();
	if (mm.find(n) != mm.end()) {
		cout << "Pronadjen u multimapi" << endl;
	}
	auto end = high_resolution_clock::now();
	cout << "Multimap: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}

int main()
{
	int limit = 100000;
	vector<int> v;
	set<int> s;
	multiset<int> ms;
	map<int, int> m;
	multimap<int, int> mm;

	insert(limit, v, s, ms, m, mm);

	int n = 100000;
	//preopterecenje funkcija (function overload) - jednako ime, razliciti parametri
	measure(n, v);
	measure(n, s);
	measure(n, ms);
	measure(n, m);
	measure(n, mm);

	return 0;
}
