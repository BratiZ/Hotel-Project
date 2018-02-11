#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <sstream>
#include <conio.h>
#include <limits>
#include <stdexcept>

using namespace std;
//Klient
//Pobyt
//Pokoj
//Uslugi

// ------------------- UZYTKOWE FUNKCJE ---------------------

void pause()
{
	system("PAUSE>thrash/NULL.txt");
}

void kolor(int kolor)
{
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut , kolor );
}

void outKolor( int x, string str)
{
	kolor(x);
	cout<<str;
}

string string2Int( int x )
{
	ostringstream ss;
	ss << x;
	string str = ss.str(); 
	
	return str;
	
}// zamiana int na string :)

struct console
  { /*
  console( unsigned width, unsigned height )
    {
    	
    SMALL_RECT r;
    COORD c;
    
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left = r.Top = 0;
    r.Right = width -1;
    r.Bottom = height -1;
    
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;*/
  };

//-------------- POKOJE FUNKCJE POCZATEK -------------------------------------

class Pokoj
{
	protected:
		class data
		{
			public:
				int dzien;
				int miesiac;	
				int rok;
		};
		
	public:
		int ID;
		float cena;
		char stan;
		data zajetyOd;
		data zajetyDo;
		int IDKlient;
		
		Pokoj()
		{
			ID = 0;
			cena = 0;
			stan = '0';
			zajetyOd.dzien = 0;
			zajetyOd.miesiac = 0;
			zajetyOd.rok = 0;
			zajetyDo.dzien = 0;
			zajetyDo.miesiac = 0;
			zajetyDo.rok = 0;
			IDKlient = 0;		
		}
		
	virtual bool getStan() = 0;
};

class Pokoj1OS : public Pokoj
{
	int ileOsob;
	
	public:
		
		Pokoj1OS( int xID , float xCena , char xStan , int xD1 , int xM1 , int xR1 , int xD2 , int xM2 , int xR2 , int xIDKlient ) 
		{
		
			ID = xID;
			cena = xCena;
			ileOsob = 1;
			stan = xStan;
			zajetyOd.dzien = xD1;
			zajetyOd.miesiac = xM1;
			zajetyOd.rok = xR1;
			zajetyDo.dzien = xD2;
			zajetyDo.miesiac = xM2;
			zajetyDo.rok = xR2;	
			IDKlient = xIDKlient;
		}
		
		bool getStan()
		{
			if( stan == '0' )
				return true;
			
			return false;
		}
		
		~Pokoj1OS()
		{
			//cout<<"DI{AD";
		}
};

