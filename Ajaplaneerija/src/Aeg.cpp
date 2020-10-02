#include "Aeg.hpp"
#include "Kellaaeg.hpp"
#include "Kuupaev.hpp"
#include <iostream>
#include <iomanip>


  Aeg::Aeg(){
  }
  Aeg::Aeg(Kuupaev& kuupaev, Kellaaeg& kellaaeg){
    muuda(kuupaev, kellaaeg);
  }
  Aeg::Aeg(unsigned int& aasta, unsigned int& kuu, unsigned int& paev, unsigned int& tunnid, unsigned int& minutid){
    kuupaev.muuda(aasta,kuu,paev);
    kellaaeg.muuda(tunnid, minutid);
  }
  void Aeg::muuda(Kuupaev& kuupaev, Kellaaeg& kellaaeg) {
    muudaKuupaev(kuupaev);
    muudaKellaaeg(kellaaeg);
  }
  void Aeg::muuda(Aeg& aeg){
		kuupaev = aeg.kuupaev;
		kellaaeg = aeg.kellaaeg;
  }
  void Aeg::muudaKuupaev(Kuupaev& kuupaev){
    this->kuupaev.muuda(kuupaev);
  }
  void Aeg::muudaKellaaeg(Kellaaeg& kellaaeg){
    this->kellaaeg.muuda(kellaaeg);
  }
  Kuupaev Aeg::leiaKuupaev() const {
    return kuupaev;
  }
  Kellaaeg Aeg::leiaKellaaeg() const {
    return kellaaeg;
  }


std::ostream& operator<<(std::ostream& valjund, const Aeg& aeg) {
  valjund << aeg.leiaKuupaev();
  valjund << ' ';
  valjund << aeg.leiaKellaaeg();
  return valjund;
}

std::istream& operator>>(std::istream& sisend, Aeg& aeg) {
  Kuupaev kuupaev;
  Kellaaeg kellaaeg;
  sisend >> kuupaev;
  if(sisend.peek() == ' ') {
    sisend.ignore(1, ' ');
  } else {
    sisend.setstate(std::ios::failbit);
    return sisend;
  }
  sisend >> kellaaeg;
  aeg.muuda(kuupaev,kellaaeg);
  return sisend;
}
bool operator==(const Aeg& vasak, const Aeg& parem) {
  return vasak.leiaKuupaev() == parem.leiaKuupaev() && vasak.leiaKellaaeg() == parem.leiaKellaaeg();
}

bool operator!=(const Aeg& vasak, const Aeg& parem) {
  return !operator==(vasak, parem);
}

bool operator<(const Aeg& vasak, const Aeg& parem) {
  return vasak.leiaKuupaev() < parem.leiaKuupaev() || (vasak.leiaKuupaev() == parem.leiaKuupaev() && vasak.leiaKellaaeg() < parem.leiaKellaaeg());
}

bool operator>(const Aeg& vasak, const Aeg& parem) {
  return operator<(parem, vasak);
}

bool operator<=(const Aeg& vasak, const Aeg& parem) {
  return !operator>(vasak, parem);
}

bool operator>=(const Aeg& vasak, const Aeg& parem) {
  return !operator<(vasak, parem);
}
