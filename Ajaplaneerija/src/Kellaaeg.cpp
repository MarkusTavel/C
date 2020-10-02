
#include "Kellaaeg.hpp"
#include <iostream>			// std::istream, std::ostream
#include <iomanip>			// std::setfill, std::setw


Kellaaeg::Kellaaeg() {
	tunnid = minutid = 0;
}

Kellaaeg::Kellaaeg(const Kellaaeg& kellaaeg) {
	// Siin võime kasutada kellaaja muutmise meetodit, mis võtab parameetriks
	// kellaaja tüüpi muutuja, sest olemasoleva kellaaja tundide ja minutite
	// väärtustes võime kindlad olla ning nende väärtuste õigetesse vahemikesse
	// kuulumise eelnev valideerimine pole tarvilik.
	muuda(kellaaeg);
}

Kellaaeg::Kellaaeg(const unsigned int& tunnid, const unsigned int& minutid) {
	// Algväärtustame tunnid ja minutid enne muutmise meetodi väljakutsumist
	// 0-ks, et tagada, et neil oleks igal juhul väärtus.
	// Sellisel juhul võime kasutada olemasolevat muutmise meetodit ilma
	// sealset koodi siia ümber kopeerimata.
	this->tunnid = this->minutid = 0;
	muuda(tunnid, minutid);
}

void Kellaaeg::muuda(const Kellaaeg& kellaaeg) {
	// Siin ei kasuta me kellaja muutmise meetodit tundide ja minutite
	// parameetritega eraldi, vaid anname tundidele ja minutitele väärtused
	// otse, sest olemasoleva kellajaa tundide ja minutite väärtustes võime
	// kindlad olla ning nende väärtuste õigetesse vahemikesse kuulumise eelnev
	// valideerimine pole tarvilik.
	tunnid = kellaaeg.tunnid;
	minutid = kellaaeg.minutid;
}

void Kellaaeg::muuda(const unsigned int& tunnid, const unsigned int& minutid) {
	// Kanname tundide ja minutite muutmise vastutuse edasi nende eraldi
	// muutmiseks mõeldud meetoditele, kuna funktsionaalsus on sama.
	muudaTunnid(tunnid);
	muudaMinutid(minutid);
}

void Kellaaeg::muudaTunnid(const unsigned int& tunnid) {
	// Kui parameetris edastatud tundide väärtus on ebasobiv, st see ei jää
	// vahemikku [0, 23], ei muuda me olemasolevat tundide väärtust. Sedasi
	// toimimise eelduseks on, et kellaajal on juba tundide väärtus. Seega
	// peavad kõik konstruktorid tagama, et väärtus oleks alati olemas.
	if (tunnid > 23) return;
	this->tunnid = tunnid;
}

void Kellaaeg::muudaMinutid(const unsigned int& minutid) {
	// Kui parameetris edastatud minutite väärtus on ebasobiv, st see ei jää
	// vahemikku [0, 59], ei muuda me olemasolevat minutite väärtust. Sedasi
	// toimimise eelduseks on, et kellaajal on juba minutite väärtus. Seega
	// peavad kõik konstruktorid tagama, et väärtus oleks alati olemas.
	if (minutid > 59) return;
	this->minutid = minutid;
}

unsigned int Kellaaeg::leiaTunnid() const {
	return tunnid;
}

unsigned int Kellaaeg::leiaMinutid() const {
	return minutid;
}

std::ostream& operator<<(std::ostream& valjund, const Kellaaeg& kellaaeg) {
	// Määrame väljundvoos täitemärgiks 0-i. Kui väljastatavatele väärtustele
	// määratud pikkus on suurem nende tegelikust pikkusest, täidetakse
	// puuduvad märgid 0-dega. Vaikimisi joondatakse tegelik väärtus paremale,
	// st 0-d asetatakse väärtuse ette.
	// Tasub tähele panna, et täitemärki on tarvis määrata vaid korra. See
	// rakendub kõigile väärtustele, mis pärast seda väljastatakse.
	valjund << std::setfill('0');
	// Väljastame kellaaja tundide väärtuse laiusega 2. Kui tundide väärtus on
	// ühekohaline, pannakse selle ette 0.
	// Laiuse määramisel rakendub see vaid vahetult järgnevale väljastatavale
	// väärtusele.
	valjund << std::setw(2) << kellaaeg.leiaTunnid();
	// Väljastame tundide ja minutite väärtuste vahele kooloni.
	valjund << ':';
	// Väljastame kellaaja minutite väärtuse laiusega 2. Kui minutite väärtus on
	// ühekohaline, pannakse selle ette 0.
	valjund << std::setw(2) << kellaaeg.leiaMinutid();
	// Tagastame väljundvoo objekti, et võimaldada ahelväljundit kujul
	// valjund << kellaaeg1 << " " << kellaaeg2;
	return valjund;
}

