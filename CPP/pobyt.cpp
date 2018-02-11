#include "zmienne.hpp"

int main(int argc, char** argv) {

	HWND console = GetConsoleWindow();
  	RECT r;
  	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1200, 600, TRUE);

	fstream plikBazaKlient,
			plikBazaPokoje,
			plikBazaPobyt,
			plikBazaUslugi,
			plikBazaUslug;
	
	plikBazaKlient.open( "BASE/KlientBaza.txt" 	, ios::app | ios::in ); //otworz plik
	plikBazaPokoje.open( "BASE/BazaPokoje2.txt" , ios::app | ios::in );
	plikBazaPobyt.open( "BASE/BazaPobyt.txt" 	, ios::app | ios::in );
	plikBazaUslugi.open( "BASE/UslugiBaza.txt" 	, ios::app | ios::in );
	plikBazaUslug.open( "BASE/BazaUslug.txt" 	, ios::app | ios::in );
	
	if (  !plikBazaKlient.is_open() or !plikBazaPokoje.is_open() or !plikBazaPobyt.is_open() or !plikBazaUslugi.is_open() )
	{
		outKolor( 4 , "Nie mozna otworzyc pliku!" ); //sprawdz czy otwarty
		pause();
	}
	
	
	while( true )
	{
		plikBazaUslug >> IDPobytuUslugi >> IDUslugiUslugi >> IDUloscUslugi;
		
		if( plikBazaUslug.good() )
			tabBazaUslug.push_back( BazaUslug( IDPobytuUslugi , IDUslugiUslugi , IDUloscUslugi ) );
				else
					break;
	}
	
	while( true )
	{
		plikBazaUslugi >> xIDPobyt >> xIDUslugi >> xIlosc;
		if( plikBazaUslugi.good() )
		{
			for( int f2 = 0; f2 < xIDUslugi.size(); f2++ )
			{
				if( xIDUslugi[f2] == '_' )
				{
					xIDUslugi[f2] = ' ';
				}
			}
			
			if( MaxZnakowUslugi < xIDUslugi.size() )
				MaxZnakowUslugi = xIDUslugi.size();
			
			if( ileCenaZnakow < xIlosc.size() )
				ileCenaZnakow = xIlosc.size();
			
			tabUslugi.push_back( Uslugi( xIDPobyt , xIDUslugi , xIlosc ) );
		}else
			break;	
	}
	
	while( true )
	{	
		plikBazaPobyt >> PobytIDPobyt >> PobytIDKlient;
			
		if( plikBazaPobyt.good() )
		{
			tabPobyt.push_back( Pobyt( PobytIDPobyt, PobytIDKlient  ) );
		}else
			break;	
	}
	
	while( true )
	{	
		plikBazaKlient >> IDKlientZBazy >> ImieKlientZBazy >> NazwiskoKlientZBazy >> meldunek;
		
		if( ileZnakowMAX < ImieKlientZBazy.size() )	
			ileZnakowMAX = ImieKlientZBazy.size();
			
		if( ileZnakowMAX < NazwiskoKlientZBazy.size() )	
			ileZnakowMAX = NazwiskoKlientZBazy.size();
		
		if( IDKlientZBazy > IDsprawdzID )
			IDsprawdzID = IDKlientZBazy;
		
		if( IDKlientZBazy > IDsprawdzID )
			IDsprawdzID = IDKlientZBazy;
			
		if( plikBazaKlient.good() )
		{
			tabKlient.push_back( Klient( IDKlientZBazy , ImieKlientZBazy , NazwiskoKlientZBazy , meldunek ) );	
		}else
			break;	
	}
	
	while( w < 50 )
	{
		
		plikBazaPokoje >> xID >> xCena >> xStan >> xD1 >> xM1 >> xR1 >> xD2 >> xM2 >> xR2 >> xIDKlient;
		
		if( w < 10 )
			{
				pokoj1.push_back( Pokoj1OS( xID , xCena , xStan , xD1 , xM1 , xR1 , xD2 , xM2 , xR2 , xIDKlient ) );	
			}
				 
		if( w > 9 and w < 30 )
			{
				pokoj2.push_back( Pokoj1OS( xID , xCena , xStan , xD1 , xM1 , xR1 , xD2 , xM2 , xR2 , xIDKlient ) );
			}
			
		if( w > 29 and w < 50 )
			{
				pokoj3.push_back( Pokoj1OS( xID , xCena , xStan , xD1 , xM1 , xR1 , xD2 , xM2 , xR2 , xIDKlient ) );	  
			}
			
		w++;
	}
	
	plikBazaKlient.close();
	plikBazaPokoje.close();
	plikBazaPobyt.close();
	plikBazaUslugi.close();
	plikBazaUslug.close();
	
	while( WProgram )
	{
		WMenu1 = true;
		menu1 = 5;
		while( WMenu1 )
		{
			 ( 27, 44 );
			system("cls");
			
			outKolor( 12 , " +-----------------------+" );
			cout<<endl<<" |      " ;
				outKolor( 14 , "Pobyt menu" );
					outKolor( 12 , "       |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );
			
			cout<<endl<<" | " ;
				outKolor( 14 , "1.Zakwateruj Klienta" );
					outKolor( 12 , "  |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );
			
			cout<<endl<<" | " ;
				outKolor( 14 , "2.Wykwateruj Klienta" );
					outKolor( 12 , "  |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );
			
			cout<<endl<<" | " ;
				outKolor( 14 , "3.Dodaj uslugi  " );
					outKolor( 12 , "      |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );
			
			cout<<endl<<" | " ;
				outKolor( 14 , "4.Wyswietl gosci" );
					outKolor( 12 , "      |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );	
			
			cout<<endl<<" | " ;
				outKolor( 14 , "0.Wyjdz" );
					outKolor( 12 , "               |" );cout<<endl;
			outKolor( 12 , " +-----------------------+" );
			
			cout << endl;
			
			kolor(12); cout << " Wybor: ";
			kolor(14); cin >> menu1;
			
			if( !cin or menu1 > 4 or menu1 < 0 )
			{
				cin.clear();
				cin.sync();
				outKolor( 13 , " !!!---Zla wartosc---!!!");
				pause();
			}else
				{
					WMenu1 = false;
				}
			
		}//while WMenu1
		
		switch( menu1 )
		{
			case 0:
				{
					//zapis uslugi pobytu
					remove("BASE/BazaUslug.txt");
					fstream ZapiszBaze;
					ZapiszBaze.open( "BASE/BazaUslug.txt", ios::app );
					
					for( int f = 0; f < tabBazaUslug.size(); f++ )
						ZapiszBaze << tabBazaUslug[f].getIDPobyt()  << " "
							 	   << tabBazaUslug[f].getIDUsluga() << " "
							 	   << tabBazaUslug[f].getIlosc() 	<< "\n";		
					
					ZapiszBaze.close();
					
					//zapis pobyt
					remove("BASE/BazaPobyt.txt");
					ZapiszBaze;
					ZapiszBaze.open( "BASE/BazaPobyt.txt", ios::app );
					
					for( int f = 0; f < tabPobyt.size(); f++ )
						ZapiszBaze << tabPobyt[f].getIDKlient() << " " 
								   << tabPobyt[f].getIDPokoj()  << "\n";
					
					ZapiszBaze.close();
					
					//zapis klient
					remove("BASE/KlientBaza.txt");
					ZapiszBaze.open( "BASE/KlientBaza.txt", ios::app | ios::in );
					
					for( int f = 0; f < tabKlient.size(); f++ )
						ZapiszBaze << tabKlient[f].getID() 		 << " " 
								   << tabKlient[f].getImie() 	 << " " 
								   << tabKlient[f].getNazwisko() << " "
								   << tabKlient[f].getMeldunek() << "\n";
					
					ZapiszBaze.close();
					
					//zapis pokoje
					remove("BASE/BazaPokoje2.txt");
					ZapiszBaze.open( "BASE/BazaPokoje2.txt", ios::app | ios::in );
					for( int f = 0; f < pokoj1.size(); f++ )
						ZapiszBaze << pokoj1[f].ID               << " " 
								   << pokoj1[f].cena             << " "
								   << pokoj1[f].stan             << " "
								   << pokoj1[f].zajetyOd.dzien   << " "
								   << pokoj1[f].zajetyOd.miesiac << " "
								   << pokoj1[f].zajetyOd.rok     << " "
								   << pokoj1[f].zajetyDo.dzien   << " "
								   << pokoj1[f].zajetyDo.miesiac << " "
								   << pokoj1[f].zajetyDo.rok     << " "
								   << pokoj1[f].IDKlient         << "\n" ;
					
					for( int f = 0; f < pokoj2.size(); f++ )
						ZapiszBaze << pokoj2[f].ID               << " " 
								   << pokoj2[f].cena             << " "
								   << pokoj2[f].stan             << " "
								   << pokoj2[f].zajetyOd.dzien   << " "
								   << pokoj2[f].zajetyOd.miesiac << " "
								   << pokoj2[f].zajetyOd.rok     << " "
								   << pokoj2[f].zajetyDo.dzien   << " "
								   << pokoj2[f].zajetyDo.miesiac << " "
								   << pokoj2[f].zajetyDo.rok     << " "
								   << pokoj2[f].IDKlient         << "\n" ;
								   
					for( int f = 0; f < pokoj3.size(); f++ )
						ZapiszBaze << pokoj3[f].ID               << " " 
								   << pokoj3[f].cena             << " "
								   << pokoj3[f].stan             << " "
								   << pokoj3[f].zajetyOd.dzien   << " "
								   << pokoj3[f].zajetyOd.miesiac << " "
								   << pokoj3[f].zajetyOd.rok     << " "
								   << pokoj3[f].zajetyDo.dzien   << " "
								   << pokoj3[f].zajetyDo.miesiac << " "
								   << pokoj3[f].zajetyDo.rok     << " "
								   << pokoj3[f].IDKlient         << "\n" ;
						
					ZapiszBaze.close();
					
					system("administracja.exe");
					
					return 0;
					break;
				}
				
			case 1:
				{
					if( tabKlient.size() > 0 )
					{
						
						WZamelduj = true;
						kontynuuj = true;
						while( WZamelduj )
						{
							PokojDobry = false;
							KlientDobry = false;
							WMenu1Zakwateruj = true;
							wyborINT = 3;
							while( WMenu1Zakwateruj ) //menu case 1 zakwateruj
							{
								 ( 27, 44 );
								 
								system("CLS");
								
								outKolor( 12 , " +-----------------------+" );
								cout<<endl<<" |    " ;
									outKolor( 14 , "Wybierz Goscia" );
										outKolor( 12 , "     |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								cout<<endl<<" | " ;
									outKolor( 14 , "1.Wyszukaj goscia" );
										outKolor( 12 , "     |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								cout<<endl<<" | " ;
									outKolor( 14 , "2.Pokaz liste" );
										outKolor( 12 , "         |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								cout<<endl<<" | " ;
									outKolor( 14 , "0.Wyjdz" );
										outKolor( 12 , "               |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								cout<<endl;
								
								kolor(12); cout << " Wybor: ";
								kolor(14); cin >> wyborINT;
								
								if( !cin or wyborINT > 2 or wyborINT < 0 )
								{
									cin.clear();
									cin.sync();
									outKolor( 13 , " !!!---Zla wartosc---!!!");
									pause();
								}else
									{
										break;
									}
							}//while true menu case 1 zakwateruj
	
						switch( wyborINT )
						{
							case 0:
								{
									outKolor( 13 , " !!!---Przerwano operacje---!!!");	
									WZamelduj = false;
									kontynuuj = false;
									break;
								}
								
							case 1:
								{
									WZnajdzKlienta = true;
									while( WZnajdzKlienta ) // czy jest taki ziomek
									{
										tabIDweryfikacja.erase( tabIDweryfikacja.begin() , tabIDweryfikacja.end() );
										nazwaKlientSpacja = false;
										IDZgodnosc = false;
										
										system("CLS");
										
										outKolor( 12 , " +-----------------------+" );
										cout<<endl<<" |     " ;
											outKolor( 14 , "Wyszukaj goscia" );
												outKolor( 12 , "   |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
											cout<<endl<<" | " ;
											outKolor( 14 , "0.Cofnij       " );
												outKolor( 12 , "       |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										cout << endl << " Szukaj: ";
									
										cin.clear();
										cin.sync();
										kolor(14); getline( cin , nazwaKlient );
										
										for( int f = 0; f < nazwaKlient.size(); f++ )
											if( nazwaKlient[f] == ' ' ) nazwaKlientSpacja = true;
										
										if( !nazwaKlientSpacja )
										{
											for( int f = 0; f < tabKlient.size(); f++ )
											{
												if( tabKlient[f].getImie() == nazwaKlient or tabKlient[f].getNazwisko() == nazwaKlient )
												{
													kolor(12);
													kreska(ileZnakowMAX);
													cout<<endl<<" | "; kolor(14); cout<<"       ID:"; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(f+1) 			 , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
													kreska(ileZnakowMAX);
													cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() 	 , ileZnakowMAX ) ); kolor(12); cout<<" |";
													cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
													kreska(ileZnakowMAX); cout<<endl;
													tabIDweryfikacja.push_back( f+1 );
												}
											}
											
										}else
											{
												int TEMP = 0;
												string TEMPImie = "",
													   TEMPNazwisko = "";
												
												while( nazwaKlient[TEMP] != ' ' )
												{
													TEMPImie += nazwaKlient[TEMP];
													TEMP++;
												}
												
												TEMP++;
												while( TEMP != nazwaKlient.size() )
												{
													TEMPNazwisko += nazwaKlient[TEMP];
													TEMP++;
												}
												
												for( int f = 0; f < tabKlient.size(); f++ )
												{
													if( tabKlient[f].getImie() == TEMPImie or tabKlient[f].getNazwisko() == TEMPImie or tabKlient[f].getImie() == TEMPNazwisko or tabKlient[f].getNazwisko() == TEMPNazwisko )
													{
														kreska(ileZnakowMAX);
														cout << endl << " | "; kolor(14); cout << "       ID:"; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( string2Int(f+1) 			 , ileZnakowMAX ) ); kolor(12); cout << " |" << endl;
														kreska(ileZnakowMAX);  
														cout << endl << " | "; kolor(14); cout << "Imie:     "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() 	 , ileZnakowMAX ) ); kolor(12); cout << " |";
														cout << endl << " | "; kolor(14); cout << "Nazwisko: "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout << " |" << endl;
														kreska(ileZnakowMAX); cout<<endl;
														tabIDweryfikacja.push_back( f+1 );
													}
												}
											}//else
											
										if( nazwaKlient == "0" )
										{
											outKolor( 13 , "!!!---Przerwano operacje---!!! "); 
											WZamelduj = false;
											WZnajdzKlienta = false;
											kontynuuj = false;
											pause();
											break;
										}else							
											if( tabIDweryfikacja.size() == 0 )
											{
												kolor(13); cout << "!!!---Nie ma takiego klienta---!!!";
												pause();
											}else
												{
													kolor(14); cout << " Podaj ID:";
													kolor(12); cin >> wyborINT;
													
													if( !cin )
													{
														cin.clear();
														cin.sync();
														outKolor( 13 , " !!!---Zla wartosc---!!!");	
														pause();
													}else
														{
															for( int f = 0; f < tabIDweryfikacja.size(); f++ )
																if( wyborINT == tabIDweryfikacja[f] ) 
																{
																	IDZgodnosc = true;
																	break;
																}
																
																if( !IDZgodnosc )
																{
																	outKolor( 13 , " !!!---Zle ID Goscia---!!!");
																	pause();	
																}else
																	{	
																		if( tabKlient[ wyborINT-1 ].getMeldunek() != '0' )
																		{
																			outKolor( 13 , " !!!---Gosc jest juz zameldowany---!!!");
																			pause();
																		}else
																			{
																			 	KlientDobry = true;
																				NowyIDKlientPobyt = wyborINT-1;
																				break;
																			}
																	
																		
																	}				
														}
												}//if sprwadzenie ID goscia	
																											
									}//while
								break;
								}//case 1
								
							case 2:
								{
									while( true )
									{
										system("CLS");
									
										outKolor( 12 , " +-----------------------+" );
										cout<<endl<<" |   " ;
											outKolor( 14 , "Wybierz ID goscia" );
												outKolor( 12 , "   |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
											cout<<endl<<" | " ;
											outKolor( 14 , "0.Cofnij       " );
												outKolor( 12 , "       |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										if( tabKlient.size() > 0 )	
										{	
											cout<<endl;
											for( int f = 0; f < tabKlient.size(); f++ )
											{
												if( tabKlient[ f ].getMeldunek() == '0' )
												{
													kreska(ileZnakowMAX);
														cout<<endl<<" | "; kolor(14); cout<<"ID:       "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(f+1) , ileZnakowMAX ) ); kolor(12); cout<<" |";
														cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
														cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
													kreska(ileZnakowMAX);
												}
											}
											
											
											cout<<endl<<" ID: ";	
											kolor(14);
											cin>>wyborINT;
											
											if( !cin )
											{
												cin.clear();
												cin.sync();
												outKolor( 13 , "!!!---Zla wartosc---!!! "); 
											}else
												if( wyborINT == 0 )
												{
													outKolor( 13 , "!!!---Przerwano operacje---!!! "); 
													WZamelduj = false;
													WZnajdzKlienta = false;
													kontynuuj = false;
													pause();
													break;
												}else
													if( wyborINT < 0 or wyborINT > tabKlient.size() )
													{
														outKolor( 13 , "!!!---Zla wartosc---!!! "); 
													}else
														{
															if( tabKlient[ wyborINT-1 ].getMeldunek() != '0' )
															{
																outKolor( 13 , " !!!---Gosc jest juz zameldowany---!!!");
																pause();
															}else
																{
																 	KlientDobry = true;
																	NowyIDKlientPobyt = wyborINT-1;
																	break;
																}
														}				
										}else
											{
												outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); 
											}
										}
								
								break;
								}//case 2
								
							
							
							}// swtich wyborINT z zamelduj
							
							bool WSwitch2 = true;
							while( WSwitch2 and kontynuuj )
							{
								while( true )
									{
										 ( 27, 44 );
										system("CLS");
										outKolor( 12 , " +-----------------------+" );
										cout<<endl<<" |    " ;
											outKolor( 14 , "Wybierz pokoj" );
												outKolor( 12 , "      |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										cout<<endl<<" | " ;
											outKolor( 14 , "1.Podaj numer pokoju" );
												outKolor( 12 , "  |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										cout<<endl<<" | " ;
											outKolor( 14 , "2.Pokaz liste" );
												outKolor( 12 , "         |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										cout<<endl<<" | " ;
											outKolor( 14 , "0.Wyjdz" );
												outKolor( 12 , "               |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										cout<<endl;
										
										kolor(12); cout << " Wybor: ";
											kolor(14); cin >> wyborINT;
											
											if( !cin or wyborINT > 2 or wyborINT < 0 )
											{
												cin.clear();
												cin.sync();
												outKolor( 13 , " !!!---Zla wartosc---!!!");
												pause();
											}else
												{
													break;
												}
									}
									
								switch( wyborINT )
									{
										case 0:
										{
											outKolor( 13 , " !!!---Przerwano operacje---!!!");	
											WSwitch2 = false;
											WZamelduj = false;
											break;
										}
										
										case 1:
											{
												while( true )
												{
													system("CLS");
													outKolor( 12 , " +-----------------------+" );
											
													cout<<endl<<" | " ;
														outKolor( 14 , "1.Podaj numer pokoju" );
															outKolor( 12 , "  |" ); cout << endl;
													outKolor( 12 , " +-----------------------+" );
													
													cout<<endl<<" | " ;
														outKolor( 14 , "0.Wyjdz" );
															outKolor( 12 , "               |" );cout<<endl;
													outKolor( 12 , " +-----------------------+" );
													
													kolor(12); cout << endl << " Wybor: ";
													kolor(14); cin >> wyborINT;
													
													if( wyborINT == 0 )
													{
														outKolor( 13 , " !!!---Przerwano operacje---!!!");	
														WSwitch2 = false;
														WZamelduj = false;
														break;
													}else
													
													if( !cin )
													{
														cin.clear();
														cin.sync();
														outKolor( 13 , " !!!---Zla wartosc---!!!");
														pause();
													}else
														{
															if( wyborINT > 100 and wyborINT < 111 or 
																wyborINT > 200 and wyborINT < 211 or 
																wyborINT > 300 and wyborINT < 311 or 
																wyborINT > 400 and wyborINT < 411 or 
																wyborINT > 500 and wyborINT < 511 )
																{
																	tmpNrPokoju = wyborINT;
																		
																		if( wyborINT > 100 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 200 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 300 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 400 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 500 )
																			tmpNrPokoju -= 100;
																	
																	if( wyborINT > 100 and wyborINT < 111 and pokoj1[ tmpNrPokoju - 1 ].getStan() ) 
																		{
																			NowyIDPokojPobyt = pokoj1[ tmpNrPokoju - 1 ].ID;
																			pokoj1[ tmpNrPokoju - 1 ].stan = '1';
																			PokojDobry = true;
																			break;	
																		}else
																			if( wyborINT > 200 and wyborINT < 211 and pokoj2[ tmpNrPokoju - 1 ].getStan() == true )
																			{
																				NowyIDPokojPobyt = pokoj2[ tmpNrPokoju - 1 ].ID;
																				pokoj2[ tmpNrPokoju - 1 ].stan = '1';
																				PokojDobry = true;
																				break;	
																			}else
																				if( wyborINT > 300 and wyborINT < 311 and pokoj2[ tmpNrPokoju + 9 ].getStan() == true ) 
																				{
																					NowyIDPokojPobyt = pokoj2[ tmpNrPokoju + 9 ].ID;
																					pokoj2[ tmpNrPokoju + 9 ].stan = '1';
																					PokojDobry = true;
																					break;
																				}else
																					if( wyborINT > 400 and wyborINT < 411 and pokoj3[ tmpNrPokoju - 1 ].getStan() == true ) 
																					{
																						NowyIDPokojPobyt = pokoj3[ tmpNrPokoju - 1 ].ID;
																						pokoj3[ tmpNrPokoju - 1 ].stan = '1';
																						PokojDobry = true;
																						break;	
																					}else
																						if( wyborINT > 500 and wyborINT < 511 and pokoj3[ tmpNrPokoju + 9 ].getStan() == true )
																						{
																							NowyIDPokojPobyt = pokoj3[ tmpNrPokoju + 9 ].ID;
																							pokoj3[ tmpNrPokoju + 9 ].stan = '1';
																							PokojDobry = true;
																							break;	
																						}else
																							{
																								cout << "!!!---Pokoj jest zajety---!!!";
																								pause();
																							}
																
																}else
																	{
																		outKolor( 13 , " !!!---Zla wartosc---!!!");
																		kolor(8); cout<<" Nacisnij dowolny przycisk..."<<endl;
																		pause();
																	}
														}
													
												}//while menu
												
												break;									
											}// case 1
											
										case 2:
											{
												while( true )
												{
													system("CLS");
													PrintPokoje( pokoj1 , pokoj2 , pokoj3 );
													
													kolor(12); cout << endl << " Wybor: ";
													kolor(14); cin >> wyborINT;
														
													if( wyborINT == 0 )
													{
														outKolor( 13 , " !!!---Przerwano operacje---!!!");	
														WSwitch2 = false;
														WZamelduj = false;
														break;
													}else
														if( !cin )
															{
																cin.clear();
																cin.sync();
																outKolor( 13 , " !!!---Zla wartosc---!!!");
																pause();
															}else
																if( wyborINT > 100 and wyborINT < 111 or 
																	wyborINT > 200 and wyborINT < 211 or 
																	wyborINT > 300 and wyborINT < 311 or 
																	wyborINT > 400 and wyborINT < 411 or 
																	wyborINT > 500 and wyborINT < 511 )
																	{
																		
																		tmpNrPokoju = wyborINT;
																		
																		if( wyborINT > 100 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 200 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 300 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 400 )
																			tmpNrPokoju -= 100;
																			
																		if( wyborINT > 500 )
																			tmpNrPokoju -= 100;
																			
																		
																		if( wyborINT > 100 and wyborINT < 111 and pokoj1[ tmpNrPokoju - 1 ].getStan() ) 
																		{
																			NowyIDPokojPobyt = pokoj1[ tmpNrPokoju - 1 ].ID;
																			pokoj1[ tmpNrPokoju - 1 ].stan = '1';
																			PokojDobry = true;																	
																			break;	
																		}else
																			if( wyborINT > 200 and wyborINT < 211 and pokoj2[ tmpNrPokoju - 1 ].getStan() == true )
																			{
																				NowyIDPokojPobyt = pokoj2[ tmpNrPokoju - 1 ].ID;
																				pokoj2[ tmpNrPokoju - 1 ].stan = '1';
																				PokojDobry = true;
																				break;	
																			}else
																				if( wyborINT > 300 and wyborINT < 311 and pokoj2[ tmpNrPokoju + 9 ].getStan() == true ) 
																				{
																					NowyIDPokojPobyt = pokoj2[ tmpNrPokoju + 9 ].ID;
																					pokoj2[ tmpNrPokoju + 9 ].stan = '1';
																					PokojDobry = true;
																					break;	
																				}else
																					if( wyborINT > 400 and wyborINT < 411 and pokoj3[ tmpNrPokoju - 1 ].getStan() == true ) 
																					{
																						NowyIDPokojPobyt = pokoj3[ tmpNrPokoju - 1 ].ID;
																						pokoj3[ tmpNrPokoju - 1 ].stan = '1';
																						PokojDobry = true;
																						break;	
																					}else
																						if( wyborINT > 500 and wyborINT < 511 and pokoj3[ tmpNrPokoju + 9 ].getStan() == true )
																						{
																							NowyIDPokojPobyt = pokoj3[ tmpNrPokoju + 9 ].ID;
																							pokoj3[ tmpNrPokoju + 9 ].stan = '1';
																							PokojDobry = true;
																							break;	
																						}else
																							{
																								cout << "!!!---Pokoj jest zajety---!!!";
																								pause();
																							}
																	}else
																		{
																			cout<<endl;
																			outKolor( 13 , " !!!---Zla wartosc---!!!");
																			kolor(8); cout<<" Nacisnij dowolny przycisk..."<<endl;
																			pause();
																		}
												}
												
											break;
											}//case 2
										
											
									}//switch pokoje w pobyt
									
								if( KlientDobry and PokojDobry )
								{
									tabPobyt.push_back( Pobyt( NowyIDKlientPobyt , NowyIDPokojPobyt ) );
									tabKlient[ NowyIDKlientPobyt ].setMeldunek( '1' );
									cout << "!!!---Zakwaterowano---!!!";
									pause();
									WZamelduj = false;
									WMenu1Zakwateruj = false;
									break;
								}
									
								
							}//while ogolny do pokoi
									
							
						}//while WZamelduj
						
						
					}else
						{
							kolor(13); cout << "!!!---Brak klientow w bazie---!!!";
							pause();	
						}	
					break;	
				}// menu  case 1
				
			case 2: // glowny
				{
					if( tabPobyt.size() > 0 )
					{
						WZamelduj = true;
						kontynuuj = true;
									
						while( WZamelduj )
						{
							PokojDobry = false;
							KlientDobry = false;
							WMenu1Zakwateruj = true;
							wyborINT = 3;
							
							while( WMenu1Zakwateruj ) //menu case 1 zakwateruj
							{
								 ( 27, 44 );
								system("CLS");
								
								outKolor( 12 , " +-----------------------+" );
								cout<<endl<<" |    " ;
									outKolor( 14 , "Wybierz Goscia" );
										outKolor( 12 , "     |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
												
								cout<<endl<<" | " ;
									outKolor( 14 , "1.Pokaz liste" );
										outKolor( 12 , "         |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								cout<<endl<<" | " ;
									outKolor( 14 , "0.Wyjdz" );
										outKolor( 12 , "               |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								cout<<endl;
								
								kolor(12); cout << " Wybor: ";
								kolor(14); cin >> wyborINT;
								
								if( !cin or wyborINT > 1 or wyborINT < 0 )
								{
									cin.clear();
									cin.sync();
									outKolor( 13 , " !!!---Zla wartosc---!!!");
									pause();
								}else
									{
										break;
									}
							}//while true menu case 1 zakwateruj
							
							switch( wyborINT )
							{
								case 0:
									{
										outKolor( 13 , " !!!---Przerwano operacje---!!!");	
										pause();
										WZamelduj = false;
										kontynuuj = false;
										WMenu1Zakwateruj = false;
										break;
									}
								
								case 1:
									{
										kontynuuj = true;
										while( true )
										{
											system("CLS");
										
											outKolor( 12 , " +-----------------------+" );
											cout<<endl<<" |   " ;
												outKolor( 14 , "Wybierz ID goscia" );
													outKolor( 12 , "   |" );cout<<endl;
											outKolor( 12 , " +-----------------------+" );
											
												cout<<endl<<" | " ;
												outKolor( 14 , "0.Cofnij       " );
													outKolor( 12 , "       |" );cout<<endl;
											outKolor( 12 , " +-----------------------+" );
											
											if( tabPobyt.size() > 0 )	
											{	
												cout<<endl;
												for( int f = 0; f < tabPobyt.size(); f++ )
												{
													kreska(ileZnakowMAX);
													cout<<endl<<" | "; 
														kolor(14); cout<<"ID:       "; 
															kolor(12); cout<<"| "; 
																outKolor( 14 , wyrownaj( string2Int(f+1) , ileZnakowMAX ) ); 
															kolor(12); cout<<" |";
												
													cout<<endl<<" | "; 
														kolor(14); cout<<"Imie:     "; 
															kolor(12); cout<<"| "; 
																outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getImie() , ileZnakowMAX ) ); 
															kolor(12); cout<<" |";
													
													cout<<endl<<" | "; 
														kolor(14); cout<<"Nazwisko: "; 
															kolor(12); cout<<"| "; 
																outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getNazwisko() , ileZnakowMAX ) ); 
															kolor(12); cout<<" |"<<endl;
												}
												
												kreska(ileZnakowMAX);
												
												cout << endl << " ID: ";	
												kolor(14);
												cin >> wyborINT;
												
												if( !cin )
												{
													cin.clear();
													cin.sync();
													outKolor( 13 , "!!!---Zla wartosc---!!! "); 
												}else
													if( wyborINT == 0 )
													{
														outKolor( 13 , " !!!---Przerwano operacje---!!!");	
														pause();
														WZamelduj = false;
														kontynuuj = false;
														WMenu1Zakwateruj = false;
														break;
													}else
														if( wyborINT < 0 or wyborINT > tabPobyt.size() )
														{
															outKolor( 13 , "!!!---Zla wartosc---!!! ");
															pause(); 
														}else
															{
																WZamelduj = false; // konczy case
															 	KlientDobry = true;
																NowyIDKlientPobyt = wyborINT - 1;
																															
																if( tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() <= 10  )
																	pokoj1[ tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() - 1 ].stan = '0';
																	
													       else if( tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() <= 30 )
														  			pokoj2[ tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() - 11 ].stan = '0';
														  			
														   else if( tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() <= 50  )
														   			pokoj3[ tabPobyt[ NowyIDKlientPobyt ].getIDPokoj() - 31 ].stan = '0';
														   			
														   	tabKlient[ tabPobyt[ NowyIDKlientPobyt ].getIDKlient() ].setMeldunek('0');
															  		
														   	tabPobyt.erase( tabPobyt.begin() + NowyIDKlientPobyt );
														   			
																outKolor( 13 , "!!!---Wymeldowano goscia---!!! ");
																pause();
																break;
															}				
											}else
												{
													cout << endl;
													outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); 
													pause();
													kontynuuj = false;
													WZamelduj = false;
													break;
												}
										}
										
										
										
										
										break;
									}//case 1 
							}
						}//while kejs
						
					}// if pusto
					else
						{
							outKolor( 13 , "!!!---Brak zameldowanych Gosci---!!! "); 
							pause();
						}
						
				break;	
				}//menu case 2
				
			case 3: // glowy
				{
					if( tabUslugi.size() > 0 )
					{
						WZamelduj = true;
						kontynuuj = true;
						
						while( WZamelduj )
						{
							PokojDobry = false;
							KlientDobry = false;
							WMenu1Zakwateruj = true;
							wyborINT = 3;
							
							while( WMenu1Zakwateruj ) //menu case 1 zakwateruj
							{
								 ( 27, 44 );
								system("CLS");
								
								outKolor( 12 , " +-----------------------+" );
								cout<<endl<<" |    " ;
									outKolor( 14 , "Wybierz Goscia" );
										outKolor( 12 , "     |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
												
								cout<<endl<<" | " ;
									outKolor( 14 , "1.Pokaz liste" );
										outKolor( 12 , "         |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								cout<<endl<<" | " ;
									outKolor( 14 , "0.Wyjdz" );
										outKolor( 12 , "               |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								cout<<endl;
								
								kolor(12); cout << " Wybor: ";
								kolor(14); cin >> wyborINT;
								
								if( !cin or wyborINT > 1 or wyborINT < 0 )
								{
									cin.clear();
									cin.sync();
									outKolor( 13 , " !!!---Zla wartosc---!!!");
									pause();
								}else
									{
										break;
									}
							}//while true menu case 1 zakwateruj
	
						switch( wyborINT )
						{
							case 0:
								{
									outKolor( 13 , " !!!---Przerwano operacje---!!!");	
									WZamelduj = false;
									kontynuuj = false;
									break;
								}
								
							case 1:
								{
									kontynuuj = true;
									while( true )
									{
										system("CLS");
									
										outKolor( 12 , " +-----------------------+" );
										cout<<endl<<" |   " ;
											outKolor( 14 , "Wybierz ID goscia" );
												outKolor( 12 , "   |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
											cout<<endl<<" | " ;
											outKolor( 14 , "0.Cofnij       " );
												outKolor( 12 , "       |" );cout<<endl;
										outKolor( 12 , " +-----------------------+" );
										
										if( tabPobyt.size() > 0 )	
										{	
											cout<<endl;
											for( int f = 0; f < tabPobyt.size(); f++ )
											{
												
												kreska(ileZnakowMAX);
												cout<<endl<<" | "; 
													kolor(14); cout<<"ID:       "; 
														kolor(12); cout<<"| "; 
															outKolor( 14 , wyrownaj( string2Int(f+1) , ileZnakowMAX ) ); 
														kolor(12); cout<<" |";
											
												cout<<endl<<" | "; 
													kolor(14); cout<<"Imie:     "; 
														kolor(12); cout<<"| "; 
															outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getImie() , ileZnakowMAX ) ); 
														kolor(12); cout<<" |";
												
												cout<<endl<<" | "; 
													kolor(14); cout<<"Nazwisko: "; 
														kolor(12); cout<<"| "; 
															outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getNazwisko() , ileZnakowMAX ) ); 
														kolor(12); cout<<" |"<<endl;
												
											}
											
											kreska(ileZnakowMAX);
											
											cout << endl << " ID: ";	
											kolor(14);
											cin >> wyborINT;
											
											if( !cin )
											{
												cin.clear();
												cin.sync();
												outKolor( 13 , "!!!---Zla wartosc---!!! "); 
											}else
												if( wyborINT == 0 )
												{
													outKolor( 13 , "!!!---Przerwano operacje---!!! "); 
													pause();
													kontynuuj = false;
													break;
												}else
													if( wyborINT < 0 or wyborINT > tabPobyt.size() )
													{
														outKolor( 13 , "!!!---Zla wartosc---!!! ");
														pause(); 
													}else
														{
														 	KlientDobry = true;
															NowyIDKlientPobyt = wyborINT-1;	
															break;
														}
										}else
											{
												cout << endl;
												outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); 
												pause();
												kontynuuj = false;
												WZamelduj = false;
												break;
											}
									}
								
								break;
								}//case 1
									
							}//switch case 3 uslugi	
							
							bool WorkInUslugi = true;
							
							while( WorkInUslugi and kontynuuj )
							{
								system("CLS");
										
								outKolor( 12 , " +-----------------------+" );
								cout<<endl<<" |   " ;
									outKolor( 14 , "Wybierz ID Uslugi" );
										outKolor( 12 , "   |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
									cout<<endl<<" | " ;
									outKolor( 14 , "0.Cofnij       " );
										outKolor( 12 , "       |" );cout<<endl;
								outKolor( 12 , " +-----------------------+" );
								
								int ileMenuZnakow = 2;
								
								if( tabUslugi.size() >  100 )
									ileMenuZnakow += 1;
								
								string tempA = " ";
								
								cout << endl;
								ileCenaZnakow+=1;
								kreska2( MaxZnakowUslugi , ileMenuZnakow , ileCenaZnakow );
								
								cout << endl;
									kolor(12); cout << " | ";
										kolor(14); cout << "ID";
										kolor(12); cout << " |" ;
										kolor(14); cout << wyrownaj( "              Nazwa " , MaxZnakowUslugi+1 );
										kolor(12); cout << " | ";
										kolor(14); cout << "Cena";
										kolor(12); cout << " |";
									
								for( int f = 0; f < tabUslugi.size(); f++ )
								{
									if( f  < 10 )
										tempA = " ";
											else tempA = "";
											
									cout<<endl;
									kreska2( MaxZnakowUslugi , ileMenuZnakow , ileCenaZnakow );
									
									cout << endl;
									
									kolor(12); cout << " | "; 
										kolor(14); cout << tempA << tabUslugi[f].getID(); 
										 
									kolor(12); cout << " | ";  
										kolor(14); cout<< wyrownaj( tabUslugi[f].getNazwa() , MaxZnakowUslugi );
									
									kolor(12); cout << " | ";  
										kolor(14); cout<< wyrownaj( tabUslugi[f].getCena() , ileCenaZnakow );  kolor(12); cout << " |" <<  endl ;
									
									kreska2( MaxZnakowUslugi , ileMenuZnakow , ileCenaZnakow );
								}
								
								cout << endl << " Wybor:";
								kolor(14); cin >> wyborINT;
								
								if( !cin )
								{
									cin.clear();
									cin.sync();
									outKolor( 13 , "!!!---Zla wartosc---!!! "); 
									pause();
								}else
									{ 
										if( wyborINT == 0 )
										{
											WorkInUslugi = false;
											outKolor( 13 , "!!!---Przerwano operacje---!!! "); 
											pause();
											break;
										}else
											if( wyborINT < 1 or wyborINT > tabUslugi.size() )
											{
												outKolor( 13 , "!!!---Zla wartosc---!!! "); 
												pause();
											}else
												{
													tmpIDKlient = wyborINT-1;	
													
													system("CLS");
													while( true )
													{
														outKolor( 12 , " +-----------------------+" );
														cout<<endl<<" | " ;
															outKolor( 14 , "0.Cofnij       " );
																outKolor( 12 , "       |" );cout<<endl;
														outKolor( 12 , " +-----------------------+" );
																				
														cout<<endl;
														kreska2( MaxZnakowUslugi , ileMenuZnakow , ileCenaZnakow );
														
														cout << endl;
														
														if( tmpIDKlient  < 10 )
															tempA = " ";
																else tempA = "";
														
														kolor(12); cout << " | "; 
															kolor(14); cout << tempA << tabUslugi[tmpIDKlient].getID(); 
															 
														kolor(12); cout << " | ";  
															kolor(14); cout<< wyrownaj( tabUslugi[tmpIDKlient].getNazwa() , MaxZnakowUslugi );
														
														kolor(12); cout << " | ";  
															kolor(14); cout<< wyrownaj( tabUslugi[tmpIDKlient].getCena() , ileCenaZnakow );  kolor(12); cout << " |" <<  endl ;
														
														kreska2( MaxZnakowUslugi , ileMenuZnakow , ileCenaZnakow );
														
														cout << endl << " Ilosc:";
														kolor(14); cin >> wyborINT;
														
														if( !cin )
														{
															cin.clear();
															cin.sync();
															outKolor( 13 , "!!!---Zla wartosc---!!! "); 
															pause();
														}else
															if( wyborINT == 0 )
															{
																WorkInUslugi = false;
																outKolor( 13 , "!!!---Przerwano operacje---!!! "); 
																pause();
																break;
															}else
																{
																	kontynuuj = false;
																	WorkInUslugi = false;
																	WZamelduj = false;
																	bool findit = false;
																	
																	for( int f = 0; f < tabBazaUslug.size(); f++ )
																		if( tabBazaUslug[f].getIDPobyt() == NowyIDKlientPobyt and tabBazaUslug[f].getIDUsluga() == tmpIDKlient )
																		{
																			tabBazaUslug[f].setIlosc( tabBazaUslug[f].getIlosc() + wyborINT ); 
																			findit = true;
																			break;
																		}
																																			
																		if( !findit )
																			tabBazaUslug.push_back( BazaUslug( NowyIDKlientPobyt+1 , tmpIDKlient , wyborINT ) );
																	
																	outKolor( 13 , "!!!---Dodano usloge gosciowi---!!! "); 
																	pause();
																	break;
																}
																				
													}//while true
													
													
												}
									}
								
							}
							
						}//while case 3 uslugi glowny
						
					}else
						{
							kolor(13); cout << "!!!---Nie ma uslug---!!!";
							pause();
						}
						
					break;
				}//menu case 3
			
			case 4:
				{
					system("CLS");
										
					outKolor( 12 , " +-----------------------+" );
					cout<<endl<<" |     " ;
						outKolor( 14 , "Goscie hotelu" );
							outKolor( 12 , "     |" );cout<<endl;
					outKolor( 12 , " +-----------------------+" );
					
					if( tabPobyt.size() > 0 )	
					{	int tempa;
						cout<<endl;
						for( int f = 0; f < tabPobyt.size(); f++ )
						{	
							ileUslug = 0;	
							kolor(12); kreska2( ileZnakowMAX , ileZnakowMAX , ileZnakowMAX );				
							
							cout << endl;
							
							kolor(12); cout<<" | "; 
								outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getImie() , ileZnakowMAX ) ); 
							kolor(12); cout<<" | ";
							
							outKolor( 14 , wyrownaj( tabKlient[ tabPobyt[f].getIDKlient() ].getNazwisko() , ileZnakowMAX ) ); 
								kolor(12); cout<<" | ";
							
							if( tabPobyt[ f ].getIDPokoj() <= 10  )
								tempa = pokoj1[ tabPobyt[ f ].getIDPokoj() - 1 ].ID + 100;
								
				       else if( tabPobyt[ f ].getIDPokoj() <= 20 )
					  			tempa = pokoj2[ tabPobyt[ f ].getIDPokoj() - 11 ].ID + 190;
					  			
					   else if( tabPobyt[ f ].getIDPokoj() <= 30 )
					  			tempa = pokoj2[ tabPobyt[ f ].getIDPokoj() - 11 ].ID + 280;
								    		
					   else if( tabPobyt[ f ].getIDPokoj() <= 40  )
					   			tempa = pokoj3[ tabPobyt[ f ].getIDPokoj() - 31 ].ID + 370;
					   			
					   else if( tabPobyt[ f ].getIDPokoj() <= 50  )
					   			tempa = pokoj3[ tabPobyt[ f ].getIDPokoj() - 31 ].ID + 460;
					   			
							outKolor( 14 , wyrownaj( string2Int( tempa ) , ileZnakowMAX ) );	
							kolor(12); cout <<" | "<<endl;
							
							kreska2( ileZnakowMAX , ileZnakowMAX , ileZnakowMAX ); 	cout << endl;			
							
							outKolor( 10 , wyrownaj( " Uslugi:" , ileZnakowMAX ) ); 
							cout << endl;
								
							for( int f2 = 0; f2 < tabBazaUslug.size(); f2++ )
							{
								if( tabBazaUslug[f2].getIDPobyt() == tabKlient[ tabPobyt[f].getIDKlient() ].getID() )
								{
									kolor(12); cout << "\t "; 
										kolor(10); cout << "Nazwa: "; 	kolor(11); cout << tabUslugi[ tabBazaUslug[f2].getIDUsluga() ].getNazwa();
										kolor(10); cout << " Cena: "; 	kolor(11); cout << tabUslugi[ tabBazaUslug[f2].getIDUsluga() ].getCena();
										kolor(10); cout << " Ilosc: "; 	kolor(11); cout << tabBazaUslug[f2].getIlosc() << endl;	
									ileUslug += 1;
								}	
							}
							
							if( ileUslug == 0 )
								{	
									kolor(10); 
									cout << "\tBrak " << endl; 
								}
											
						}
						
					pause();
					}else
						{
							cout << endl;
							outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); 
							pause();
							break;
						}
					
					
					break;
				}
			
			
				
		}//switch menu1
		
	}//while WProgram

	return 0;
}
