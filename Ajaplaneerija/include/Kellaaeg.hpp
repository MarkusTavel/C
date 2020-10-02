

// Kaitseme faili mitmekordse manustamise eest
// Kui eelprotsessoris pole päisfailile vastavat konstanti veel defineeritud,
// siis järelikult pole päisfaili veel koodile lisatud; defineerime konstandi
// ja lisame päisfaili sisu koodile. Kui konstant on juba defineeritud, siis
// on päisfaili sisu korra juba koodile lisatud ja seda uuesti teha ei tohiks.
// Paneme tähele, et kõigil päisfailidel on erinevad konstandid.
#ifndef __H_KELLAAEG__
#define __H_KELLAAEG__

#include <iostream>			// std::istream, std::ostream


/**
 * Kellaaja klass võimaldab salvestada kellaaegu kujul tunnid:minutid, kus
 * tunnid jäävad vahemikku [0, 23] ja minutid jäävad vahemikku [0, 59].
 * Klassil on sisend- ja väljundvoo-operaatorid, mis võimaldavad kellaaegasid
 * sisse lugeda ja väljastada formaadis TT:MM.
 * Klassil on ka võrdlusoperaatorid ==, !=, <, >, <= ja >=, mis võimaldavad
 * kellaaegasid omavahel lihtsalt võrrelda.
 */
class Kellaaeg {

public:
	/**
	 * Konstruktor ilma ühegi parameetrita; algväärtustab kellaaja kujule 00:00.
	 */
	Kellaaeg();

	/**
	 * Konstruktor, mis algväärtustab kellaaja vastavalt parameetris esitatud
	 * kellaaja tüüpi muutujale.
	 * @param kellaaeg Loodava kellaaja soovitud väärtus
	 */
	Kellaaeg(const Kellaaeg& kellaaeg);

	/**
	 * Konstruktor, mis algväärtustab kellaaja vastavalt parameetris esitatud
	 * tundide ja minutite väärtustele kujul tunnid:minutid.
	 * Piirangud:
	 * - Kui parameetris esitatud tundide väärtus ei jää vahemikku [0, 23],
	 *   algväärtustatakse see 0-ks.
	 * - Kui parameetris esitatud minutite väärtus ei jää vahemikku [0, 59],
	 *   algväärtustatakse see 0-ks.
	 * @param tunnid  Loodava kellaaja soovitud tundide väärtus
	 * @param minutid Loodava kellaaja soovitud minutite väärtus
	 */
	Kellaaeg(const unsigned int& tunnid, const unsigned int& minutid);

	/**
	 * Meetod, mis muudab kellaaja väärtust vastavalt parameetris esitatud
	 * kellaaja tüüpi muutujale.
	 * @param kellaaeg Kellaaeg, mille väärtus ümber kopeerida
	 */
	void muuda(const Kellaaeg& kellaaeg);

	/**
	 * Meetod, mis muudab kellaaja väärtust vastavalt parameetris esitatud
	 * tundide ja minutite väärtustele kujul tunnid:minutid.
	 * Piirangud:
	 * - Kui parameetris esitatud tundide väärtus ei jää vahemikku [0, 23],
	 *   siis kellaaja tundide väärtust ei muudeta.
	 * - Kui parameetris esitatud minutite väärtus ei jää vahemikku [0, 59],
	 *   siis kellaaja minutite väärtust ei muudeta.
	 * @param tunnid  Kellajale soovitud tundide uus väärtus
	 * @param minutid Kellaajale soovitud minutite uus väärtus
	 */
	void muuda(const unsigned int& tunnid, const unsigned int& minutid);

	/**
	 * Meetod, mis muudab kellaaja tundide väärtust vastavalt parameetris
	 * esitatatud väärtusele.
	 * Piirangud:
	 * - Kui parameetris esitatud tundide väärtus ei jää vahemikku [0, 23],
	 *   siis kellaaja tundide väärtust ei muudeta.
	 * @param tunnid Kellaajale soovitud tundide uus väärtus
	 */
	void muudaTunnid(const unsigned int& tunnid);

	/**
	 * Meetod, mis muudab kellaaja minutite väärtust vastavalt parameetris
	 * esitatud väärtusele.
	 * Piirangud:
	 * - Kui parameetris esitatud minutite väärtus ei jää vahemikku [0, 59],
	 *   siis kellaaja minutite väärtust ei muudeta.
	 * @param minutid Kellajaale soovitud minutite uus väärtus
	 */
	void muudaMinutid(const unsigned int& minutid);

