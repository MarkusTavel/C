// Vene kabe
// Markus Tavel

#include <iostream>
#include <limits>
#include <ctype.h>
#include <fstream>

using namespace std;

class Manguvali {
public:
	void algvaartusta(char manguvali[9][9]){
		char mark1 = 'A';
		char mark2 = '1';
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				manguvali[i][j] = '-';
				if(i == 0 && j == 0){
					manguvali[i][j] = ' ';
				}
				if(i == 1 && j % 2 == 0){
					manguvali[i][j] = mangija1;
				}
				if(i == 2 && j % 2 == 1){
					manguvali[i][j] = mangija1;
				}
				if(i == 3 && j % 2 == 0){
					manguvali[i][j] = mangija1;
				}
				if(i == 6 && j % 2 == 1){
					manguvali[i][j] = mangija2;
				}
				if(i == 7 && j % 2 == 0){
					manguvali[i][j] = mangija2;
				}
				if(i == 8 && j % 2 == 1){
					manguvali[i][j] = mangija2;
				}
				if(i == 0 && j >= 1){
					manguvali[i][j] = mark1; mark1++;
				}
				if(j == 0 && i >= 1) {
					manguvali[i][j] = mark2; mark2++;
				}
			}
		}
	}
	void valjasta(char tabel[9][9]) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << " " << tabel[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	bool onVoidetud(char manguvali[9][9], char nupp, char kuningas){
		int kogus = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(manguvali[i][j] == nupp || manguvali[i][j] == kuningas){
					kogus++;
				}
			}
		}
		if(kogus == 0){
			return true;
		} else {
			return false;
		}
	}
private:
	char mangija1 = 'x';
	char mangija2 = 'y';
};

class Meetodid {
public:
	void kustuta_nupp(char manguvali[9][9], int a, int b, char nupp){
		manguvali[a][b] = '-';
		char taht = '@' + b;
		if(nupp == mangija1 || nupp == kuningas1){
			cout << "Mangija x vottis mangija y nupu kohal " << a << taht <<endl;
		}
		if(nupp == mangija2 || nupp == kuningas2){
			cout << "Mangija y vottis mangija x nupu kohal " << a << taht <<endl;
		}
	}

	void muuda_kuningas(char manguvali[9][9], int a, int b, char nupp){
		if(nupp == mangija1 && a == 8){
			manguvali[a][b] = kuningas1;
		}
		if(nupp == mangija2 && a == 1){
			manguvali[a][b] = kuningas2;
		}
	}
private:
	char mangija1 = 'x'; char kuningas1 = 'X';
	char mangija2 = 'y'; char kuningas2 = 'Y';
};

