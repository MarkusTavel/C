#ifndef __H_AEG__
#define __H_AEG__

#include "Kellaaeg.hpp"
#include "Kuupaev.hpp"
#include <iostream>

class Aeg {
public:
  Aeg();
  Aeg(Kuupaev& kuupaev, Kellaaeg& kellaaeg);
  Aeg(unsigned int& aasta, unsigned int& kuu, unsigned int& paev, unsigned int& tunnid, unsigned int& minutid);
  void muuda(Kuupaev& kuupaev, Kellaaeg& kellaaeg);
  void muuda(Aeg& aeg);
  void muudaKuupaev(Kuupaev& kuupaev);
  void muudaKellaaeg(Kellaaeg& kellaaeg);
  Kuupaev leiaKuupaev() const;
  Kellaaeg leiaKellaaeg() const;

private:
  Kuupaev kuupaev;
  Kellaaeg kellaaeg;
};

std::ostream& operator<<(std::ostream& valjund, const Aeg& aeg);
std::istream& operator>>(std::istream& sisend, Aeg& aeg);
bool operator==(const Aeg& vasak, const Aeg& parem);
bool operator!=(const Aeg& vasak, const Aeg& parem);
bool operator<(const Aeg& vasak, const Aeg& parem);
bool operator>(const Aeg& vasak, const Aeg& parem);
bool operator<=(const Aeg& vasak, const Aeg& parem);
bool operator>=(const Aeg& vasak, const Aeg& parem);
#endif
