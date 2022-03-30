#include "Pravokutnik.h"
#include <sstream>

void Pravokutnik::set_sirina(int sirina)
{
    this->sirina = sirina;
}

void Pravokutnik::set_visina(int visina)
{
    this->visina = visina;
}

double Pravokutnik::povrsina()
{
    return visina * sirina;
}

string Pravokutnik::to_string()
{
    stringstream ss;
    ss << "P(" << sirina << ", " << visina << ") = " << povrsina();
    return ss.str();
}
