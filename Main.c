#include <stdio.h>

int main()
{
	int x, y;
	int menu;				//Deklaruje zmienne
	int licznik = 0;
	
	int stos[4];			//Deklaruje tablice 'stos'
	  
	
	printf("\n");
	printf("Wpisz 0 aby odlozyc element na stos\n");
	printf("Wpisz 1 aby zdjac element ze stosu\n");
	printf("Wpisz 2 aby wyswietlic zawartosc stosu\n");					//Przedstawiam menu programu
	printf("Wpisz 3 aby wyjsc z programu\n");
	printf("Co chcesz zrobic?: ");
	scanf("%i", &menu);
	
	while(menu < 0 || menu > 3)
	{
		printf("Wprowadzona liczbe inna niz 0, 1, 2, 3\n");
		printf("Co chcesz zrobic?: ");									//Zabezpieczam program przed wpisaniem wartosci innych niz dozwolone w menu
		scanf("%i", &menu);
	}

	do							//Zapetlam funkcje switch aby wykonywala sie caly czas dopoki nie zwroci wartosci 0
	{
	   switch (menu)			//Tworze funkcje switch pozwalajaca uzytkownikowi wybrana operacje na tablicy 'stos'
	   {
	   		case 0: 		//Gdy uzytkownik wpisze '0'
			if(licznik>=4)		//Jesli zmienna licznik wieksza lub rowna 4 wypisz wiadomosc 'stos jest przepelniony'
			{					
			 printf("Stos jest przepelniony\n");
			}
		 	 else 				//W innym wypadku podaj wartosc, ktora przybierze element tablicy 'stos' o numerze rownym wartosci zmiennej licznik
			{
			 printf("Podaj wartosc ktora chcesz odlozyc na %i element stosu: ", licznik+1);
			 scanf("%i", &y);
			 stos[licznik] = y;
			}
			
			if(licznik<4)		//Jezeli zmienna licznik ma wartosc mniejsza od 4 to powieksz ja o 1
			{
				licznik++;
			}
			
			 break;				//Po wykonaniu operacji przerwij funkcje switch
	
			 case 1:			//Gdy uzytkownik wpisze '1'
			 if(licznik<=0)		//Jezeli zmienna licznik ma wartosc mniejsza lub rowna 0 wypisz 'stos jest pusty'
			 {
				printf("Stos jest pusty\n");
			 }
			 else				//W innym wypadku przypisz do wartosci zmiennej y wartosc elementu z tablicy o numerze licznik-1 a nastepnie pomniejsz licznik o 1
			 {
			 y=stos[licznik-1];
			 printf("Zdjeto %i element ze stosu o wartosci %i\n", licznik, y);
			 licznik--;
			 }
			 
			 break;			//Po wykonaniu operacji przerwij funkcje switch
			 
			 case 2: 		//Gdy uzytkownik wpisze '2'
    		 printf("Aktualny wyglad stosu:\n");    
			 if(licznik<=0)			//Jesli licznik mniejszy lub rowny 0 wypisz wiadomosc 'stos jest pusty'
			 {
				printf("Stos jest pusty\n");
			 }
			 else			//W innym wypadku wyswietl kolejne elementy tabeli 'stos' za pomoca uzycia funkcji for i zmiennej pomocniczej
			 {
				 	for(x=0; x<licznik; x++)
					{
					printf("%i\n", stos[x]);
					}
			 }
			 
	         break;		//Po wykonaniu operacji przerwij funkcje switch
			 
			 case 3:		//Gdy uzytkownik wpisze '3'
		 	 printf("Dziekuje za skorzystanie z programu."); //Poprzez zwrocenie wartosci 0 funkcja switch wychodzi z petli do while
		 	 return 0;
       }
       printf("Co chcesz zrobic?: ");				//Po wykonaniu instrukcji z menu ponownie prosi o wybranie jednej z opcji
       scanf("%i", &menu);
    }while(1);					//dopoki switch nie zwroci wartosci 0(czyli uzytkownik nie wybierze opcji '3' - wyjscia z aplikacji) to funkcja switch jest zapetlona
	
	return 0;
}
