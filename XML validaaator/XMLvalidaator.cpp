#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main() {
  cout << "Sisesta failinimi: ";
  string failinimi;
  cin >> failinimi;
  int rea_number;
  int veeru_number;
  string rida; string silt = "";
  bool kas_loeme_sildi_nime = false;
  bool kas_loeme_sisu = false;
  bool kas_on_alustav_silt = true;
  bool kas_on_ise_sulguv_silt = false;
  bool kas_on_atribuut = false; // kas tegemist on atribuudiga
  bool kas_on_atribuudi_nimi = true; // kas tegemist on atribuudi nimega
  bool atribuudi_vaartus = false; // väärtus
  bool atribuudi_vaartus2 = false; // abi muutuja väärtusele
  bool atribuut_labi = false; // kas atribuut on läbi
  bool kas_on_pais = false; // kontrollime kas tegu on päisega
  bool paise_lopp = false; // lisa kontroll päise lõpu jaoks, et kas enne lopetavat noolt ka küsimärk
  int loendur = 0; // loendame mitu päist on failil
  stack<string> sildid;
// Avame faili ja loendame selle reanumbreid
  ifstream sisend(failinimi);
  if (sisend.is_open()) {
	   rea_number = 0;
	   while (getline(sisend, rida)) {
		     rea_number++;
		     //cout << rea_number << ": " << rida << endl;
         for(int i = 0; i < rida.length(); i++){
           if(kas_loeme_sisu == false){
             if(rida[i] == '<'){ //kui on alustav nool hakkame lugema sisu
               kas_loeme_sisu = true;
               kas_on_alustav_silt = true;
               veeru_number = i;
               kas_on_ise_sulguv_silt = false;
             }
           } else {
             if(silt.length() == 0){
               // kui tegu esimese märgiga lisame selle sonasse
               // ja hakkame lugema sildi nime
               if(isalpha(rida[i]) || rida[i] == '_'){
                 kas_loeme_sildi_nime = true;
                 silt = silt + rida[i];
               } else if (rida[i] == ' '){ // kui märk on tyhik siis ignoreerime
               } else if (rida[i] == '?'){
                 kas_loeme_sildi_nime = true;
                 kas_on_pais = true;
                 kas_on_alustav_silt = false;
                 silt = silt + rida[i];
               } else if (rida[i] == '/'){ // kui esimene märk on / siis on tegu lopetava sildiga
                 kas_loeme_sildi_nime = true;
                 kas_on_alustav_silt = false;
                 silt = silt + rida[i];
               } else if (rida[i] != '<'){ // kui ykski tingimus pole täidetud on järelikult viga
                 cout << "Vigane silt! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
               }
             } else { // kui sona pikkus pole 0 ehk loeme  esimesele mingit järgnevat märki
               // kui märk on / ja tegu on alustava sildiga on järelikult isesulguv silt
              if(rida[i] == '/' && kas_on_alustav_silt == true && kas_on_atribuut == false){
                kas_on_ise_sulguv_silt = true;
                kas_loeme_sildi_nime = false;
              } // kui isesulguv silt lopetab ei pane seda pinusse vaid liigume edasi
              if(rida[i] == '>' && kas_on_ise_sulguv_silt == true ){
                kas_loeme_sisu = false;
                kas_loeme_sildi_nime = false;
                if(atribuut_labi == false && atribuudi_vaartus == true){
                  cout << "Atribuudi vaartusel puuduvad lopetavad jutumargid! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                }
                kas_on_atribuut = false;
                atribuudi_vaartus = false;
                atribuudi_vaartus2 = false;
                atribuut_labi = false;
                //cout << silt << endl;
                silt = "";
              }
              if(rida[i] == '?' && kas_on_pais == true){ // kui on ? siis päis lõpeb
                paise_lopp = true;
              }
              // kui on lopetav nool vaatame kas tegu on alustava voi lopetava sildiga
              if(rida[i] == '>' && kas_on_ise_sulguv_silt == false && kas_on_pais == false){
                 kas_loeme_sisu = false;
                 kas_loeme_sildi_nime = false;
                 if(atribuut_labi == false && atribuudi_vaartus == true){
                   cout << "Atribuudi vaartusel puuduvad lopetavad jutumargid! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                 }
                 kas_on_atribuut = false;
                 atribuudi_vaartus = false;
                 atribuudi_vaartus2 = false;
                 atribuut_labi = false;
                 if(kas_on_alustav_silt == true){
                   sildid.push(silt);
                   //cout << silt << endl;
                   silt = "";
                 }
                 // kui tegu on lopetava sildiga aga pinus pealmine silt ei ole temaga võrdne
                 // väljastame veateate, viskame minema pealmise ja algväärtustame sone et saaks edasi kontrollida
                 if(kas_on_alustav_silt == false && silt != '/' + sildid.top()){
                   sildid.pop();
                   cout << "Vigane silt! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                   cout << "Lopetav silt (" + silt + ") ei sama mis alustav silt (" + sildid.top() << ")" << endl;
                   silt = "";
                   // kui tegu on lopetava sildiga ja pinus pealmine silt on temaga võrdne viskame pealmise minema
                   // ja algväärtsutame sone
                 } else if (kas_on_alustav_silt == false && silt == '/' + sildid.top()){
                   sildid.pop();
                   //cout << silt << endl;
                   silt = "";
                 }
               }
              if(rida[i] == '>' && kas_on_pais == true){
                 kas_loeme_sisu = false;
                 kas_loeme_sildi_nime = false;
                 kas_on_pais = false;
                 if(atribuut_labi == false && atribuudi_vaartus == true){
                   cout << "Atribuudi vaartusel puuduvad jutumargid! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                 }
                 if(paise_lopp == false){ // kui enne lopetavat noolt pole olnud küsimärki seega on päise lõpp vigane
                   cout << "Vigane paise lopp! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                 }
                 // kui sulgeme päise suurendame ka loendurit
                 // loendur alguses 0, kui failis on rohkem kui 1 päist on viga
                 loendur++;
                 if(loendur > 1){
                   cout << "Viga! Tohib olla ainult 1 pais. Viga reas " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                 }
                 kas_on_atribuut = false;
                 atribuudi_vaartus = false;
                 atribuudi_vaartus2 = false;
                 atribuut_labi = false;
                 //cout << silt << endl;
                 silt = "";
              }
               //kui loeme sildi nime siis kontrollime kas märk on sobiv et see sisse lugeda
              if(kas_loeme_sildi_nime == true && kas_on_ise_sulguv_silt == false){
                 if(isalpha(rida[i]) || isdigit(rida[i]) || rida[i] == '-' || rida[i] == '.' || rida[i] == '_'){
                   silt = silt + rida[i];
                 } else if (rida[i] == ' '){ // kui märk on tyhik siis ignoreerime
                   kas_loeme_sildi_nime = false;
                 } else { // vastasel juhul on viga
                   cout << "Vigane silt! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                 }
              }
              if(kas_loeme_sildi_nime == false){
                //kui lopetame sildi nime lugemise aga loeme veel sisu, ja tegu on lopetava sildiga
                //ei saa tal olla küljes atribuute ehk iga märk mis ei ole tühik või lopetav märk on viga
                if(kas_on_alustav_silt == false && kas_on_ise_sulguv_silt == false && kas_on_pais == false){
                  if(rida[i] != ' ' && rida[i] != '>'){
                    cout << "Vigane silt! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                  }
                } // kui loeme sisu aga ei loe enam sildi nime ja tegu on alustava voi
                if(atribuut_labi == true){
                  if(rida[i] != ' ' ){
                    if(rida[i] == '?' && kas_on_pais == true){
                    } else if (isalpha(rida[i])){
                      atribuut_labi = false;
                    } else {
                      cout << "Peale atribuudi/atribuutide loppu ei tohi olla teisi marke! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                    }
                  }
                }  // isesulguva sildiga saab tal küljes olla atribuute
                if((kas_on_alustav_silt == true || kas_on_ise_sulguv_silt == true || kas_on_pais == true) && atribuut_labi == false){
                  if(isalpha(rida[i]) && kas_on_atribuut == false){
                    kas_on_atribuut = true;
                    kas_on_atribuudi_nimi = true;
                  } // kui on atribuut ja loeme tema nime
                  if(kas_on_atribuut == true && kas_on_atribuudi_nimi == true){
                    if(isalpha(rida[i])){
                    } else if (rida[i] == ' ') { //kui on tyhik lopetame nime lugemise
                      kas_on_atribuudi_nimi = false;
                    } else if (rida[i] == '=') { //kui on = lopetame nime lugemise
                      kas_on_atribuudi_nimi = false;
                    } else { //vastasel juhul on tegu veaga
                      cout << "Vigane atribuut! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                    }
                  } // kui on veel atribuut aga lopetasime atribuudi nime lugemise
                  if(kas_on_atribuut == true && kas_on_atribuudi_nimi == false){
                    if(rida[i] == '=' && atribuudi_vaartus == false){
                      atribuudi_vaartus = true; //algab atribuudi väärtus
                    }
                    if(atribuudi_vaartus == true){
                      if(atribuudi_vaartus2 == true){
                        if(rida[i] == '"') // kui tuleb uuesti jutumärgid lopetame atribuudi sisu
                        atribuut_labi = true;
                      }
                      if(rida[i] == '"' && atribuudi_vaartus2 == false){ // kui märk on "
                        atribuudi_vaartus2 = true; //algab jutumärkide sisu
                      }
                      // kui algab jutumärkide sisu on koik märgid sobilikud ning jutumärgid uuesti lopetavad sildi ja atribuudi
                      if(atribuudi_vaartus2 == false){ //kui jutumärke pole olnud
                        if(rida[i] == ' ' || rida[i] == '='){
                        } else {
                          cout << "Vigane atribuut! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                        }
                      }
                    }
                    if(atribuudi_vaartus == false){ // kui atribuudi väärtus pole true ehk võrdusmärki pole veel olnud on iga märk peale tühiku viga
                      if(rida[i] != ' '){
                        cout << "Vigane atribuut! Viga asub real " + to_string(rea_number) + " ja veerus " + to_string(veeru_number) << endl;
                      }
                    }

                  }
                }
              }
             }
           }

         }
	   }
	sisend.close();
  } else {
    cout << "Viga! Faili ei saanud avada." << std::endl;
  }
  if(loendur == 0){
    cout << "Viga! Failil puudub pais." << endl;
  }
  if(sildid.empty() == false){
    cout << "struktuuris on viga" << endl;
  }

  return 0;
}