class Piirangud {
public:
	bool on_sobiv_kaik(char manguvali[9][9], int a, int b, char nupp, int i, int j){
		Meetodid meetod;
		if(nupp == mangija1 && manguvali[a][b] == '-' && a == i + 1 && b == j + 1) return true;
		if(nupp == mangija1 && manguvali[a][b] == '-' && a == i + 1 && b == j - 1) return true;
		if(nupp == mangija2 && manguvali[a][b] == '-' && a == i - 1 && b == j + 1) return true;
		if(nupp == mangija2 && manguvali[a][b] == '-' && a == i - 1 && b == j - 1) return true;
		if((nupp == mangija1 || nupp == kuningas1) && a == i + 2 && b == j + 2 && manguvali[a][b] == '-' && (manguvali[i+1][j+1] == mangija2 || manguvali[i+1][j+1] == kuningas2)){
			meetod.kustuta_nupp(manguvali,i+1,j+1,nupp); return true;
		}
		if((nupp == mangija1 || nupp == kuningas1) && a == i + 2 && b == j - 2 && manguvali[a][b] == '-' && (manguvali[i+1][j-1] == mangija2 || manguvali[i+1][j-1] == kuningas2)){
			meetod.kustuta_nupp(manguvali,i+1,j-1,nupp); return true;
		}
		if((nupp == mangija1 || nupp == kuningas1) && a == i - 2 && b == j + 2 && manguvali[a][b] == '-' && (manguvali[i-1][j+1] == mangija2 || manguvali[i-1][j+1] == kuningas2)){
			meetod.kustuta_nupp(manguvali,i-1,j+1,nupp); return true;
		}
		if((nupp == mangija1 || nupp == kuningas1) && a == i - 2 && b == j - 2 && manguvali[a][b] == '-' && (manguvali[i-1][j-1] == mangija2 || manguvali[i-1][j-1] == kuningas2)){
			meetod.kustuta_nupp(manguvali,i-1,j-1,nupp); return true;
		}
		if((nupp == mangija2 || nupp == kuningas2) && a == i + 2 && b == j + 2 && manguvali[a][b] == '-' && (manguvali[i+1][j+1] == mangija1 || manguvali[i+1][j+1] == kuningas1)){
			meetod.kustuta_nupp(manguvali,i+1,j+1,nupp); return true;
		}
		if((nupp == mangija2 || nupp == kuningas2) && a == i + 2 && b == j - 2 && manguvali[a][b] == '-' && (manguvali[i+1][j-1] == mangija1 || manguvali[i+1][j-1] == kuningas1)){
			meetod.kustuta_nupp(manguvali,i+1,j-1,nupp); return true;
		}
		if((nupp == mangija2 || nupp == kuningas2) && a == i - 2 && b == j + 2 && manguvali[a][b] == '-' && (manguvali[i-1][j+1] == mangija1 || manguvali[i-1][j+1] == kuningas1)){
			meetod.kustuta_nupp(manguvali,i-1,j+1,nupp); return true;
		}
		if((nupp == mangija2 || nupp == kuningas2) && a == i - 2 && b == j - 2 && manguvali[a][b] == '-' && (manguvali[i-1][j-1] == mangija1 || manguvali[i-1][j-1] == kuningas1)){
			meetod.kustuta_nupp(manguvali,i-1,j-1,nupp); return true;
		}
		if((nupp == kuningas1 || nupp == kuningas2) && manguvali[a][b] == '-' && a == i + 1 && b == j + 1) return true;
		if((nupp == kuningas1 || nupp == kuningas2) && manguvali[a][b] == '-' && a == i + 1 && b == j - 1) return true;
		if((nupp == kuningas1 || nupp == kuningas2) && manguvali[a][b] == '-' && a == i - 1 && b == j + 1) return true;
		if((nupp == kuningas1 || nupp == kuningas2) && manguvali[a][b] == '-' && a == i - 1 && b == j - 1) return true;
		return false;
	}

	bool nupp_on_kinni(char manguvali[9][9], int a, int b, char nupp){
		int a1, a2, b1, b2;
		a1 = a + 1; b1 = b + 1; a2 = a - 1; b2 = b - 1;
		// kui nupp on x ja temast all y saab võtta pole nupp kinni
		if(nupp == mangija1 && (manguvali[a1][b1] == mangija2 || manguvali[a1][b1] == kuningas2) && manguvali[a1 + 1][b1 + 1] == '-') return true;
		if(nupp == mangija1 && (manguvali[a1][b2] == mangija2 || manguvali[a1][b2] == kuningas2) && manguvali[a1 + 1][b2 - 1] == '-') return true;
		// kui nupp on x ja temast üleval y saab võtta pole nupp kinni
		if(nupp == mangija1 && (manguvali[a2][b1] == mangija2 || manguvali[a2][b1] == kuningas2) && manguvali[a2 - 1][b1 + 1] == '-') return true;
		if(nupp == mangija1 && (manguvali[a2][b2] == mangija2 || manguvali[a2][b2] == kuningas2) && manguvali[a2 - 1][b2 - 1] == '-') return true;
		// kui nupp on y ja temast all x saab võtta pole nupp kinni
		if(nupp == mangija2 && (manguvali[a1][b1] == mangija1 || manguvali[a1][b1] == kuningas1) && manguvali[a1 + 1][b1 + 1] == '-') return true;
		if(nupp == mangija2 && (manguvali[a1][b2] == mangija1 || manguvali[a1][b2] == kuningas1) && manguvali[a1 + 1][b2 - 1] == '-') return true;
		// kui nupp on y ja temast üleva x saab võtta pole nupp kinni
		if(nupp == mangija2 && (manguvali[a2][b1] == mangija1 || manguvali[a2][b1] == kuningas1) && manguvali[a2 - 1][b1 + 1] == '-') return true;
		if(nupp == mangija2 && (manguvali[a2][b2] == mangija1 || manguvali[a2][b2] == kuningas1) && manguvali[a2 - 1][b2 - 1] == '-') return true;

		if(nupp == kuningas1 && (manguvali[a1][b1] == mangija2 || manguvali[a1][b1] == kuningas2) && manguvali[a1 + 1][b1 + 1] == '-') return true;
		if(nupp == kuningas1 && (manguvali[a1][b2] == mangija2 || manguvali[a1][b2] == kuningas2) && manguvali[a1 + 1][b2 - 1] == '-') return true;

		if(nupp == kuningas1 && (manguvali[a2][b1] == mangija2 || manguvali[a2][b1] == kuningas2) && manguvali[a2 - 1][b1 + 1] == '-') return true;
		if(nupp == kuningas1 && (manguvali[a2][b2] == mangija2 || manguvali[a2][b2] == kuningas2) && manguvali[a2 - 1][b2 - 1] == '-') return true;

		if(nupp == kuningas2 && (manguvali[a1][b1] == mangija1 || manguvali[a1][b1] == kuningas1) && manguvali[a1 + 1][b1 + 1] == '-') return true;
		if(nupp == kuningas2 && (manguvali[a1][b2] == mangija1 || manguvali[a1][b2] == kuningas1) && manguvali[a1 + 1][b2 - 1] == '-') return true;

		if(nupp == kuningas2 && (manguvali[a2][b1] == mangija1 || manguvali[a2][b1] == kuningas1) && manguvali[a2 - 1][b1 + 1] == '-') return true;
		if(nupp == kuningas2 && (manguvali[a2][b2] == mangija1 || manguvali[a2][b2] == kuningas1) && manguvali[a2 - 1][b2 - 1] == '-') return true;

		if(nupp == mangija1 && manguvali[a1][b1] != '-' && manguvali[a1][b2] != '-') return false;
		if(nupp == mangija2 && manguvali[a2][b1] != '-' && manguvali[a2][b2] != '-') return false;

		return true;
	}
private:
	char mangija1 = 'x'; char kuningas1 = 'X';
	char mangija2 = 'y'; char kuningas2 = 'Y';
};