	/**
	 * Meetod, mis tagastab kellaaja tundide väärtuse.
	 * @return Kellaaja tundide väärtus; mittenegatiivne täisarv
	 */
	unsigned int leiaTunnid() const;

	/**
	 * Meetod, mis tagastab kellaaja minutite väärtuse.
	 * @return Kellaaja minutite väärtus; mittenegatiivne täisarv
	 */
	unsigned int leiaMinutid() const;

private:
	/**
	 * Kellaaja tundide komponent; mittenegatiivne täisarv
	 */
	unsigned int tunnid;

	/**
	 * Kellaaja minutite komponent; mittenegatiivne täisarv
	 */
	unsigned int minutid;
};


/**
 * Kellaaja väljundvoo-operaatorit << ülelaadiv funkstioon, mis väljastab
 * kellaja väljundvoogu kujul tunnid:minutid.
 * Seejuures järgitakse formaati TT:MM, st nii tundide kui minutite väärtused
 * väljastatakse kahekohalisena. Ühekohalistele väärtustele eelnevad nullid.
 * @param  valjund  Väljundvoog, kuhu kellaaeg väljastada
 * @param  kellaaeg Kellaaeg, mida väljundvoogu kirjutada
 * @return          Väljundvoog, et võimaldada ahelväljundit
 */
std::ostream& operator<<(std::ostream& valjund, const Kellaaeg& kellaaeg);

/**
 * Kellaaja sisendvoo-operaatorit >> ülelaadiv funktsioon, mis loeb kellaaja
 * sisendvoost sisse kujul tunnid:minutid.
 * Kui tundide või minutite kohal pole mittenegatiivsed täisarvud korrektses
 * vahemikus (tundide puhul [0, 23], minutite puhul [0, 59]) või need pole
 * eraldatud kooloniga, märgitakse sisendvoog katkiseks.
 * @param  sisend   Sisendvoog, millest kellaaeg sisse lugeda
 * @param  kellaaeg Kellaaja muutuja, millesse sisendvoost väärtus lugeda
 * @return          Sisendvoog, et võimaldada ahelsisendit
 */
std::istream& operator>>(std::istream& sisend, Kellaaeg& kellaaeg);

/**
 * Kellaaegade võrdlusoperaatorit == ülelaadiv funktsioon, mis leiab, kas kaks
 * kellaaega on omavahel võrdsed.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas kaks kellaaega on võrdsed
 */
bool operator==(const Kellaaeg& vasak, const Kellaaeg& parem);

/**
 * Kellaaegade võrdlusoperaatorit != ülelaadiv funktsioon, mis leiab, kas kaks
 * kellaaega on omavahel mittevõrdsed.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas kaks kellaaega on mittevõrdsed
 */
bool operator!=(const Kellaaeg& vasak, const Kellaaeg& parem);

/**
 * Kellaaegade võrdlusoperaatorit < ülelaadiv funktsioon, mis leiab, kas üks
 * kellaaeg on teisest väiksem.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas vasakpoolne kellaaeg on
 *               parempoolsest kellaajast väiksem
 */
bool operator<(const Kellaaeg& vasak, const Kellaaeg& parem);

/**
 * Kellaaegade võrdlusoperaatorit > ülelaadiv funktsioon, mis leiab, kas üks
 * kellaaeg on teisest suurem.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas vasakpoolne kellaaeg on
 *               parempoolsest kellaajast suurem
 */
bool operator>(const Kellaaeg& vasak, const Kellaaeg& parem);

/**
 * Kellaaegade võrdlusoperaatorit <= ülelaadiv funktsioon, mis leiab, kas üks
 * kellaaeg on teisest väiksem või sellega võrdne.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas vasakpoolne kellaaeg on
 *               parempoolsest kellaajast väiksem või sellega võrdne
 */
bool operator<=(const Kellaaeg& vasak, const Kellaaeg& parem);

/**
 * Kellaaegade võrdlusoperaatorit >= ülelaadib funktsioon, mis leiab, kas üks
 * kellaaeg on teisest suurem või sellega võrdne.
 * @param  vasak Võrdluse vasakpoolseks operandiks olev kellaaeg
 * @param  parem Võrdluse parempoolseks operandiks olev kellaaeg
 * @return       Tõeväärtus, mis näitab, kas vasakpoolne kellaaeg on
 *               parempoolsest kellaajast suurem või sellega võrdne
 */
bool operator>=(const Kellaaeg& vasak, const Kellaaeg& parem);


// Päisefaili konstandi __H_KELLAAEG__ lõpulause
#endif
