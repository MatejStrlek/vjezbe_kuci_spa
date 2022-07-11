#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

void flush(queue<int>& q, ofstream& out) {
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void copy(ifstream& in, ofstream& out)
{
	queue<int> q;
	int n;
	while (in >> n) {
		q.push(n);
		if (q.size() == 5) {
			flush(q, out);
		}
	}
	flush(q, out);
}

int main() {

	ifstream in("brojevi.txt");
	ofstream out("out.txt");

	if (!in) {
		cout << "Greska!" << endl;
		return 1;
	}

	copy(in, out);

	in.close();
	out.close();
	return 0;
}