class Kaik {
public:
	int loe_number(){
		bool vale_sisend;
		char number;
		do{
			vale_sisend = false;
			cout << "sisesta number koordinaat "<<endl;
			cin >> number;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (number < '1' || number > '8') {
				vale_sisend = true;
				cout << "Sellist valikut pole" << endl;
			}
		}while(vale_sisend);
		int indeks = number - 48;
		return indeks;
	}

	int loe_taht(){
		bool vale_sisend;
		char taht;
		do{
			vale_sisend = false;
			cout << "sisesta taht koordinaat "<<endl;
			cin >> taht;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (taht < 'A' || taht > 'H') {
				vale_sisend = true;
				cout << "Sellist valikut pole" << endl;
			}
		}while(vale_sisend);
		int indeks = taht - 64;
		return indeks;
	}

	void liiguta_nupp(char manguvali[9][9], char nupp){
		int i, j;
		vali_nupp(manguvali,nupp,i,j);
		vali_koht(manguvali,nupp,i,j);
	}

	void vali_koht(char manguvali[9][9], char nupp, int i, int j){
		bool vale_sisend; Piirangud piirang; Meetodid meetod;
		int m, n;
		do{
			vale_sisend = false;
			cout << "Vali koht, kuhu tahad kaia"<<endl;
			m = loe_number(); n = loe_taht();
			if(m == i && n == j){
				cout << "See nupp asub juba sellel kohal" <<endl;
				vale_sisend = true;
			}
			if(manguvali[m][n] == mangija1 || manguvali[m][n] == mangija2){
				cout << "Sinna ei saa nuppu asetada" <<endl;
				vale_sisend = true;
			}
			if(piirang.on_sobiv_kaik(manguvali, m, n,nupp,i,j) == false){
				cout << "Seda kaiku ei saa sooritada" <<endl;
				vale_sisend = true;
			}
		}while(vale_sisend);
		manguvali[m][n] = nupp;
		meetod.muuda_kuningas(manguvali, m, n, nupp);
	}

	void vali_nupp(char manguvali[9][9], char& nupp, int& i, int& j){
		bool vale_sisend;
		do{
			vale_sisend = false;
			Piirangud piirang;
			cout << "Vali nupp, millega tahad käia"<<endl;
			i = loe_number(); j = loe_taht();
			if(manguvali[i][j] == kuningas1 && nupp == mangija1){
				nupp = kuningas1;
			}
			if(manguvali[i][j] == kuningas2 && nupp == mangija2){
				nupp = kuningas2;
			}
			if(piirang.nupp_on_kinni(manguvali,i,j,nupp) == false){
				cout << "Selle nupuga ei saa kuhugi kaia"<< endl;
				vale_sisend = true;
			}
			if(manguvali[i][j] != nupp){
				cout << "Sellel kohal ei asu teie nupp" << endl;
				vale_sisend = true;
			}
		}while(vale_sisend);
		manguvali[i][j] = '-';
	}

private:
	char mangija1 = 'x'; char kuningas1 = 'X';
	char mangija2 = 'y'; char kuningas2 = 'Y';
};