void PrintPokojeWolne( vector < Pokoj1OS > a , vector < Pokoj1OS > b , vector < Pokoj1OS > c )
{
	char znaka[a.size()], 
		 znakb[b.size()],
		 znakc[c.size()]; 
	
	for( int f = 0; f < a.size(); f++ )
	{
		if( a[f].getStan() )
			{
				znaka[f] = 'W';	
			}
				else 
					{
						znaka[f] = 'Z';	
					}			
	}
	
	for( int f = 0; f < b.size(); f++ )
	{
		if( b[f].getStan() )
			{
				znakb[f] = 'W';	
			}
				else 
					{
						znakb[f] = 'Z';	
					}
	}
	
	for( int f = 0; f < c.size(); f++ )
	{
		if( c[f].getStan() )
			{
				znakc[f] = 'W';	
			}
				else 
					{
						znakc[f] = 'Z';	
					}
	}
	
	kolor(3); cout<<" +--------+-----------------------------------------------------------+"<<endl;
	cout<<" | "; kolor(11); cout<<"Pietra"; kolor(3); 
		cout<<" |                      ";  kolor(11); cout<<"Wolne Pokoje"; kolor(3); cout<<"                         |"<<endl;
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11); cout<<"1 "; kolor(3); cout<<"   | "; 
			if( znaka[0] == 'W' ) { kolor(11); cout<<"101"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[1] == 'W' ) { kolor(11); cout<<"102"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[2] == 'W' ) { kolor(11); cout<<"103"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[3] == 'W' ) { kolor(11); cout<<"104"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[4] == 'W' ) { kolor(11); cout<<"105"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[5] == 'W' ) { kolor(11); cout<<"106"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[6] == 'W' ) { kolor(11); cout<<"107"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znaka[7] == 'W' ) { kolor(11); cout<<"108"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; } 
			if( znaka[8] == 'W' ) { kolor(11); cout<<"109"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; } 
			if( znaka[9] == 'W' ) { kolor(11); cout<<"110"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
				kolor(12); cout<<endl; 
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11); cout<<"2 "; kolor(3); cout<<"   | "; 
			if( znakb[0] == 'W' ) { kolor(11); cout<<"201"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[1] == 'W' ) { kolor(11); cout<<"202"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[2] == 'W' ) { kolor(11); cout<<"203"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[3] == 'W' ) { kolor(11); cout<<"204"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[4] == 'W' ) { kolor(11); cout<<"205"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[5] == 'W' ) { kolor(11); cout<<"206"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[6] == 'W' ) { kolor(11); cout<<"207"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[7] == 'W' ) { kolor(11); cout<<"208"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[8] == 'W' ) { kolor(11); cout<<"209"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[9] == 'W' ) { kolor(11); cout<<"210"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
				kolor(12); cout<<endl;
				   			
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11); cout<<"3 "; kolor(3); cout<<"   | "; 
			if( znakb[10] == 'W' ) { kolor(11); cout<<"301"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[11] == 'W' ) { kolor(11); cout<<"302"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[12] == 'W' ) { kolor(11); cout<<"303"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[13] == 'W' ) { kolor(11); cout<<"304"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[14] == 'W' ) { kolor(11); cout<<"305"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[15] == 'W' ) { kolor(11); cout<<"306"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[16] == 'W' ) { kolor(11); cout<<"307"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[17] == 'W' ) { kolor(11); cout<<"308"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[18] == 'W' ) { kolor(11); cout<<"309"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakb[19] == 'W' ) { kolor(11); cout<<"310"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
				kolor(12); cout<<endl;
				   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11); cout<<"4 "; kolor(3); cout<<"   | "; 
			if( znakc[0] == 'W' ) { kolor(11); cout<<"401"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[1] == 'W' ) { kolor(11); cout<<"402"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[2] == 'W' ) { kolor(11); cout<<"403"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[3] == 'W' ) { kolor(11); cout<<"404"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[4] == 'W' ) { kolor(11); cout<<"405"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[5] == 'W' ) { kolor(11); cout<<"406"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[6] == 'W' ) { kolor(11); cout<<"407"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
			if( znakc[7] == 'W' ) { kolor(11); cout<<"408"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; } 
			if( znakc[8] == 'W' ) { kolor(11); cout<<"409"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; } 
			if( znakc[9] == 'W' ) { kolor(11); cout<<"410"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   "; kolor(3); cout<<" | "; }
				kolor(12); cout<<endl;
				   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11); cout<<"5 "; kolor(3); cout<<"   | "; 
			if( znakc[10] == 'W' ) { kolor(11); cout<<"501"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[11] == 'W' ) { kolor(11); cout<<"502"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[12] == 'W' ) { kolor(11); cout<<"503"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[13] == 'W' ) { kolor(11); cout<<"504"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[14] == 'W' ) { kolor(11); cout<<"505"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[15] == 'W' ) { kolor(11); cout<<"506"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[16] == 'W' ) { kolor(11); cout<<"507"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
			if( znakc[17] == 'W' ) { kolor(11); cout<<"508"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; } 
			if( znakc[18] == 'W' ) { kolor(11); cout<<"509"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; } 
			if( znakc[19] == 'W' ) { kolor(11); cout<<"510"; kolor(3); cout<<" | "; } else { kolor(11); cout<<"   ";kolor(3); cout<<" | "; }
				kolor(12); cout<<endl;
						
		kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;

}

void PrintPokoje( vector < Pokoj1OS > a , vector < Pokoj1OS > b , vector < Pokoj1OS > c )
{
	char znaka[a.size()], //10
		 znakb[b.size()], //20
		 znakc[c.size()]; //20
		 
	int index = 0;
	
	for( int f = 0; f < a.size(); f++ )
	{
		if( a[f].getStan() )
			{
				znaka[f] = 'W';	
			}
				else 
					{
						znaka[f] = 'Z';	
					}			
	}
	
	for( int f = 0; f < b.size(); f++ )
	{
		if( b[f].getStan() )
			{
				znakb[f] = 'W';	
			}
				else 
					{
						znakb[f] = 'Z';	
					}
	}
	
	for( int f = 0; f < c.size(); f++ )
	{
		if( c[f].getStan() )
			{
				znakc[f] = 'W';	
			}
				else 
					{
						znakc[f] = 'Z';	
					}
	}
	
	
	kolor(3); cout<<" +--------+-----------------------------------------------------------+"<<endl<<" | ";
		kolor(11);cout<<"Pietra";kolor(3); cout<<" |                       "; 
		kolor(11); cout<<"Pokoje";kolor(3); cout<<"                              |"<<endl;
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11);cout<<"1 ";kolor(3); cout<<"   | "; 
				   kolor(11);cout<<"101";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"102";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"103";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"104";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"105";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"106";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"107";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"108";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"109";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"110";kolor(3); cout<<" | ";	
				   		kolor(12);cout<<"<- pokoje jednoosobowe"<<endl;
				   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |  "; 
	kolor(11); cout<<"Stan";kolor(3);cout<<"  |";
		for( index = 0; index < 10; index++ ) 
		{
			if( znaka[index] == 'W' ) 
				{
					kolor(10);
					cout<<"  "<<znaka[index]; 
					kolor(3); cout<<"  |"; 	
				}else
					{
						kolor(12);
						cout<<"  "<<znaka[index];
						kolor(3); cout<<"  |";
					}
		}
		cout<<endl;
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		 kolor(11);cout<<"2 ";kolor(3); cout<<"   | "; 
				   kolor(11);cout<<"201";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"202";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"203";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"204";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"205";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"206";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"207";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"208";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"209";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"210";kolor(3); cout<<" | ";	
				   		kolor(12);cout<<"<- pokoje dwupokojowe"<<endl;
				   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |  "; 
	kolor(11); cout<<"Stan";kolor(3);cout<<"  |";
		for( index = 0; index < 10; index++ ) 
		{
			if( znakb[index] == 'W' ) 
				{
					kolor(10);
					cout<<"  "<<znakb[index]; 
					kolor(3); cout<<"  |"; 	
				}else
					{
						kolor(12);
						cout<<"  "<<znakb[index];
						kolor(3); cout<<"  |";
					}
		}
		cout<<endl;	
						   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		kolor(11);cout<<"3 ";kolor(3); cout<<"   | "; 
				   kolor(11);cout<<"301";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"302";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"303";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"304";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"305";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"306";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"307";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"308";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"309";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"310";kolor(3); cout<<" | ";	
				   		
	kolor(3); cout<<endl<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |  "; 
	kolor(11); cout<<"Stan";kolor(3);cout<<"  |";
		for( index; index < 20; index++ ) 
		{
			if( znakb[index] == 'W' ) 
				{
					kolor(10);
					cout<<"  "<<znakb[index]; 
					kolor(3); cout<<"  |"; 	
				}else
					{
						kolor(12);
						cout<<"  "<<znakb[index];
						kolor(3); cout<<"  |";
					}
		}
		cout<<endl;
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		kolor(11);cout<<"4 ";kolor(3); cout<<"   | "; 
				   kolor(11);cout<<"401";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"402";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"403";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"404";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"405";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"406";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"407";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"408";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"409";kolor(3); cout<<" | ";	
				   kolor(11);cout<<"409";kolor(3); cout<<" | "; 
				   		kolor(12);cout<<"<- pokoje trzyosobowe"<<endl;
				   		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |  "; 
	kolor(11); cout<<"Stan";kolor(3);cout<<"  |";
		for( index = 0; index < 10; index++ ) 
		{
			if( znakc[index] == 'W' ) 
				{
					kolor(10);
					cout<<"  "<<znakc[index]; 
					kolor(3); cout<<"  |"; 	
				}else
					{
						kolor(12);
						cout<<"  "<<znakc[index];
						kolor(3); cout<<"  |";
					}
		}
		cout<<endl;
		
	kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl
				  <<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |   ";
		kolor(11);cout<<"5 ";kolor(3); cout<<"   | "; 
				   kolor(11);cout<<"501";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"502";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"503";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"504";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"505";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"506";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"507";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"508";kolor(3); cout<<" | "; 
				   kolor(11);cout<<"509";kolor(3); cout<<" | ";	
				   kolor(11);cout<<"510";kolor(3); cout<<" | "; 
				   		
	kolor(3); cout<<endl<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl<<" |  "; 
	kolor(11); cout<<"Stan";kolor(3);cout<<"  |";
		for( index; index < 20; index++ ) 
		{
			if( znakc[index] == 'W' ) 
				{
					kolor(10);
					cout<<"  "<<znakc[index]; 
					kolor(3); cout<<"  |"; 	
				}else
					{
						kolor(12);
						cout<<"  "<<znakc[index];
						kolor(3); cout<<"  |";
					}
		}
		cout<<endl;				   		
		
		kolor(3); cout<<" +--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;

}

