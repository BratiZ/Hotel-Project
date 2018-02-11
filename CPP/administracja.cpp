#include "funkcje.hpp"

int main(int argc, char** argv) {
	
	int wybor,
		wyborMenu1;
	
	char TEMPwybor,
		 wyborWyjscie;
	
	bool program = true,
		 dobryWybor = false;
	
	while( program )
	{
		dobryWybor = false;
		while( !dobryWybor )
		{
			system("CLS");
			
			printMenuAdm( 12 , 14 );
			
			cin>>wybor;
		
			if( cin )
			{
				wyborMenu1 = wybor;
				dobryWybor = true;
				
			}else
				{
					cin.clear();
					cin.sync();
					
					kolor(13); cout<<" !!!---Zla wartosc!---!!!"<<endl
						<<"    Sprobuj ponownie!";
					pause();
					system("CLS");
				}		
		}//while menu 1

		switch( wyborMenu1 )
		{
			case 0:
				{
					kolor(13);
					cout<<"  Czy napewno chcesz wyjsc?(Y/N): ";
					cin>>wyborWyjscie;
					
					if( wyborWyjscie == 'Y' or wyborWyjscie == '1' or wyborWyjscie == 'y' )
					{
						outKolor( 13 , "  !!!---Zamykam program---!!!" );
						kolor(8);
						return 0;
					}else
						{
							outKolor( 10 , "  !!!---Nie zamykam programu---!!!" );
							pause();
						}
						
					break;
				}
				
			case 1:
				{
					system("klient.exe");
					return 0;
					break;
				}
				
			case 2:
				{
					system("pokoje.exe");
					return 0;
					break;
				}
				
			case 3:
				{
					system("uslugi.exe");
					return 0;
					break;
				}
				
			case 4:
				{
					system("pobyt.exe");
					return 0;
					break;
				}		
		}//switch

	}//while program
	
	return 0;
}
