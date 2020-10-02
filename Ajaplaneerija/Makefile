# Algoritmid ja andmestruktuurid (NTR0390)
# Tallinna Tehnikaülikooli Tartu Kolledž
# Kodutöö 04: Ajaplaneerija
# Makefile programmi kompileerimiseks
# Kasutamine:
#   Kompileerimine			make all
#   Puhastamine				make clean

# Defineerime kompileeritava programmi nime
PROGRAM = ajaplaneerija.exe

# Defineerime kataloogid
# src           Definitsioonifailid (.cpp)
# include       Deklaratsioonifailid ehk päisfailid (.hpp)
# build         Objektfailid ehk objektkood (.o)
# bin           Käivitatavad programmid ehk masinkood
PATH_SRC = src
PATH_INCLUDE = include
PATH_BUILD = build
PATH_BIN = bin

# Defineerime objektfailide nimistu
# Seejuures lisame igale failinimele õige kataloogi ja faililaiendi.
# Kui programmi laiendada, tuleb siia nimistusse kanda lisatud failid.
# Objektkood on programmi kompileerimise vaheetapp, kus lähtekoodi failid on
# juba kompileeritud, aga ei ole veel ühtseks programmiks kokku pandud.
FILES = main Kellaaeg Kuupaev Aeg Uritus
OBJ = $(FILES:%=$(PATH_BUILD)\\%.o)

# Defineerime kompileeritava programmi asukoha
TARGET = $(PATH_BIN)\$(PROGRAM)

# Defineerime kasutatava kompilaatori
# g++           GNU C++ kompilaator
CXX = g++

# Määrame kompilaatorile edastatavad lipud
# -Wall         Kuvame kõik (all) hoiatused (W)
# -g            Anname GDB silujale (debugger) rohkem infot
# -std=c++14    Kasutame 2014. aasta C++ ISO standardit
CXXFLAGS = -Wall -g -std=c++14

# Määrame kompileerimisel manustatavate päisfailide kataloogi lipu
INC = -I $(PATH_INCLUDE)

# Defineerime käsu, mida kasutatakse failide kustutamiseks
# rm -f         Linux
# del /f        Windows
RM = del /f

# Defineerime käsu 'all', mis kompileerib kogu programmi
# See käsk kutsutakse välja, kui käsureal sisestada 'make' või 'make all'
all: $(TARGET)

# Defineerime käsu 'clean', mis puhastab kataloogi kompileeritud failidest
# See käsk kutsutakse välja, kui käsureal sisestada 'make clean'
clean:
	${RM} $(OBJ) $(TARGET)

# Defineerime, kuidas kogu programm objektkoodist kokku pannakse (linkimine)
# $^            Viitab failidele, mille põhjal kompileeritakse (dependencies)
# $@            Viitab failile, mida kompileeritakse (target)
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@

# Defineerime reeglipõhiselt, kuidas objektkood kompileeritakse
# $^            Viitab failidele, mille põhjal kompileeritakse (dependencies)
# $@            Viitab failile, mida kompileeritakse (target)
# Seejuures loome eelnevalt tarvilikud kataloogid
$(PATH_BUILD)\\%.o: $(PATH_SRC)\%.cpp
	$(CXX) -c $^ -o $@ $(INC) $(CXXFLAGS)