void printSzczegolyPokoj( vector < Pokoj1OS > a , int b )
{	
		if( a[b-1].getStan() )
			{
				kolor(12); cout << " +---------------+ " << endl;
				kolor(12); cout << " | "; kolor(14); cout << "ID:           "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].ID << endl;
				kolor(12); cout << " +---------------+ " << endl;
				kolor(12); cout << " | "; kolor(14); cout << "Numer Pokoju: "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].ID << endl;
				kolor(12); cout << " +---------------+ " << endl;						
				kolor(12); cout << " | "; kolor(14); cout << "Cena:         "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].cena << endl;
				kolor(12); cout << " +---------------+ " << endl;				
				kolor(12); cout << " | "; kolor(14); cout << "Stan:         "; kolor(12); cout <<"| "; kolor(14); cout << "Wolny" << endl;
				kolor(12); cout << " +---------------+ " << endl;
			}else 
				{
					kolor(12); cout << " +---------------+ " << endl;
					kolor(12); cout << " | "; kolor(14); cout << "ID:           "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].ID << endl;
					kolor(12); cout << " +---------------+ " << endl;
					kolor(12); cout << " | "; kolor(14); cout << "Numer Pokoju: "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].ID << endl;
					kolor(12); cout << " +---------------+ " << endl;						
					kolor(12); cout << " | "; kolor(14); cout << "Cena:         "; kolor(12); cout <<"| "; kolor(14); cout << a[b-1].cena << endl;
					kolor(12); cout << " +---------------+ " << endl;				
					kolor(12); cout << " | "; kolor(14); cout << "Stan:         "; kolor(12); cout <<"| "; kolor(14); cout << "Zajety" << endl;
					kolor(12); cout << " +---------------+ " << endl;
					kolor(12); cout << " | "; kolor(14); cout << "Zajety od:    "; kolor(12); cout <<"| "; kolor(14);
						cout << a[ b-1 ].zajetyOd.dzien << "-" 
					         << a[ b-1 ].zajetyOd.miesiac << "-" 
						     << a[ b-1 ].zajetyOd.rok <<endl;		
					kolor(12); cout << " +---------------+ " << endl;
					kolor(12); cout << " | "; kolor(14); cout << "Zajety do:    "; kolor(12); cout <<"| "; kolor(14);
						cout << a[ b-1 ].zajetyDo.dzien << "-" 
					         << a[ b-1 ].zajetyDo.miesiac << "-" 
						     << a[ b-1 ].zajetyDo.rok <<endl;		
					kolor(12); cout << " +---------------+ " << endl;
				}
	
}

