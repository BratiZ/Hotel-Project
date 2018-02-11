#include "funkcje.hpp" // tu sa funkcje

int main(int argc, char** argv) {
	
	fstream plik;
	plik.open( "BASE/BazaPokoje2.txt" , ios::app | ios::in );
	
	if (  !plik.is_open() )
	{
		cout<<"Nie mozna otworzyc pliku!"<<endl
			<<"Wychodzenie z programu"; //sprawdz czy otwarty
		pause();
		return 0;
	}
	
	vector< Pokoj1OS > pokoj1;
	vector< Pokoj1OS > pokoj2;
	vector< Pokoj1OS > pokoj3;
	
	int xID, 
		xD1,
		xM1,
		xR1,
		xD2,
		xM2,
		xR2,
		xIDKlient, //do zapisu tempy takie
		w = 0,
		nrPokoju,
		pokojSwitchID = 0; 
		
	float xCena; //do zapisu tempy takie
	 
	char xStan,  //do zapisu tempy takie
		 wyborMenu,
		 wyborMenuInt;
	
	bool program = true,
		 menu1 = true,
		 szczegolyPokoj = true;
		 
	
	while( w < 50 )
	{
		
		plik >> xID >> xCena >> xStan >> xD1 >> xM1 >> xR1 >> xD2 >> xM2 >> xR2 >> xIDKlient;
		
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
	
	plik.close();	
	while( program )
	{
		menu1 = true;
		while( menu1 )	
		{
			system("cls");
			console con( 25, 20 );
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"    Menu Pokoje    ";
				kolor(12); cout<<" |"<<endl; 

			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"1. Wszystkie Pokoje";
				kolor(12); cout<<" |"<<endl; 
		
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"2. Wolne Pokoje    ";
				kolor(12); cout<<" |"<<endl; 
				
			kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"3. Szczegoly Pokoi ";
				kolor(12); cout<<" |"<<endl; 
				
				kolor(12); cout<<" +---------------------+"<<endl;
				kolor(12); cout<<" | "; 
					kolor(14); cout<<"0. wyjdz           ";
				kolor(12); cout<<" |"<<endl; 
				
			kolor(12); cout<<" +---------------------+"<<endl;
			
			kolor(12); cout<<" Wybor: "; kolor(14);
			cin>>wyborMenu;
			
			if( wyborMenu == '0' or wyborMenu == '1' or wyborMenu == '2' or wyborMenu == '3' )
			{
				wyborMenuInt = wyborMenu - 48;
				menu1 = false;
			}else
				{
					kolor(13);cout<<" !!!---Zly wybor---!!!"<<endl;
					pause();
				}
		}
		
		switch( wyborMenuInt )
		{
			case 0:
				{
					system("administracja.exe");
					return 0;
					break;
				}
			
			case 1:
				{
					system("CLS");
					console con( 95 , 30 );
					
					PrintPokoje( pokoj1 , pokoj2 , pokoj3 );
					kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
					pause();
					break;
				}
			
			case 2:
				{
					system("CLS");
					console con( 80 , 20 );
					
					PrintPokojeWolne( pokoj1 , pokoj2 , pokoj3 );
					kolor(8);cout<<endl<<" Nacisnij dowolny przycisk aby przejsc do menu..."; 
					pause();
					break;
				}
				
			case 3:
				{
					szczegolyPokoj = true;
					while( szczegolyPokoj )
					{
			
						system("CLS");
						console con( 95 , 31 );
						
						kolor(3); cout<<"          +-----------------------------------------------------------+"<<endl;
							cout<<"   "; kolor(11); cout<<"      "; kolor(3); 
							cout<<" |                  ";  kolor(11); cout<<"Szczegoly pokoi"; kolor(3); cout<<"                          |"<<endl;
							
						PrintPokoje( pokoj1 , pokoj2 , pokoj3 );
						
						kolor(12); cout<<"  Podaj nr pokoju: ";
						kolor(14);	
										
						
						cin>>nrPokoju;
						if( !cin )
						{
							cin.clear();
							cin.sync();
							
							kolor(13);cout<<" !!!---Zly znak!---!!!"<<endl;
							kolor(8); cout<<" Nacisnij dowolny przycisk..."<<endl;
							pause();
						}else if( nrPokoju > 100 and nrPokoju < 111 or nrPokoju > 200 and nrPokoju < 211 or nrPokoju > 300 and nrPokoju < 311 or nrPokoju > 400 and nrPokoju < 411 or nrPokoju > 500 and nrPokoju < 511 )
								{
									szczegolyPokoj = false;
								}else
									{
										kolor(13); cout<<" !!!---Zly numer pokoju!---!!!"<<endl;
										kolor(8); cout<<" Nacisnij dowolny przycisk..."<<endl;
										pause();
										
									}
					
					}
					
						 if( nrPokoju > 100 and nrPokoju < 111 ) pokojSwitchID = 1;
					else if( nrPokoju > 200 and nrPokoju < 211 ) pokojSwitchID = 2;
					else if( nrPokoju > 300 and nrPokoju < 311 ) pokojSwitchID = 3;
					else if( nrPokoju > 400 and nrPokoju < 411 ) pokojSwitchID = 4;
					else if( nrPokoju > 500 and nrPokoju < 511 ) pokojSwitchID = 5;
					
					int tmpNrPokoju = nrPokoju % 10;
					
					console con( 50 , 153 );
					switch( pokojSwitchID )
					{
						case 0:
							{
								break;
							}
							
						case 1:
							{
								system("cls");
								
								printSzczegolyPokoj( pokoj1 , tmpNrPokoju );
								
								break;
							}
						
						case 2:
							{
								system("cls");
								
								printSzczegolyPokoj( pokoj2 , tmpNrPokoju );
								
								break;
							}
							
						case 3:
							{
								system("cls");
								
								tmpNrPokoju = tmpNrPokoju + 10;
								
								printSzczegolyPokoj( pokoj2 , tmpNrPokoju );
								
								break;
							}
							
						case 4:
							{
								system("cls");
								
								printSzczegolyPokoj( pokoj3 , tmpNrPokoju );
								
								break;
							}
						
						case 5:
							{
								system("cls");
								
								tmpNrPokoju = tmpNrPokoju + 10;
								
								printSzczegolyPokoj( pokoj3 , tmpNrPokoju );
								
								break;
							}
													
					}//koniec switch pokojSwitchID
				
					kolor(8); cout << endl << " Nacisnij dowolny przycisk aby przejsc do menu..."; 
					pause();
					break;
				}			
		}// switch wtdf
		
	}
		
	return 0;
}

