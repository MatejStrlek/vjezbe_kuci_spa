#include <iostream>
#include "insertion_sort.h"
#include "tocka.h"

using namespace std;

int main()
{
	tocka tocke[] =
	{
		tocka(5, 0),
		tocka(0, 5),
		tocka(10, 10),
		tocka(5, 5),
		tocka(4, 7)
	};

	int size = sizeof(tocke) / sizeof(tocka);
	insertion_sort(tocke, size);

	for (int i = 0; i < size; i++)
	{
		cout
			<< tocke[i].x << ", "
			<< tocke[i].y
			<< " (D=" << tocke[i].distance() << ")"
			<< endl;
	}

	return 0;
}