//-------------- KLIENT FUNKCJE POCZATEK --------------------------------------


void printElementMenu( int x, int y, string str )
{
	int longstr = str.size() + 1 ;
	
	string ileSpacji,
		   minusy;
		   
	minusy = "----------------------"; //szerokosc menu :) 
	
	for( int f = 0; f < minusy.size() - longstr; f++ )
		ileSpacji += " ";
	
	kolor(x); cout<<" +"<<minusy<<"+"<<endl;
	kolor(x); cout<<" | ";
	kolor(y); cout<<str;
	kolor(x); cout<<ileSpacji<<"|"<<endl;
}


void printMenu( int x, int y )
{
	
		printElementMenu(x,y,"      Klienci");
			printElementMenu(x,y,"1. Dodaj Klienta");
			printElementMenu(x,y,"2. Usun Klienta");
			printElementMenu(x,y,"3. Edytuj Klienta");
			printElementMenu(x,y,"4. Wyswietl Klientow");
			printElementMenu(x,y,"0. Zapisz i wyjdz");
				
		kolor(x);cout<<" +----------------------+"<<endl;	//kek
			kolor(y);cout<<"   Wybor: "; 
}

class Klient
{
	private:
		int ID;
		string imie,
			   nazwisko;
		char meldunek;
		
			
	public:
		void setID( int xID ) { ID = xID; }
		void setNazwisko( string str ) { nazwisko = str; }
		void setImie( string str ) { imie = str; }
		void setMeldunek( char ch ) { meldunek = ch; }
		