class Mang {
public:
	void kirjuta_faili(string failinimi, char mangija) {
		ofstream valjund(failinimi, ios::app);
		valjund << "Mangija " << mangija << " voit." << endl;
		valjund.close();
	}
	void kuvaReeglid(){
		cout << "Tere tulemast mangima Vene kabet!" << endl;
		cout << "Vene kabes mangivad omavahel 2 mangijat, kes liiguvad oma nupuga korda mooda." << endl;
		cout << "Tavalise nupuga on võimalik kaia vaid edasi, kuid võtta saab ka tagasi." << endl;
		cout << "Kui mangija nupp jouab vastase esimesele reale, muutub see kuningaks." << endl;
		cout << "Kuningas saab ja kaia ning votta edasi-tagasi. Mangimiseks kasurealiides." << endl;
		cout << "Mangija kaigu alguses lastakse mangijal valida nupp, selleks tuleb sisestada number ning taht koordinaat." << endl;
		cout << "Kui sisend ei vasta nouetele voi kohal asuv nupp on kinni kysitakse sisend uuesti." << endl;
		cout << "Kui nupp on korrektselt valitud tuleb sooritada kaik. Jallegi tuleb sisestadanumber ning taht koordinaat." << endl;
		cout << "Kui kaiku sooritada ei saa, annab programm sellest teada ning sisend kysitakse uuesti." << endl;
		cout << "Voitjaks tuleb mangija kes on suutnud eemalda mangulaualt koik vastase nupud." << endl;
	}
	void mangi(){
		do {
			kuvaReeglid();
			Manguvali vali; Kaik kaik; string valjundfail = "tulemused.txt";
			char manguvali[9][9]; char kuningas;
			char nupp[2] = {mangija1, mangija2};
			vali.algvaartusta(manguvali);
			for(int mangija = 0, kaike = 0; ; mangija = 1 - mangija, kaike++){
				vali.valjasta(manguvali);
				cout << "On mangija " << nupp[mangija] << " kord." <<endl;
				kaik.liiguta_nupp(manguvali, nupp[mangija]);
				if(nupp[mangija] == mangija1){
					kuningas = kuningas1;
				}
				if(nupp[mangija] == mangija2){
					kuningas = kuningas2;
				}
				if(vali.onVoidetud(manguvali, nupp[mangija], kuningas) == true){
					vali.valjasta(manguvali);
					kirjuta_faili(valjundfail, nupp[mangija]);
					cout <<"mang läbi, mängija " << nupp[mangija] << " voitis." <<endl;
					break;
				}
			}
		} while (soovib_uuesti());
	}
	bool soovib_uuesti() {
		// Loeme käsurealt märgi, mis vastab kasutaja mängusoovile
		// ('Y'/'y' tähistab soovi edasi mängida, 'N'/'n' soovi lõpetada)
		// Kui kasutaja sisestab ebasobiva märgi, küsime temalt sisendit uuesti
		char sisend;
		bool vale_sisend;
		do {
			// Eeldame, et kasutaja sisestab sobiva märgi
			vale_sisend = false;
			// Küsime kasutajalt sisendina märgi
			cout << "Kas soovid uuesti mangida (Y/N)? ";
			cin >> sisend;
			// Puhastame sisendvoo, viskame kõik allesjäänud märgid minema
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// Kui sisend ei ole sobiv, märgime sisendi vääraks ja väljastame
			// veateate
			if (sisend != 'Y' && sisend != 'y' && sisend != 'N' && sisend != 'n') {
				vale_sisend = true;
				cout << "Viga! Vasta kas 'Y' voi 'N'." << endl;
			}
		} while (vale_sisend);
		// Tagastame tõeväärtu8se, kas kasutaja soovib edasi mängida
		return sisend == 'Y' || sisend == 'y';
	}
private:
	char mangija1 = 'x'; char kuningas1 = 'X';
	char mangija2 = 'y'; char kuningas2 = 'Y';
};

int main(){
	Mang mang;
	mang.mangi();
	return 0;
}
