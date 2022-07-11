#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	// Dodajte u set brojeve od 1 do 10
	// 1. nacin - default konstruktor i insert
	//set<int> s;
	//for (int i = 1; i <= 10; i++)
	//{
	//	s.insert(i);
	//}
	// 2. nacin - default konstruktor i insert sa inicijalizacijskom listom
	//set<int> s;
	//s.insert({ 2, 1, 8, 3, 4, 5, 7, 6, 10, 9, 10, 10 });
	// 3. nacin - konstruktor sa inicijalizacijskom listom
	set<int> s({ 2, 1, 8, 3, 4, 5, 7, 6, 10, 9, 10, 10 });

	// Ispisite sve od pocetka do kraja - jedinstveni i poredani!
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// Uklonite broj 7, dodajte 17 pa ispisite od kraja do pocetka
	// brisanje vraca broj obrisanih
	cout << "broj obrisanih 7: " << s.erase(7) << endl;

	// ubacivanje vraca pair<iterator, bool>:
	//	- first (iterator) pokazuje na element, 
	//	- second(bool) govori da li je ubacen ili je vec bio unutra 
	//pair<set<int>::iterator, bool> result = s.insert(17); 
	// ali jednostavnije nam je koristiti auto:
	auto result = s.insert(17); // probati sa 1
	cout << "broj " << *result.first << " je ubacen: " << result.second << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// Prepisite svaki broj dva puta u multiset
	multiset<int> ms;
	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		ms.insert(*it);
		ms.insert(*it);
	}

	// Ispisite sve elemente multiseta
	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// Prepisite sve iz multiseta u mapu
	// kljuc neka bude broj, a vrijednost kvadrat broja
	map<int, int> m;
	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		// 1. nacin - eksplicitno
		//int element = *it;
		//m.insert(pair<int, int>(element, element * element));
		// ili 
		//m.emplace(element, element * element);
		// 2. nacin - indexer
		//int element = *it;
		//m[element] = element * element;
		// 3. nacin - implicitno 
		m[*it] = *it * *it;
	}

	// Ispisite sve kljuceve i pokraj svakog vrijednost u zagradi  - jedinstveni kljucevi!
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " (" << it->second << ")" << " ";
	}
	cout << endl;

	// Prepisite sve u multimap u obrnutom redoslijedu
	multimap<int, int> mm;
	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{
		// 1. nacin - eksplicitno
		//mm.insert(pair<int, int>(it->first, it->second));
		// 2. nacin - implicitno
		mm.insert(*it);
	}

	// Ispisite sve kljuceve i pokraj svakog vrijednost u zagradi 
	//	- obzirom da koristi binarno stablo trazenja, zadrzava se originalni ordering elemenata, 
	//	 bez obzira na nacin unosa (unijeli smo obrnutim redoslijedom)
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " (" << it->second << ")" << " ";
	}
	cout << endl;

	return 0;
}