		int getID(){ return ID; }
		string getImie(){ return imie; }
		string getNazwisko(){ return nazwisko; }
		char getMeldunek(){ return meldunek; }
		
		Klient( int xID, string strI, string strN , char charM )
		{
			ID = xID;
			imie = strI;
			nazwisko = strN;
			meldunek = charM;
		}
		
		Klient()
		{
			ID = 1020;
			imie = "1020";
			nazwisko = "1020";
			meldunek = '0';
		}
		
		~Klient()
		{
			ID = 0;
		}
		
		void Print()
		{
			kolor(12);cout<<" +-----------+----------------"<<endl;
			kolor(12); cout<<" |     "; 
				kolor(14); cout<<"Imie: ";
			kolor(12); cout<<"| ";
				kolor(14); cout<<imie<<endl;
				
			kolor(12); cout<<" | ";
				kolor(14); cout<<"Nazwisko: ";
			kolor(12); cout<<"| ";
				kolor(14); cout<<nazwisko<<endl;				
		}
};

string wyrownaj( string str , int ileZnakowMAX )
{
	int wielkoscSTR = str.size();
	
	for( int f = 0; f < ileZnakowMAX - wielkoscSTR;  f++ )
	{
		str += " ";
	}	
	return str;
}

void kreska( int ileZnakowMAX )
{
	string str = " +-----------+--";
	
	for( int f = 0; f < ileZnakowMAX;  f++ )
	{
		str += "-";
	}
	
	str += "+";	
	cout<<str;
}

void kreska2( int ileZnakowMAX , int ileMenu , int ileCena )
{
	string str = " +-";
	
	for( int f = 0; f < ileMenu;  f++ )
		str += "-";
	
	str += "-+";
	
	for( int f = 0; f < ileZnakowMAX;  f++ )
		str += "-";
	
	str += "--+";
	
	for( int f = 0; f < ileCena;  f++ )
		str += "-";
		
	str += "--+";
	
	cout<<str;
}


//---------------------- FUNKCJE USLUGI POCZATEK ------------------------------


class Uslugi
{
	private:
		int ID;
		string nazwa,
		 	   cena;
		
	public:
		void setID( int xID ) 		{ ID = xID; }
		void setNazwa( string xNazwa ) 	{ nazwa = xNazwa; }
		void setCena( string xCena ) 	{ cena = xCena; }
		
		int getID() 		{ return ID; }
		string getNazwa()	{ return nazwa; }
		string getCena()	{ return cena; }
	
		Uslugi( int xID , string xNazwa , string xCena )
		{
			ID = xID;
			nazwa = xNazwa;
			cena = xCena;
		}
		
		void print()
		{
			cout<<"ID: " << ID <<endl
				<<"Nz: " << nazwa <<endl
				<<"Cn: " << cena <<endl;
		}
		
};

