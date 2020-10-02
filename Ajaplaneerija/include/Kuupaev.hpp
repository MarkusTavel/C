#ifndef __H_KUUPAEV__
#define __H_KUUPAEV__

#include <iostream>

class Kuupaev {
public:
  Kuupaev();
  Kuupaev(const unsigned int& aasta, const unsigned int& kuu, const unsigned int& paev);
  void muuda(const Kuupaev& kuupaev);
  void muuda(const unsigned int& aasta, const unsigned int& kuu, const unsigned int& paev);
  void muudaAasta(const unsigned int& aasta);
  void muudaKuu(const unsigned int& kuu);
  void muudaPaev(const unsigned int& paev);
  unsigned int leiaAasta() const;
  unsigned int leiaKuu() const;
  unsigned int leiaPaev() const;
private:
  unsigned int aasta;
  unsigned int kuu;
  unsigned int paev;
};

std::ostream& operator<<(std::ostream& valjund, const Kuupaev& kuupaev);
std::istream& operator>>(std::istream& sisend, Kuupaev& kuupaev);
bool operator==(const Kuupaev& vasak, const Kuupaev& parem);
bool operator!=(const Kuupaev& vasak, const Kuupaev& parem);
bool operator<(const Kuupaev& vasak, const Kuupaev& parem);
bool operator>(const Kuupaev& vasak, const Kuupaev& parem);
bool operator<=(const Kuupaev& vasak, const Kuupaev& parem);
bool operator>=(const Kuupaev& vasak, const Kuupaev& parem);
#endif
