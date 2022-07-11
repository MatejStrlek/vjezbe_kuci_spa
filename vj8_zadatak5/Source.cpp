#include <iostream>
#include <ctime>
#include <queue>
#include "Message.h"

using namespace std;

int main()
{
	priority_queue<message, vector<message>, message_comparer_desc> pq;

	pq.push(message("Kupi kruh", 2));
	pq.emplace("Pokupi punicu", 3);
	pq.emplace("Nauci raditi s hrpom", 1);
	pq.emplace("Kupi mlijeko", 1);
	pq.emplace("Nauci rjesavati diferencijalne jednadzbe", 3);

	while (!pq.empty())
	{
		cout << pq.top().to_string() << endl;
		pq.pop();
	}

	return 0;
}