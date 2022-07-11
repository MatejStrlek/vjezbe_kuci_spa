#include <iostream>
#include "Client.h"
using namespace std;

int main() {

	srand(time(nullptr));

	Client c("www.bla.com");

	cout << c.get() << endl;
	cout << c.post() << endl;
	cout << c.getPort() << endl;

	return 0;
}