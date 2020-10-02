#include <iostream>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void sordi(string& sona){ // sõna sortimise meetod
   sort(sona.begin(), sona.end());
}

vector<string> loe_sisend(string failinimi, vector<string> vektor) {
	ifstream sisend(failinimi); //sisendafil
  string rida;
  if(sisend.is_open()){ // loeme sisendfailist rea haaval sõned sisse
    while(getline(sisend, rida)){
      vektor.push_back(rida); // paneme kõik sõned algul ühte vektorisse
    }
  }
	sisend.close(); // kui jõuame faili lõppu sulgeme faili
  return vektor; // tagastame saadud vektroi
}

map<string, vector<string>> pane_mappi(vector<string> vektor, map<string,vector<string>> sonede_map){
  // võtame parameetritesse vektori mis sisaldab sõnesi ning
  // map tüüpi objekti mis sisaldab võtme kohal sõnesid ja
  // väärtuste kohal on vektorid mis sisaldavad sõnesid
  for(int i = 0; i < vektor.size(); i++){ // käime saadud vektori kõik sõned ükshaaval läbi
    string sone(vektor[i]); //paneme string tüüpi muutujasse käesoleva sõne
    sordi(sone); // sordime kõik sõned
    // kontrollime kas sorteeritud sõne juba eksisteerib mapis
    if(sonede_map.find(sone) == sonede_map.end()){
      // teeme ajutise vektori väärtuse jaoks ja paneme selle koos võtmega mapi
      vector<string> ajutine;
      ajutine.push_back(vektor[i]);
      sonede_map.insert(make_pair(sone, ajutine));
    } else { // uue sõna puhul teeme ajutise vektori ja lisame sõna
            // olemasoleva mapi võtme juurde
      vector<string> ajutine(sonede_map[sone]);
      ajutine.push_back(vektor[i]);
      sonede_map[sone] = ajutine;
    }
  }
  return sonede_map; //tagastame loodud map objekti
}

void kirjuta_faili(map<string,vector<string>> sonede_map, string failinimi) {
    ofstream valjund(failinimi); //väljundfail
    for (auto& x : sonede_map) { // käime läbi kõik map võtmed ja neile vastavad väärtused
        valjund << x.first << " : "; // kõigepealt kirjutame võtme
        vector<string> ajutine(x.second); // teeme ajutise vektori et saaks mitu väärtust ühele võtmele
        for (int i = 0; i < ajutine.size(); i++) { // vaatame mitu sõne on vektoris ja kirjutame need kõik faili
          valjund << ajutine[i] << " ";
        }
        valjund << endl;
    }
    valjund.close();
}

int main() {
  map<string,vector<string>> sonede_map; // map kuhu loome registri
  vector<string> vektor; // vektor kuhu loeme sisendfailist andmed
  string sisendfail = "sonastik.txt";
  string valjundfail;
  // loeme sisendfailist andmed vektorisse
  vektor = loe_sisend(sisendfail, vektor);
  // paneme saadud vektorist andmed mapi ja leiame anagrammid
  sonede_map = pane_mappi(vektor, sonede_map);
  cout << "Sisesta fail kuhu anagrammid kirjutada. " << endl;
  cin >> valjundfail; // küsime väljundfaili kuhu anagrammid koostada
  kirjuta_faili(sonede_map,valjundfail);
  return 0;
}
