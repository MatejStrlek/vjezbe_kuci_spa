#include "Huron.h"
#include <string>
#include <sstream>
using namespace std;

Huron::Huron(int godina, double vodostaj)
{
    this->godina = godina;
    this->vodostaj = vodostaj;
}

double Huron::get_vodostaj()
{
    return vodostaj;
}

int Huron::get_godina()
{
    return godina;
}

string Huron::to_string()
{
    stringstream ss;

    ss << "Godina: " << godina << ", " << "Vodostaj: " << vodostaj << endl;

    return ss.str();
}
