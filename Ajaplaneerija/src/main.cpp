/**
 * Algoritmid ja andmestruktuurid (NTR0390)
 * Tallinna Tehnikaülikooli Tartu Kolledž
 * Kodutöö 04: Ajaplaneerija
 * Põhiprogramm
 * MARKUS TAVEL
 */

#include "Kellaaeg.hpp"
#include "Kuupaev.hpp"
#include "Aeg.hpp"
#include "Uritus.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int loe_taisarv() {
	char valik;
	bool vale_sisend;
	do {
		vale_sisend = false;
		cout << "Palun sisesta oma valik." <<endl;
		cin >> valik;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (valik > '2' || valik < '0') {
			vale_sisend = true;
			cout << "Sellist valikut pole" << endl;
		}
	} while (vale_sisend);
	int arv = valik - 48;
	return arv;
}

void kuvaMenuu() {
	cout << "  1. Vaata uritusi" << endl;
	cout << "  2. Lisa uritus" << endl;
	cout << "  0. Lopeta" << endl << endl;
}

void loe_sisend(string failinimi, Uritus uritus[100]) {
	ifstream sisend(failinimi);
	for (int i = 0; i < 100; i++){
    sisend >> uritus[i];
	}
	sisend.close();
}

void vaataUritusi(){
	Uritus uritus[100]; Uritus kogus;
	int hulk = 0;
	string sisendfail = "uritused.txt";
	loe_sisend(sisendfail, uritus);
	for(int i = 0; i < 100; i++){
		if(uritus[i] != kogus){
			hulk++;
		}
	}
  for(int i = 0; i < hulk ;i++){
    cout << uritus[i] << endl;
  }
	return;
}

void kirjuta_faili(string failinimi, Uritus uritus) {
	ofstream valjund(failinimi, ios::app);
  valjund << uritus << endl;
	valjund.close();
}

void lisaUritus(){
	Uritus lisatavuritus; string valjundfail = "uritused.txt";
	Uritus uritus[100];
	string sisendfail = "uritused.txt";
	bool vale_sisend;
	do {
		vale_sisend = false;
		cout << "Sisesta urituse algus-lopp aeg ja nimi kujul 'DD:MM:YYYY TT:MM' 'DD:MM:YYYY TT:MM' nimi " <<endl;
		cin >> lisatavuritus;
		if (cin.fail()) {
			cout << "Viga! Uritust ei saanud sisse lugeda." << endl;
			vale_sisend = true;
			cin.clear();
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		loe_sisend(sisendfail, uritus);
		for(int i = 0; i < 100; i++){
				if(lisatavuritus == uritus[i]){
					cout << "Sellel ajal juba toimub uritus" << endl;
					vale_sisend = true;
					break;
				}
		}
	} while (vale_sisend);
	kirjuta_faili(valjundfail, lisatavuritus);
	cout << lisatavuritus << endl;
	cout << "On lisatud nimekirja" <<endl;
	return;
}

void tegutse(int valik) {
	switch (valik) {
		case 1:
			vaataUritusi();
			break;
		case 2:
			lisaUritus();
			break;
	}
}

void kaivita() {
	unsigned int valik;
	do {
		kuvaMenuu();
		valik = loe_taisarv();
		if (valik != 0) tegutse(valik);
	} while (valik != 0);
	cout << "Ilusat paeva jatku!" << endl;
}


int main() {
kaivita();
return 0;
}
