#ifndef __H_URITUS__
#define __H_URITUS__

#include "Kellaaeg.hpp"
#include "Kuupaev.hpp"
#include "Aeg.hpp"
#include <iostream>

class Uritus{
public:
	Uritus();
	Uritus(Aeg& algus, Aeg& lopp, std::string& nimi);
	void muuda(Uritus& uritus);
	void muuda(Aeg& algus, Aeg& lopp, std::string& nimi);
	void muudaAlgus(Aeg& algus);
	void muudaLopp(Aeg& lopp);
	void muudaNimi(std::string& nimi);
	Aeg leiaAlgus() const;
	Aeg leiaLopp() const;
	std::string leiaNimi() const;
private:
	Aeg algus;
	Aeg lopp;
	std::string nimi;
};

std::ostream& operator<<(std::ostream& valjund, const Uritus& uritus);
std::istream& operator>>(std::istream& sisend, Uritus& uritus);
bool operator==(const Uritus& vasak, const Uritus& parem);
bool operator!=(const Uritus& vasak, const Uritus& parem);
bool operator<(const Uritus& vasak, const Uritus& parem);
bool operator>(const Uritus& vasak, const Uritus& parem);
bool operator<=(const Uritus& vasak, const Uritus& parem);
bool operator>=(const Uritus& vasak, const Uritus& parem);
#endif
