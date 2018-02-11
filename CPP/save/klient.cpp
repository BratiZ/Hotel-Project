#include "funkcje.hpp"// tu sa funkcje 

int main(int argc, char** argv) {
	//remove - usuwanie kek
	
	fstream plik;
	
	plik.open( "BASE/KlientBaza.txt" , ios::app | ios::in ); //otworz plik
	
	if (  !plik.is_open() )
	{
		outKolor( 4 , "Nie mozna otworzyc pliku!" ); //sprawdz czy otwarty
		pause();
	}
		
	vector< Klient > tabKlient;
			
	string ImieKlientZBazy,
		   NazwiskoKlientZBazy,
		   tempEdytuj;
	
	char TEMPwybor,
		 sprawdzWybor,
		 meldunek = '0'; 
	
	int IDKlientZBazy = 0,
		wyborMenu1,
		IDKlientSTAN = 0,
		IDsprawdzID = 0,
		flgUsunKlienta = 0,
		wybor,
		menuEdytuj,
		ileZnakowMAX = 0;
	
	bool dobryWybor = false,
		 program = true,
		 UsuwanieWybor = false;

	while( true )
	{
		plik >> IDKlientZBazy >> ImieKlientZBazy >> NazwiskoKlientZBazy >> meldunek;
		
		if( ileZnakowMAX < ImieKlientZBazy.size() )	
			ileZnakowMAX = ImieKlientZBazy.size();
			
		if( ileZnakowMAX < NazwiskoKlientZBazy.size() )	
			ileZnakowMAX = NazwiskoKlientZBazy.size();
		
		if( IDKlientZBazy > IDsprawdzID )
			IDsprawdzID = IDKlientZBazy;
		
		if( plik.good() )
		{
			tabKlient.push_back( Klient( IDKlientZBazy , ImieKlientZBazy , NazwiskoKlientZBazy , meldunek ) );
		}else
			break;	
	}
	
	plik.close();
	
	//wczytanie klientow do programu
	
	while( program )
	{
		dobryWybor = false;
		while( !dobryWybor )
		{
			system("CLS");
			 ( 27, 22 );
			printMenu( 12 , 14 ); //menu z kolorami x <- ramka y <- napisy
			
			cin>>TEMPwybor;
		
			if( TEMPwybor == '0' or TEMPwybor == '1' or TEMPwybor == '2' or TEMPwybor == '3' or TEMPwybor =='4' )
			{
				wyborMenu1 = TEMPwybor - 48;	
				dobryWybor = true;
			}else
				{
					outKolor( 13 , " !!!---Zla wartosc!---!!!");
					pause();
				}		
		}//while menu 1
		
		switch( wyborMenu1 )
		{
			case 0:
				{
					remove("BASE/KlientBaza.txt");
					fstream ZapiszBaze;
					ZapiszBaze.open( "BASE/KlientBaza.txt", ios::app | ios::in );
					
					for( int f = 0; f < tabKlient.size(); f++ )
						ZapiszBaze << tabKlient[f].getID() << " " 
								   << tabKlient[f].getImie() << " " 
								   << tabKlient[f].getNazwisko() << " "
								   << tabKlient[f].getMeldunek() << "\n";
					
					ZapiszBaze.close();
					
					system("administracja.exe");
					
					return 0;
					break;
				}
				
			case 1:
				{
					 ( 27, 22 );
					wybor = 2;
					while( wybor < 0 or wybor > 1 )
					{
						system("cls");
					
						outKolor( 12 , " +----------------------+" ); cout<<endl;
						cout<<" |"; outKolor( 14 , "    Dodaj Klienta     "); outKolor( 12 , "|" ); 
						cout<<endl<<" +----------------------+"<<endl;
						
						cout<<" |"; outKolor( 14 , " 1. Dodaj             "); outKolor( 12 , "|" ); 
						cout<<endl<<" +----------------------+"<<endl;
					
						cout<<" |"; outKolor( 14 , " 0. Wroc do menu      "); outKolor( 12 , "|" ); 
						cout<<endl<<" +----------------------+"<<endl;
						
						outKolor( 12 , " Wybor: "); 
						kolor(14); cin>>wybor;
						
						if( !cin )
						{
							cin.clear();
							cin.sync();
							outKolor( 13 , " !!!---Zla wartosc---!!!");
							pause();
						}else if( wybor != 1 and wybor != 0 )
								{
									outKolor( 13 , " !!!---Zla wartosc---!!!");
									pause();
								}
					}
					
					if( wybor != 0 )
					{
						
						outKolor( 12 , " Podaj imie: " );
						
						kolor(14);
						cin>>ImieKlientZBazy;
						
						outKolor( 12 , " Podaj Nazwisko: " ); 
						
						kolor(14);
						cin>>NazwiskoKlientZBazy;
				
						tabKlient.push_back( Klient( ++IDsprawdzID , ImieKlientZBazy , NazwiskoKlientZBazy , '0' ) );
						outKolor( 10 , " !!!---Dodano Klienta---!!!");
						
						if( NazwiskoKlientZBazy.size() > ileZnakowMAX )
							ileZnakowMAX = NazwiskoKlientZBazy.size();
							
						if( ImieKlientZBazy.size() > ileZnakowMAX )
							ileZnakowMAX = ImieKlientZBazy.size();
					}else
						outKolor( 13 , " !!!---Przerwano operacje---!!!");	
					
					kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
					pause();	
					
					break;
				}//case 1 dodaj klienta
				
			case 2:
				{	
					system("CLS");
					
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |    " ;
						outKolor( 14 , "Usun Klienta" );
							outKolor( 12 , "      |" );
					cout<<endl; 
							
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |    " ;
						outKolor( 14 , " Wybierz ID " );
							outKolor( 12 , "      |" );
					cout<<endl;	
								
					outKolor( 12 , " +----------------------+" );
					cout<<endl<<" |   ";
						 outKolor( 14 , "0. Wyjdz do menu" );
							outKolor( 12 , "   |" );cout<<endl;
							
					outKolor( 12 , " +----------------------+" );
					cout<<endl;
					
					if( tabKlient.size() > 0 )	
					{	
						cout<<endl;
						for( int f = 0; f < tabKlient.size(); f++ )
						{							
							kreska(ileZnakowMAX);
							cout<<endl<<" | "; kolor(14); cout<<"ID:       "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(f+1) 			 , ileZnakowMAX ) ); kolor(12); cout<<" |";
							cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() 	 , ileZnakowMAX ) ); kolor(12); cout<<" |";
							cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
						}
						kreska(ileZnakowMAX);
					
						cout<<endl<<" Wybor: ";
						
						kolor(14);
						cin>>wybor;
						
						if( wybor != 0 )
						{
							if( tabKlient[wybor-1].getMeldunek() == '1' )
							{
								outKolor( 13 , " !!!---Gosc jest zameldowany!---!!!");
								
							}else
								{
									outKolor( 13 , " Czy napewno chcesz usunac Klienta?(Y/N): ");
									cin>>sprawdzWybor;
								
									if( sprawdzWybor == 'Y' or sprawdzWybor == '1' or sprawdzWybor == 'y' )
									{
										tabKlient.erase( tabKlient.begin() + wybor - 1 );
										outKolor( 10 , " !!!---Usunieto Klienta---!!!");
										UsuwanieWybor = true;
									}else
										outKolor( 13 , " !!!---Przerwano operacje---!!!");	
								}
								
						}
					}else
						{		
							outKolor( 5 , " +-----------------------------------+" );
								cout<<endl<<" | "; outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); kolor(5); cout<< "|"<<endl
								<<" +-----------------------------------+"<<endl;
						}
							
						kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
						pause();
					break;
				}//case 2 usun klienta
				
			case 3:
				{
					 ( 27, 22 );
					system("CLS");
					
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |   " ;
						outKolor( 14 , "Edytuj Klienta" );
							outKolor( 12 , "     |" );
					cout<<endl; 
							
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |    " ;
						outKolor( 14 , " Wybierz ID " );
							outKolor( 12 , "      |" );
					cout<<endl;	
								
					outKolor( 12 , " +----------------------+" );
					cout<<endl<<" |   ";
						 outKolor( 14 , "0. Wyjdz do menu" );
							outKolor( 12 , "   |" );cout<<endl;
							
					outKolor( 12 , " +----------------------+" );
					cout<<endl;
					
					if( tabKlient.size() > 0 )	
					{	
						cout<<endl;
						for( int f = 0; f < tabKlient.size(); f++ )
						{
							kreska(ileZnakowMAX);
							cout<<endl<<" | "; kolor(14); cout<<"ID:       "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(f+1) , ileZnakowMAX ) ); kolor(12); cout<<" |";
							cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
							cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
						}
						kreska(ileZnakowMAX);
						cout<<endl<<" ID: ";	
						kolor(14);
						cin>>wybor;
						
						if( wybor != 0 )
						{
							while( true )
							{
								system("cls");
							
								outKolor( 12 , " +----------------------+");
								cout<<endl<<" |   " ;
								outKolor( 14 , "Edytuj Klienta" );
								outKolor( 12 , "     |" );
								cout<<endl; 
								outKolor( 12 , " +----------------------+");
							
								cout<<endl<<" |" ;
								outKolor( 14 , " 1. Zmien imie: " );
								outKolor( 12 , "      |" );
								cout<<endl; 
								outKolor( 12 , " +----------------------+");
								
								cout<<endl<<" |" ;
								outKolor( 14 , " 2. Zmien Nazwisko: " );
								outKolor( 12 , "  |" );
								cout<<endl; 
								outKolor( 12 , " +----------------------+");
								
								cout<<endl<<" |" ;
								outKolor( 14 , " 0. Powrot do menu  " );
								outKolor( 12 , "  |" );
								cout<<endl; 
								outKolor( 12 , " +----------------------+");
								
								cout<<endl;
								
								kolor(12); kreska(ileZnakowMAX);
								cout<<endl<<" | "; kolor(14); cout<<"ID:       "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(wybor) , ileZnakowMAX ) ); kolor(12); cout<<" |";
								cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
								cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
								kolor(12); kreska(ileZnakowMAX);
								
								cout<<endl<<" Wybor: ";
								kolor(14); cin>>menuEdytuj;
														
								if( menuEdytuj != 0 or menuEdytuj != 1 or menuEdytuj != 2 )
								{
									if( menuEdytuj != 0 )
									{
										if( menuEdytuj == 1 )
										{
											system("cls");
											
											outKolor( 12 , " +----------------------+");
											cout<<endl<<" |   " ;
											outKolor( 14 , "Edytuj Klienta" );
											outKolor( 12 , "     |" );
											cout<<endl; 
											outKolor( 12 , " +----------------------+");
							
											cout<<endl<<" |" ;
											outKolor( 14 , "   Zmien imie:  " );
											outKolor( 12 , "      |" );
											cout<<endl; 
											outKolor( 12 , " +----------------------+");
											
											cout<<endl;
											
											kolor(12); kreska(ileZnakowMAX);
											cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
											cout<<endl; kolor(12); kreska(ileZnakowMAX);
											
											cout<<endl<<" Nowe imie: "; 
											kolor(14); cin>>tempEdytuj; 
											
											tabKlient[wybor-1].setImie(tempEdytuj);
											
											if( tempEdytuj.size() > ileZnakowMAX )
												ileZnakowMAX = tempEdytuj.size();
											
											outKolor( 10 , " !!!---Zmieniono imie Klienta---!!!");
											
										}
										
										if( menuEdytuj == 2 )
										{
											system("cls");
											
											outKolor( 12 , " +----------------------+");
											cout<<endl<<" |   " ;
											outKolor( 14 , "Edytuj Klienta" );
											outKolor( 12 , "     |" );
											cout<<endl; 
											outKolor( 12 , " +----------------------+");
							
											cout<<endl<<" |   " ;
											outKolor( 14 , "Zmien nazwisko:" );
											outKolor( 12 , "    |" );
											cout<<endl; 
											outKolor( 12 , " +----------------------+");
											
											cout<<endl;
											
											kolor(12); kreska(ileZnakowMAX);
											cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |";
											cout<<endl;kolor(12); kreska(ileZnakowMAX);
											
											cout<<endl<<" Nowe Nazwisko: "; 
											kolor(14); cin>>tempEdytuj; 
											
											tabKlient[wybor-1].setNazwisko(tempEdytuj);
											
											if( tempEdytuj.size() > ileZnakowMAX )
												ileZnakowMAX = tempEdytuj.size();
											
											outKolor( 10 , " !!!---Zmieniono nazwisko Klienta---!!!");
											
										}
										
										kolor(12); kreska(ileZnakowMAX);
										cout<<endl<<" | "; kolor(14); cout<<"ID:       "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( string2Int(wybor) , ileZnakowMAX ) ); kolor(12); cout<<" |";
										cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
										cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[wybor-1].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
										kolor(12); kreska(ileZnakowMAX);
										
									}else
										{
											outKolor( 13 , " !!!---Przerwano operacje---!!!");
											break;
										}
								}else
									{
										outKolor( 13 , " !!!---Zla wartosc---!!!");	
									}
							}		
						}else
							outKolor( 13 , " !!!---Przerwano operacje---!!!");
						
						kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
						pause();
					}
					
					break;
				}
				
			case 4:
				{
					 ( 27, 44 );
					system("cls");
					
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |   " ;
						outKolor( 14 , "Wyswietl Klientow" );
							outKolor( 12 , "  |" );cout<<endl; 
					outKolor( 12 , " +----------------------+");
					
					if( tabKlient.size() > 0 )
					{
						cout<<endl;
						for( int f = 0; f < tabKlient.size(); f++ )
						{
							kreska(ileZnakowMAX);
							cout<<endl<<" | "; kolor(14); cout<<"Imie:     "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getImie() , ileZnakowMAX ) ); kolor(12); cout<<" |";
							cout<<endl<<" | "; kolor(14); cout<<"Nazwisko: "; kolor(12); cout<<"| "; outKolor( 14 , wyrownaj( tabKlient[f].getNazwisko() , ileZnakowMAX ) ); kolor(12); cout<<" |"<<endl;
						}
						kreska(ileZnakowMAX);
					}else
						{
							outKolor( 5 , " +-----------------------------------+" );
								cout<<endl<<" | "; outKolor( 13 , "!!!---Brak Klientow w Bazie---!!! "); kolor(5); cout<< "|"<<endl
								<<" +-----------------------------------+"<<endl;
						}
					
					kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
					pause();
					break;
				}//case 3 lista klientow
				
		}//switch klient
		
	}//while program
	
	return 0;
}
