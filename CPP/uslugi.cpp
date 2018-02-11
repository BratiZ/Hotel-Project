#include "funkcje.hpp"

int main(int argc, char** argv) {
	
	fstream pUslugi;
	
	vector< Uslugi > usl;
	
	string nazwaZBazy,
		   cenaZBazy,
		   tempEdytuj;
	
	int IDZBazy,
		IDsprawdzID = 0,
		wyborMenu,
		MAXCena = 0,
		MAXNazwa = 0,
		wybor,
		menuEdytuj,
		ileZnakowMAX = 0;
	
	char sprawdzWybor;
	
	bool program = true,
		 menu1 = true;
		 
	
	pUslugi.open( "BASE/UslugiBaza.txt" , ios::in | ios::app );
	
	if( !pUslugi.is_open() )
	{
		cout<<"Nie mozna otworzyc pliku!"<<endl
			<<"Wychodzenie z programu"; //sprawdz czy otwarty
		pause();
		return 0;
	}
	
	if( ifstream("BASE/UslugiBaza.txt", ios::ate).tellg() )
	{
		while( pUslugi >> IDZBazy >> nazwaZBazy >> cenaZBazy )
		{			
			for( int f2 = 0; f2 < nazwaZBazy.size(); f2++ )
			{
				if( nazwaZBazy[f2] == '_' )
				{
					nazwaZBazy[f2] = ' ';
				}
			}

			usl.push_back( Uslugi( IDZBazy  , nazwaZBazy , cenaZBazy ) );
			
			if( IDZBazy > IDsprawdzID )
				IDsprawdzID = IDZBazy;
			
			if( cenaZBazy.size() > MAXCena )
				MAXCena = cenaZBazy.size();
				
			if( nazwaZBazy.size() > MAXNazwa )
				MAXNazwa = nazwaZBazy.size();
				
			if( ileZnakowMAX < MAXNazwa )
				ileZnakowMAX = MAXNazwa;
				
			if( ileZnakowMAX < MAXCena )
				ileZnakowMAX = MAXCena; 	
		}
	
	}
	
	pUslugi.close();
	
	while( program )
	{
		menu1 = true;
		while( menu1 )
		{
			system("cls");
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"    Menu Uslugi    ";
				kolor(12); cout<<" |"<<endl; 
		
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"1. Wszystkie Uslugi";
				kolor(12); cout<<" |"<<endl; 
		
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"2. Dodaj Usluge    ";
				kolor(12); cout<<" |"<<endl; 
				
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"3. Usun Usluge     ";
				kolor(12); cout<<" |"<<endl; 
			
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"4. Edytuj Usluge   ";
				kolor(12); cout<<" |"<<endl; 
				
				kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"0. wyjdz           ";
				kolor(12); cout<<" |"<<endl; 
				
			kolor(12); cout<<" +---------------------+"<<endl;
			
			kolor(12); cout<<" Wybor: "; kolor(14);
			cin>>wyborMenu;	
			
			if( !cin )
			{
				cin.clear();
				cin.sync();
				
				kolor(13);cout<<" !!!---Zly znak---!!!"<<endl;
				pause();
			}else
				{
					if( wyborMenu == 0 or wyborMenu == 1 or wyborMenu == 2 or wyborMenu == 3 or wyborMenu == 4 )
					{
						menu1 = false;
					}else
						{
							kolor(13);cout<<" !!!---Zly wybor---!!!"<<endl;
							pause();
						}
				}	
		}//while menu1
		
		switch( wyborMenu )
		{
			case 0:
				{
					for( int f = 0; f < usl.size(); f++ )
					{
						string temp = usl[f].getNazwa();
						
						for( int f2 = 0; f2 < temp.size(); f2++ )
						{
							if( temp[f2] == ' ' )
							{
								temp[f2] = '_';
							}
						}
						
						usl[f].setNazwa( temp );
					}
					
					remove("BASE/UslugiBaza.txt");
					fstream ZapiszBaze;
					ZapiszBaze.open( "BASE/UslugiBaza.txt", ios::app );
					
					for( int f = 0; f < usl.size(); f++ )
						ZapiszBaze << usl[f].getID() << " " 
								   << usl[f].getNazwa() << " " 
								   << usl[f].getCena() << "\n";
					
					ZapiszBaze.close();
					
					system("administracja.exe");
					
					return 0;
					break;
				}
				
			case 1:
				{
					system("cls");
					
					if( usl.size() != 0 )
						for( int f = 0; f < usl.size(); f++ )
						{
							printUsluga( usl[f] , ileZnakowMAX );
						}
					else
						{
							kolor(13); cout<<"!!!---Nie ma zadnej uslugi---!!!"<<endl;
						}
				pause();
				break;
				}
			
			case 2:
				{
					wybor = 2;
					while( wybor < 0 or wybor > 1 )
					{
						system("cls");
					
						outKolor( 12 , " +----------------------+" ); cout<<endl;
						cout<<" |"; outKolor( 14 , "    Dodaj usluge      "); outKolor( 12 , "|" ); 
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
							
							kolor(13);cout<<" !!!---Zly znak---!!!"<<endl;
							pause();
						}else
							{
								if( wybor != 1 and wybor != 0 )
									{
										outKolor( 13 , " !!!---Zla wartosc---!!!");
										pause();
									}
							}
					}
					
					if( wybor != 0 )
					{
						
						outKolor( 12 , " Podaj nazwe: " );
						
						kolor(14);
						
						cin.clear();
						cin.sync();
						getline( cin ,  nazwaZBazy );
						
						outKolor( 12 , " Podaj cene: " ); 
						
						kolor(14);
						cin>>cenaZBazy;
				
						usl.push_back( Uslugi( ++IDsprawdzID , nazwaZBazy , cenaZBazy  ) );
						outKolor( 10 , " !!!---Dodano usluge---!!!");
						
						if( cenaZBazy.size() > ileZnakowMAX )
							ileZnakowMAX = cenaZBazy.size();
							
						if( nazwaZBazy.size() > ileZnakowMAX )
							ileZnakowMAX = nazwaZBazy.size();
							
					}else
						outKolor( 13 , " !!!---Przerwano operacje---!!!");	
					
					pause();	
					
					break;	
				}//case 2
				
			case 3:
				{
					system("CLS");
					
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |    " ;
						outKolor( 14 , "Usun Usluge" );
							outKolor( 12 , "       |" );
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
					
					if( usl.size() > 0 )	
					{	while( true )
						{							
							for( int f = 0; f < usl.size(); f++ )
								printUslugaID( usl[ f ] , ileZnakowMAX , f+1 );	
												
							cout<<endl<<" Wybor: ";
							
							kolor(14);
							cin>>wybor;
						
							if( !cin )
							{
								cin.clear();
								cin.sync();
								
								kolor(13);cout<<" !!!---Zly znak---!!!"<<endl;
								pause();
							}else
								if( wybor >= usl.size() or wybor <= usl.size() )
									break;
								else
									kolor(13);cout<<" !!!---Zla wartosc---!!!"<<endl;
						}
						
							
						if ( wybor != 0 )
						{
							outKolor( 13 , " Czy napewno chcesz usunac usluge?(Y/N): ");
							cin>>sprawdzWybor;
						
							if( sprawdzWybor == 'Y' or sprawdzWybor == '1' or sprawdzWybor == 'y' )
							{
								usl.erase( usl.begin() + wybor - 1 );
								kolor(10); cout<<" !!!---Usunieto usluge---!!!";
							}else
								kolor(13); cout<<" !!!---Przerwano operacje---!!!";		
						}
					}else
						{		
							outKolor( 5 , " +-----------------------------------+" );
								cout<<endl<<" | "; kolor(13); cout<<"!!!---Brak uslug w bazie---!!! "; kolor(5); cout<< "|"<<endl
								<<" +-----------------------------------+"<<endl;
						}
					break;
				}//case 3
			
			case 4:
				{
					//console con( 27, 22 );
					system("CLS");
					
					outKolor( 12 , " +----------------------+");
					cout<<endl<<" |    " ;
						outKolor( 14 , "Edytuj Uslugi" );
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
							outKolor( 12 , "   |" ); cout<<endl;
							
					outKolor( 12 , " +----------------------+" );
					cout << endl;
					
					if( usl.size() > 0 )	
					{	
						cout<<endl;
						
						for( int f = 0; f < usl.size(); f++ )
							printUslugaID( usl[ f ] , ileZnakowMAX , f+1 );
						
						cout << endl << " ID: ";
						kolor(14);
						cin >> wybor;
						
						if( wybor != 0 )
						{
							while( true )
							{
								system("cls");
							
								outKolor( 12 , " +----------------------+");
								cout << endl << " |    " ;
								outKolor( 14 , "Edytuj usluge" );
								outKolor( 12 , "     |" );
								cout << endl; 
								outKolor( 12 , " +----------------------+");
							
								cout << endl << " | " ;
								outKolor( 14 , " 1. Zmien nazwe: " );
								outKolor( 12 , "    |" );
								cout << endl; 
								outKolor( 12 , " +----------------------+");
								
								cout << endl << " | " ;
								outKolor( 14 , " 2. Zmien cene: " );
								outKolor( 12 , "     |" );
								cout << endl; 
								outKolor( 12 , " +----------------------+");
								
								cout << endl << " |" ;
								outKolor( 14 , " 0. Powrot do menu  " );
								outKolor( 12 , "  |" );
								cout << endl; 
								outKolor( 12 , " +----------------------+");
								
								cout << endl;
								
								kolor(12); kreska(ileZnakowMAX);
								cout << endl << " | "; kolor(14); cout << "ID:       "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( string2Int( wybor ) , ileZnakowMAX ) ); 		   kolor(12); cout << " |";
								cout << endl << " | "; kolor(14); cout << "Nazwa:    "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( usl[ wybor - 1 ].getNazwa() , ileZnakowMAX ) ); kolor(12); cout << " |";
								cout << endl << " | "; kolor(14); cout << "Cena:     "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( usl[ wybor - 1 ].getCena() , ileZnakowMAX ) );  kolor(12); cout << " |" << endl;
								kolor(12); kreska(ileZnakowMAX);
								
								cout << endl << " Wybor: ";
								kolor(14); cin >> menuEdytuj;
								
								if( !cin )
								{
									cin.clear();
									cin.sync();
								}else
									{
										if( menuEdytuj != 0 or menuEdytuj != 1 or menuEdytuj != 2 )
										{
											if( menuEdytuj != 0 )
											{
												if( menuEdytuj == 1 )
												{
													system("cls");
													
													outKolor( 12 , " +----------------------+");
													cout << endl << " |    " ;
													outKolor( 14 , "Edytuj usluge" );
													outKolor( 12 , "     |" );
													cout << endl; 
													outKolor( 12 , " +----------------------+");
									
													cout << endl << " |" ;
													outKolor( 14 , "   Zmien nazwe:  " );
													outKolor( 12 , "     |" );
													cout << endl; 
													outKolor( 12 , " +----------------------+");
													
													cout << endl;
													
													kolor(12); kreska(ileZnakowMAX);
													cout << endl << " | "; kolor(14); cout << "Nazwa:    "; kolor(12); cout << "| "; outKolor( 14 , wyrownaj( usl[wybor-1].getNazwa() , ileZnakowMAX ) ); kolor(12); cout << " |";
													cout << endl; kolor(12); kreska(ileZnakowMAX);
													
													cout << endl << " Nowa Nazwa: "; 
													kolor(14); 
													
													cin.clear();
													cin.sync();	
													getline( cin ,  tempEdytuj ) ; 
													
													usl[ wybor-1 ].setNazwa(tempEdytuj);
													
													if( tempEdytuj.size() > ileZnakowMAX )
														ileZnakowMAX = tempEdytuj.size();
													
													outKolor( 10 , " !!!---Zmieniono nazwe uslugi---!!!");
													
												}
												
												if( menuEdytuj == 2 )
												{
													system("cls");
													
													outKolor( 12 , " +----------------------+");
													cout << endl << " |    " ;
													outKolor( 14 , "Edytuj usluge" );
													outKolor( 12 , "     |" );
													cout << endl; 
													outKolor( 12 , " +----------------------+");
									
													cout << endl << " |    " ;
													outKolor( 14 , "Zmien Cene:" );
													outKolor( 12 , "       |" );
													cout << endl; 
													outKolor( 12 , " +----------------------+");
													
													cout << endl;
													
													kolor(12); kreska(ileZnakowMAX);
													cout << endl << " | "; kolor(14); cout<<"Cena: "; kolor(12); cout<<"    | "; outKolor( 14 , wyrownaj( usl[wybor-1].getCena() , ileZnakowMAX) ); kolor(12); cout<<" |";
													cout << endl; kolor(12); kreska(ileZnakowMAX);
													
													cout << endl << " Nowa cena: "; 
													kolor(14); cin >> tempEdytuj; 
													
													usl[wybor-1].setCena(tempEdytuj);
													
													if( tempEdytuj.size() > ileZnakowMAX )
														ileZnakowMAX = tempEdytuj.size();
													
													outKolor( 10 , " !!!---Zmieniono cene uslugi---!!!");
													
												}
												
												for( int f = 0; f < usl.size(); f++ )
													printUslugaID( usl[ f ] , ileZnakowMAX , f+1 );
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
							}//while
									
						}else
							outKolor( 13 , " !!!---Przerwano operacje---!!!");
						
						kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
						pause();
					}
					
					break;
				}
			
		}
		
	}//while program	
	
	
	
	
	return 0;
}
