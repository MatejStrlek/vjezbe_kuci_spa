#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int menu()
{
	system("cls");
	cout << "1 = otvaranje racuna" << endl;
	cout << "2 = stavljanje na racun" << endl;
	cout << "3 = skidanje s racuna" << endl;
	cout << "4 = ispis stanja pojedinog racuna" << endl;
	cout << "5 = ispis stanja svih racuna" << endl;
	cout << "6 = izlaz" << endl;
	int n;
	cout << "Odaberite opciju: ";
	cin >> n;
	cin.ignore();
	return n;
}

void open_account(unordered_map<string, double>& bank)
{
	string account_nr;
	cout << "Unesite broj racuna:";
	getline(cin, account_nr);
	if (bank.find(account_nr) != bank.end()) {
		cout << "Broj racuna vec postoji" << endl;
		return;
	}
	//bank.insert({ account_nr, 0 });
	bank[account_nr] = 0;
	cout << "Uspjesno kreiran racun." << endl;
}

void deposit(unordered_map<string, double>& bank)
{
	string account_nr;
	cout << "Unesite broj racuna:";
	getline(cin, account_nr);
	if (bank.find(account_nr) == bank.end()) {
		cout << "Broj racuna ne postoji" << endl;
		return;
	}
	double amount;
	cout << "Unesite iznos za staviti: ";
	cin >> amount;
	cin.ignore();
	bank[account_nr] += amount;
}

void withdraw(unordered_map<string, double>& bank)
{
	string account_nr;
	cout << "Unesite broj racuna:";
	getline(cin, account_nr);
	if (bank.find(account_nr) == bank.end()) {
		cout << "Broj racuna ne postoji" << endl;
		return;
	}
	double amount;
	cout << "Unesite iznos za skinuti: ";
	cin >> amount;
	cin.ignore();
	bank[account_nr] -= amount;
}

void print_account(unordered_map<string, double>& bank)
{
	string account_nr;
	cout << "Unesite broj racuna:";
	getline(cin, account_nr);
	if (bank.find(account_nr) == bank.end()) {
		cout << "Broj racuna ne postoji" << endl;
		return;
	}
	cout << "Stanje racuna: " << bank[account_nr] << endl;
}

void print_accounts(unordered_map<string, double>& bank)
{
	for (auto it = bank.begin(); it != bank.end(); ++it)
	{
		cout << "Stanje racuna - " << it->first << ": " << it->second << endl;
	}
}

int main()
{
	unordered_map<string, double> bank;
	int choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			open_account(bank);
			break;
		case 2:
			deposit(bank);
			break;
		case 3:
			withdraw(bank);
			break;
		case 4:
			print_account(bank);
			break;
		case 5:
			print_accounts(bank);
			break;
		}
		cout << "Pritisnite enter za nastavak";
		cin.ignore();
	} while (choice != 6);

	return 0;
}