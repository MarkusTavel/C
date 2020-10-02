#include "Kuupaev.hpp"
#include <iostream>
#include <iomanip>

unsigned int getNumberOfDays(unsigned int month, unsigned int year) {
if( month == 2){
  if((year%400==0) || (year%4==0 && year%100!=0))
    return 29;
  else
    return 28;
}
else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
||month == 10 || month==12)
  return 31;
else
  return 30;
}

  Kuupaev::Kuupaev() {
		aasta = kuu = paev = 0;
	}
  Kuupaev::Kuupaev(const unsigned int& aasta, const unsigned int& kuu, const unsigned int& paev) {
    this->aasta = this->kuu = this->paev = 0;
    muuda(aasta,kuu,paev);
	}
  void Kuupaev::muuda(const Kuupaev& kuupaev){
    aasta = kuupaev.aasta;
    kuu = kuupaev.kuu;
    paev = kuupaev.paev;
  }
  void Kuupaev::muuda(const unsigned int& aasta, const unsigned int& kuu, const unsigned int& paev){
    muudaAasta(aasta);
    muudaKuu(kuu);
    muudaPaev(paev);
  }
  void Kuupaev::muudaAasta(const unsigned int& aasta){
    if(aasta < 1000 || aasta > 9999) return;
    this->aasta = aasta;
  }
  void Kuupaev::muudaKuu(const unsigned int& kuu){
    if(kuu > 12) return;
    this->kuu = kuu;
  }
  void Kuupaev::muudaPaev(const unsigned int& paev){
    if(paev > 31) return;
    this->paev = paev;
  }
  unsigned int Kuupaev::leiaAasta() const {
		return aasta;
	}
  unsigned int Kuupaev::leiaKuu() const {
		return kuu;
	}
  unsigned int Kuupaev::leiaPaev() const {
		return paev;
	}
std::ostream& operator<<(std::ostream& valjund, const Kuupaev& kuupaev) {
	valjund << std::setfill('0');
	valjund << std::setw(2) << kuupaev.leiaPaev();
	valjund << ':';
	valjund << std::setw(2) << kuupaev.leiaKuu();
  valjund << ':';
  valjund << std::setw(4) << kuupaev.leiaAasta();
	return valjund;
}
std::istream& operator>>(std::istream& sisend, Kuupaev& kuupaev) {
	unsigned int paev, kuu, aasta;
	sisend >> paev;
	if (sisend.fail()) return sisend;
	if (sisend.peek() == ':') {
		sisend.ignore(1, ':');
	} else {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	sisend >> kuu;
	if (sisend.fail()) return sisend;
	if (kuu > 12) {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
  if (sisend.peek() == ':') {
		sisend.ignore(1, ':');
	} else {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
  sisend >> aasta;
	if (sisend.fail()) return sisend;
	if (aasta < 1000 || aasta > 9999) {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
  if (paev > getNumberOfDays(kuu, aasta)) {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	kuupaev.muuda(aasta,kuu,paev);
	return sisend;
}
bool operator==(const Kuupaev& vasak, const Kuupaev& parem) {
	return vasak.leiaAasta() == parem.leiaAasta() &&
		vasak.leiaKuu() == parem.leiaKuu() && vasak.leiaPaev() == parem.leiaPaev();
}

bool operator!=(const Kuupaev& vasak, const Kuupaev& parem) {
	return !operator==(vasak, parem);
}

bool operator<(const Kuupaev& vasak, const Kuupaev& parem) {
	return vasak.leiaAasta() < parem.leiaAasta() ||
		(vasak.leiaAasta() == parem.leiaAasta() &&
		vasak.leiaKuu() < parem.leiaKuu()) || (vasak.leiaAasta() == parem.leiaAasta() &&
		vasak.leiaKuu() == parem.leiaKuu() && vasak.leiaPaev() < parem.leiaPaev());
}

bool operator>(const Kuupaev& vasak, const Kuupaev& parem) {
	return operator<(parem, vasak);
}

bool operator<=(const Kuupaev& vasak, const Kuupaev& parem) {
	return !operator>(vasak, parem);
}

bool operator>=(const Kuupaev& vasak, const Kuupaev& parem) {
	return !operator<(vasak, parem);
}
