#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

bool check(ifstream& in) {
	stack<char> s;
	string line;

	while (getline(in, line))
	{
		for (size_t i = 0; i < line.length(); i++)
		{
			char c = line[i];

			if (c == '(' || c == '{' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (s.empty() && c != '(') {
					return false;
				}
				s.pop();
			}
			else if (c == '}') {
				if (s.empty() && c != '{') {
					return false;
				}
				s.pop();
			}
			else if (c == ']') {
				if (s.empty() && c != '[') {
					return false;
				}
				s.pop();
			}
		}
	}
	return s.empty();
}

int main() {

	ifstream in("proba3.txt");

	if (!in)
	{
		cout << "Greska!" << endl;
		return 1;
	}
	
	if (check(in)) {
		cout << "Uspjesno" << endl;
	}
	else {
		cout << "Greska" << endl;
	}

	in.close();
	return 0;
}