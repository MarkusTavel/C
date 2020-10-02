#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void sordi(string& sona){ // sortimise meetod
   sort(sona.begin(), sona.end());
}

map<string, vector<string>> loe_sisend(string failinimi) {
	map<string, vector<string>> sonede_tabel; // loome map objekti kuhu anagrammid sisse lugeda
	ifstream sisend(failinimi); // sisendfail
	if (sisend.is_open()) {
		string rida;
    // loeme sisendafili rida haaval
		while (getline(sisend, rida)) {
			istringstream sonevoog(rida); // muudame rea sõnevooks
			string voti;
			string sona;
      char mark;
			vector<string> vaartus;
			sonevoog >> voti; // kõigepealt loeme sisse võtme, seda on ainult üks
      sonevoog >> mark;
			while (sonevoog >> sona) { // edasi loeme väärtused, neid võib olla mitu
				vaartus.push_back(sona); // lisaem vektorisse
			}
			sonede_tabel[voti] = vaartus; // lisame võtme mappi
		}
		sisend.close();
	}
	return sonede_tabel; // tagastame loodud mapi
}

string korrasta(string sone){
  string uus_sone = ""; // teeme uue sõne
  for(int i = 0; i < sone.length(); i++){
    // kui tegemist ei ole a-z märgiga ei lisa seda uude sõnesse
    if(sone[i] > 96 && sone[i] < 123){
        uus_sone = uus_sone + sone[i];
    }
  } // tagastame sõne kust eemaldatud üleliigsed märgid
  return uus_sone;
}

int main() {
  map<string, vector<string>> sonede_map;
  string sisendfail = "anagrammid.txt";
  sonede_map = loe_sisend(sisendfail);
  bool anagramm = false;
  bool lopeta = false;
	string otsitav; // otsitav anagramm
  do {
    anagramm = false;
    cout << "Sisestage sone (voi 0, et lopetada): ";
  	cin >> otsitav; // küsime sisendina sõne mille anagramme hakkab programm otsima
    //korrastame ja sorteerime sisendi
    if(otsitav == "0") { // kui sisend on 0 väljume tsüklist
      lopeta = true;
      break;
    }
    otsitav = korrasta(otsitav); // eemaldame kõik üleliigsed märgid sisendist
    cout << "Teie sisend: " << otsitav << endl;
    sordi(otsitav);
  	for (auto& x : sonede_map) { // otsime korrastatud sone järgi
      // kui leidub talle vastav võti väljastame väärtused vektorina
  			if(x.first == otsitav){
          anagramm = true;
          cout << "Selle anagrammid: " << endl;
  				//cout << x.first;
  				vector<string> ajutine(x.second);
  				for (int i = 0; i < ajutine.size(); i++) {
  					cout << ajutine[i] << " ";
  				}
          cout << endl;
  			}
  	}
    if(anagramm == false){
      cout << "Anagramme ei leitud!" << endl;
    }
  } while(lopeta == false);
  cout << "Ilusat päeva!";
  return 0;
}
