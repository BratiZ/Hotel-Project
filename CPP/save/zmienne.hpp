#include "funkcje.hpp"

int IDsprawdzID = 0,
		IDKlientZBazy = 0,
		w = 0,
		xID,
		xD1, 
		xM1, 
		xR1, 
		xD2, 
		xM2, 
		xR2, 
		xIDKlient,
		IDklient,
		PobytIDKlient,
		PobytIDPokoj,
		PobytIDUsluga,
		PobytIDPobyt,
		ileZnakowMAX = 0,
		wyborINT,
		menu1,
		IDUslugi = 0,
		ID,
		xIDPobyt,
		wyjdz = 0,
		NowyIDKlient = 0,
		NowyIDKlientPobyt,
		NowyIDPokojPobyt,
		tmpNrPokoju,
		IDPobytuUslugi, 
		IDUslugiUslugi, 
		IDUloscUslugi,
		MaxZnakowUslugi = 0,
		ileCenaZnakow = 0,
		tmpIDKlient,
		tmpIDPobyt,
		ileUslug;
	
	string ImieKlientZBazy,
		   NazwiskoKlientZBazy,
		   nazwaKlient,
		   xIDUslugi,
		   xIlosc;
	
	char meldunek = '0',
		 xStan;
	
	float xCena;
	
	bool WProgram = true,
		 WMenu1 = true,
		 WZamelduj = true,
		 nazwaKlientSpacja = false,
		 IDZgodnosc = false,
		 WZnajdzKlienta = true,
		 WMenu1Zakwateruj = true,
		 PokojDobry = false,
		 KlientDobry = false,
		 kontynuuj = true;
 
	vector <Uslugi> tabUslugi;
	
	vector <int> tabIDweryfikacja;
	
	vector <Pobyt> tabPobyt;
	
	vector <Klient> tabKlient;
	
	vector <Pokoj1OS>  pokoj1,
	 				   pokoj2,
	 				   pokoj3;
	
	vector <BazaUslug> tabBazaUslug;
	