std::istream& operator>>(std::istream& sisend, Kellaaeg& kellaaeg) {
	// Deklareerime muutujad kellaaja tundide ja minutite väärtuste eraldi
	// sisselugemiseks. Kasutame eraldi muutujaid, mitte ei loe väärtusi otse
	// parameetris esitatud kellaaja tüüpi muutujasse, sest enne väärtuste
	// sisselugemist ei tea me veel, kas kellaaeg on sobival kujul.
	unsigned int tunnid, minutid;
	// Loeme sisse kellaaja tundide väärtuse.
	// Kui sisendvoog jõuab täisarvu sisselugemise tulemusel veaseisundisse,
	// polnud sisseloetud väärtus täisarv. Seega ei ole võimalik kellaaega
	// sisse lugeda ning tagastame kohe sisendvoo, säilitades seejuures voo
	// veaseisundi.
	// Kui sisendvoog ei ole pärast täisarvu sisselugemist veaseisundis,
	// kontrollime, et sisseloetud väärtus oleks tundidele sobivas vahemikus
	// [0, 23]. Kui see seda ei ole, ei ole võimalik kellaaega sisse lugeda,
	// seega määrame sisendvoole veaseisundi ning tagastame sisendvoo.
	sisend >> tunnid;
	if (sisend.fail()) return sisend;
	if (tunnid > 23) {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	// Kontrollime, kas järgmine märk sisendis on koolon.
	// Kui on, loeme selle sisse (maksimaalselt ühe märgi kuni koolonini,
	// koolon kaasaarvatud) ja viskame minema.
	// Kui mitte, ei ole kellaaeg sobivas vormingus, seega määrame sisendvoole
	// veaseisundi ning tagastame sisendvoo.
	if (sisend.peek() == ':') {
		sisend.ignore(1, ':');
	} else {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	// Loeme sisse kellaaja minutite väärtuse.
	// Kui sisendvoog jõuab täisarvu sisselugemise tulemusel veaseisundisse,
	// polnud sisseloetud väärtus täisarv. Seega ei ole võimalik kellaaega
	// sisse lugeda ning tagastame kohe sisendvoo, säilitades seejuures voo
	// veaseisundi.
	// Kui sisendvoog ei ole pärast täisarvu sisselugemist veaseisundis,
	// kontrollime, et sisseloetud väärtus oleks minutitele sobivas vahemikus
	// [0, 59]. Kui see seda ei ole, ei ole võimalik kellaaega sisse lugeda,
	// seega määrame sisendvoole veaseisundi ning tagastame sisendvoo.
	sisend >> minutid;
	if (sisend.fail()) return sisend;
	if (minutid > 59) {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	// Kui siiani pole funktsiooni tööd sellest sisendvoo tagastamisega veel
	// lõpetatud, oli järelikult sisendis kellaaeg sobival kujul ning selle
	// tundide ja minutite väärtused õigetes vahemikes. Seega saame lõpuks
	// kellaaja muutuja väärtust muuta.
	kellaaeg.muuda(tunnid, minutid);
	// Tagastame sisendvoo objekti, et võimaldada ahelsisendit kujul
	// sisend >> kellaaeg1 >> kellaaeg2;
	return sisend;
}

bool operator==(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Kaks kellaaega on võrdsed, kui nende tundide väärtused on võrdsed ja
	// minutite väärtused on võrdsed.
	return vasak.leiaTunnid() == parem.leiaTunnid() &&
		vasak.leiaMinutid() == parem.leiaMinutid();
}

bool operator!=(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Kaks kellaaega on mittevõrdsed, kui need pole võrdsed.
	// Kasutame siin juba kirjutatud võrdlusoperaatorit ==.
	return !operator==(vasak, parem);
}

bool operator<(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Üks kellaaeg on teisest väiksem, kui (1) selle tundide väärtus on teise
	// tundide väärtusest väiksem või (2) nende tundide väärtused on võrdsed ja
	// esimese minutite väärtus on teise minutite väärtusest väiksem.
	return vasak.leiaTunnid() < parem.leiaTunnid() ||
		(vasak.leiaTunnid() == parem.leiaTunnid() &&
		vasak.leiaMinutid() < parem.leiaMinutid());
}

bool operator>(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Üks kellaaeg on teisest suurem, kui teine on esimesest väiksem.
	// Kasutame siin juba kirjutatud võrdlusoperaatorit <.
	return operator<(parem, vasak);
}

bool operator<=(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Üks kellaaeg on teisest väiksem või sellega võrdne, kui see pole teisest
	// suurem.
	// Kasutame siin tõeväärtuse eitust ja juba kirjutatud võrdlusoperaatorit >.
	return !operator>(vasak, parem);
}

bool operator>=(const Kellaaeg& vasak, const Kellaaeg& parem) {
	// Üks kellaaeg on teisest suurem või sellega võrdne, kui see pole teisest
	// väiksem.
	// Kasutame siin tõeväärtuse eitust ja juba kirjutatud võrdlusoperaatorit <.
	return !operator<(vasak, parem);
}
