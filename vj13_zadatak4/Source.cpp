#include <iostream>
#include <string>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(nullptr));
	unordered_set<string> set;
	string s = "abcdefghi";
	int coll = 0;
	for (int i = 1; i <= 1000; i++)
	{
		random_shuffle(s.begin(), s.end());
		//pair<unordered_set<string>::iterator, bool> retval = set.insert(s);
		auto retval = set.insert(s);
		if (!retval.second)
		{
			cout << "iteracija: " << i << ",  broj kolizija: " << ++coll << endl;
		}
	}

	return 0;
}