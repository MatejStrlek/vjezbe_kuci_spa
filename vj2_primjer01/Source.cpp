#include <iostream>
using namespace std;

int multiply(int a, int b) {
	return a * b;
}

double devide(int a, int b) {
	if (b == 0) {
		throw exception("Nemozes dijeliti sa 0!");
	}

	return a / b;
}

double korijen(int a) {
	if (a < 0) {
		throw runtime_error("Nemozes korijenovat sa negativnim brojem!");
	}

	return sqrt(a);
}

int main() {
	int a, b;

	cout << "Upisi a:";
	cin >> a;

	cout << "Upisi b:";
	cin >> b;

	cout << a << " * " << b << " = " << multiply(a, b) << endl;

	try
	{
		cout << a << " / " << b << " = " << devide(a, b) << endl;
		cout << "sqrt( " << a << " ) = " << korijen(a) << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}