void printUslugaID( Uslugi a , int max , int xID )
{
	string k1 = "",
		   nazwa = a.getNazwa(),
		   cena  = a.getCena(),
		   ID = string2Int( xID );
		   
	for( int f = 0; f < max - 1; f++ )
		k1 += "-";
	k1 += "--+";
	
	int m1 = max - nazwa.size();
	
	for( int f = 0; f < m1; f++ )
		nazwa += " ";
	
	int m2 = max - cena.size();
	
	for( int f = 0; f < m2; f++ )
		cena += " ";
	
	int m3 = max - ID.size();
	
	for( int f = 0; f < m3; f++ )
		ID += " ";
	
	kolor(12); cout << " +--------+-" << k1 	<< endl;
	kolor(12); cout << " | "; kolor(14); cout   << "   ID:"; kolor(12); cout << " | ";  kolor(14); cout << ID;  kolor(12); cout << " |" << endl;
	kolor(12); cout << " +--------+-" << k1 	<< endl;
	kolor(12); cout << " | "; kolor(14); cout   << "Nazwa:"; kolor(12); cout << " | ";     kolor(14); cout << nazwa;  kolor(12); cout << " |" << endl;
	kolor(12); cout << " | "; kolor(14); cout   << "Cena:";  kolor(12); cout << "  | ";    kolor(14); cout << cena;   kolor(12); cout << " |" << endl;
	kolor(12); cout << " +--------+-" << k1 	<< endl;
}

void printUsluga( Uslugi a , int max )
{
	string k1 = "",
		   nazwa = a.getNazwa(),
		   cena  = a.getCena();
		   
	for( int f = 0; f < max - 1; f++ )
		k1 += "-";
	k1 += "--+";
	
	int m1 = max - nazwa.size();
	
	for( int f = 0; f < m1; f++ )
		nazwa += " ";
	
	int m2 = max - cena.size();
	
	for( int f = 0; f < m2; f++ )
		cena += " ";
	
	kolor(12); cout << " +--------+-" << k1 	<< endl;
	kolor(12); cout << " | "; kolor(14); cout << "Nazwa:"; kolor(12); cout << " | ";  kolor(14); cout << nazwa;  kolor(12); cout << " |" << endl;
	kolor(12); cout << " | "; kolor(14); cout << "Cena:";  kolor(12); cout << "  | "; kolor(14); cout << cena;   kolor(12); cout << " |" << endl;
	kolor(12); cout << " +--------+-" << k1 	<< endl;
}

void printMenuAdm( int x, int y )
{
	
		printElementMenu(x,y,"       Menu");
			printElementMenu(x,y,"1. Klienci");
			printElementMenu(x,y,"2. Pokoje");
			printElementMenu(x,y,"3. Uslugi");
			printElementMenu(x,y,"4. Pobyt");
			printElementMenu(x,y,"0. wyjdz");
				
		kolor(x);cout<<" +----------------------+"<<endl;	//kek
			kolor(y);cout<<"   Wybor: "; 
}

//----------------------------------------- uslugi funkcje ----------------------------------
class Pobyt
{
	private:
		int IDKlient;
		int IDPokoj;
				
	public:
		void setIDKlient( int xID ) { IDKlient = xID; }
		void setIDPokoj	( int xID ) { IDPokoj = xID; }
		
		int getIDKlient() 	{ return IDKlient; }
		int getIDPokoj() 	{ return IDPokoj; }
		
		Pobyt()
		{
			IDKlient	= 0;
			IDPokoj 	= 0;
		}
		
		Pobyt( int xIDKlient , int xIDPokoj)
		{
			IDKlient	= xIDKlient;
			IDPokoj 	= xIDPokoj;
		}
};

class BazaUslug
{
	private:
		int	IDPobyt,
			IDUsluga,
			ilosc;
			
	public:
		int getIDPobyt() 	{ return IDPobyt;  }
		int getIDUsluga() 	{ return IDUsluga; }
		int getIlosc() 		{ return ilosc; }
		
		void setIDPobyt ( int xIDPobyt  ) { IDPobyt  = xIDPobyt;  }
		void setIDUlsuga( int xIDUsluga ) { IDUsluga = xIDUsluga; }
		void setIlosc( int xIlosc ) 	  { ilosc = xIlosc; }
		
		BazaUslug()
		{
			IDPobyt = 0;
			IDUsluga = 0;
			ilosc = 0;
		}
		
		BazaUslug( int xIDPobyt , int xIDUsluga , int xIlosc )
		{
			IDPobyt = xIDPobyt;
			IDUsluga = xIDUsluga;
			ilosc = xIlosc;
		}
};


