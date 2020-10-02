# Kodutöö 04: Ajaplaneerija

See README fail on kirjutatud Markdown süntaksis. Kui kasutad Atomit ja soovid faili loetavamal kujul näha, vajuta Ctrl + Shift + M. Kui Sa ei kasuta Atomit, võid faili ilusamas vormingus nägemiseks kasutada mõnda teist Markdown'i parserit.

## Projekti struktuur

Projekt on jaotatud nelja kataloogi, millest igaüks täidab erinevat eesmärki:
- src           - definitsioonifailid (.cpp)
- include       - deklaratsioonifailid ehk päisfailid (.hpp)
- build         - objektfailid ehk objektkood (.o)
- bin           - käivitatavad programmid ehk masinkood

Projekt on töökeskkonda (nt Atom) mõistlik laadida tervikuna, nii et näeks ka projektipuud, mitte faile ükshaaval lahti võtta ja sulgeda.

## Kompileerimine ja käivitamine

Programmi kompileerimisest piisab järgnevast käsust:

```
mingw32-make all
```

See käsk käivitab programmi Make, mis loeb projekti Makefile'ist, kuidas projekti kokku kompileerima peaks. Makefile'is on selleks kõik reeglid defineeritud. Käsu sellisel kujul kasutamiseks peab programm Make asuma operatsioonisüsteemi keskkonnamuutujas (*environment variable*); vastasel juhul tuleb programmile otse viidata.

Programmi kompileerimise tulemusel luuakse objektkoodi failid kataloogi *build* ning lingitakse need kokku ühtseks täitmisfailiks kataloogis *bin*. Programmi käivitamiseks tulebki käivitada fail kataloogis *bin*.

Kataloogid *bin*, *build*, *src* ja *include* peavad projektis olemas olema. Makefile neid ise ei loo. Makefile on võimalik panna neid katalooge ise tegema, aga praegusesse näitesse seda lisatud pole, sest Makefile'id on uus teema ja juba piisavalt keerukad.

## Puhastamine

Projekti kataloogi puhastamiseks saab kasutada järgnevat käsku:

```
mingw32-make clean
```

See kustutab kõik kompileerimise tulemusel loodud objektkoodi failid ja ka nende kokkulinkimisel saadud täitmisfaili.

## Projekti edasiarendamine

Projekti edasiarendamine peaks käima samal meetodil. Uue klassi (või kooditeegi) loomiseks tuleb selle päisfail asetada kataloogi *include* ning implementatsioonifail kataloogi *src*. Päisfaili saab seejärel manustada kõikjale, kus uutesse failidesse kirjutatud koodi kasutad.

Muutusi tuleb aga teha ka Makefile'is. Iga uue komponendi lisamisel tuleb muutujasse *FILES* lisada juurdekirjutatud faili nimi ilma faililaiendita teistest tühikuga eraldatuna. Hetkel on seal ainult *main* ja *Kellaaeg*, aga näiteks komponendi *Kuupaev* lisamisel projekti (päisfail *Kuupaev.hpp* ja implementatsioonifail *Kuupaev.cpp*) peaks muutuja *FILES* välja nägema järgnev:

```Makefile
FILES = main Kellaaeg Kuupaev
```
