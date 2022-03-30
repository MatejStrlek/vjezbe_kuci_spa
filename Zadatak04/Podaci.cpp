#include "Podaci.h"
#include <sstream>

Podaci::Podaci() {
	stanje = 0;
}

void Podaci::prema_gore()
{
    if (stanje < 5) stanje++;
}

void Podaci::prema_dolje()
{
    if (stanje > 0) stanje--;
}

string Podaci::to_string()
{
	switch (stanje)
	{
	case 0: 
		return "zzz";
		break;
	case 1:
		return "R";
	case 2:
		return "Rr";
	case 3:
		return "Rrr";
	case 4:
		return "Brrrm";
	case 5:
		return "Brrrrrrrrrrrrrrrrrm!";
	}
}
