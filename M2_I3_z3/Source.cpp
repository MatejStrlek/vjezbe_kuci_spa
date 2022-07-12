#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
using namespace std;

struct compare_desc
{
	bool operator() (int i1, int i2)
	{
		return i1 > i2;
	}
};

struct compare_asc
{
	bool operator() (int i1, int i2)
	{
		return i1 < i2;
	}
};

int rand_nesto(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void ubaci(vector<int>& v) {

	for (int i = 0; i < 10; i++)
		v.push_back(rand_nesto(1, 100));
}

void asc(priority_queue<int, vector<int>, compare_asc>& pq) {

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

void desc(priority_queue<int, vector<int>, compare_desc>& pq) {

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

int main() {

	srand(time(nullptr));
	vector<int> v;

	ubaci(v);
	priority_queue<int, vector<int>, compare_asc> pq(v.begin(), v.end()); //ili greater<int>
	priority_queue<int, vector<int>, compare_desc> pq2(v.begin(), v.end()); //ili less<int>

	int odabir;

	cout << "Zelite li DESC ili ASC? (1 - DESC, 2 - ASC)" << endl;
	cin >> odabir;

	if (odabir == 1)
		asc(pq);
	else
		desc(pq2);

	return 0;
}