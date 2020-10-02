#include "Aeg.hpp"
#include "Kellaaeg.hpp"
#include "Kuupaev.hpp"
#include "Uritus.hpp"
#include <iostream>
#include <iomanip>

	Uritus::Uritus(){
	}
	Uritus::Uritus(Aeg& algus, Aeg& lopp, std::string& nimi){
		muuda(algus,lopp,nimi);
	}
	void Uritus::muuda(Uritus& uritus){
		algus = uritus.algus;
		lopp = uritus.lopp;
		nimi = uritus.nimi;
	}
	void Uritus::muuda(Aeg& algus, Aeg& lopp, std::string& nimi){
		muudaAlgus(algus);
		muudaLopp(lopp);
		muudaNimi(nimi);
	}
	void Uritus::muudaAlgus(Aeg& algus){
		this->algus.muuda(algus);
	}
	void Uritus::muudaLopp(Aeg& lopp){
		this->lopp.muuda(lopp);
	}
	void Uritus::muudaNimi(std::string& nimi){
		this->nimi = nimi;
	}
	Aeg Uritus::leiaAlgus() const {
		return algus;
	}
	Aeg Uritus::leiaLopp() const {
		return lopp;
	}
	std::string Uritus::leiaNimi() const {
		return nimi;
	}


std::ostream& operator<<(std::ostream& valjund, const Uritus& uritus) {
	valjund << uritus.leiaAlgus();
	valjund << ' ';
	valjund << uritus.leiaLopp();
	valjund << ' ';
	valjund << uritus.leiaNimi();
	return valjund;
}

std::istream& operator>>(std::istream& sisend, Uritus& uritus) {
	Aeg algus;
	Aeg lopp;
	std::string nimi;
  sisend >> algus;
  if(sisend.peek() == ' ') {
		sisend.ignore(1, ' ');
	} else {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
  sisend >> lopp;
	if(sisend.peek() == ' ') {
		sisend.ignore(1, ' ');
	} else {
		sisend.setstate(std::ios::failbit);
		return sisend;
	}
	std::getline(sisend,nimi);
  uritus.muuda(algus,lopp,nimi);
  return sisend;
}



bool operator==(const Uritus& vasak, const Uritus& parem) {
	return vasak.leiaAlgus() == parem.leiaAlgus() && vasak.leiaLopp() == parem.leiaLopp();
}
bool operator!=(const Uritus& vasak, const Uritus& parem) {
	return !operator==(vasak, parem);
}
bool operator<(const Uritus& vasak, const Uritus& parem) {
	return vasak.leiaAlgus() < parem.leiaLopp() ;
}

bool operator>(const Uritus& vasak, const Uritus& parem) {
	return operator<(parem, vasak);
}

bool operator<=(const Uritus& vasak, const Uritus& parem) {
	return !operator>(vasak, parem);
}

bool operator>=(const Uritus& vasak, const Uritus& parem) {
	return !operator<(vasak, parem);
}
