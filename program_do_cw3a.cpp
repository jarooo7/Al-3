//program demonstracyjny, kompilowany w Dev C++,
//na pocz¹tku programu za³¹czamy biblioteki i pliki naglowkowe ze zdefiniowanymi funkcjami
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <list>
//Pliki z rozszerzeniem .h zawieraja tylko prototypy funkcji, kody znajduja
//sie w plikach o tych samych nazwach lecz z rozszerzeniem .cpp
#include "matrix.h"

//deklarujemy u¿ywanie przestrzeni nazw std, zawieraj¹cej wiele przydatnych komend,
//je¿eli nie zdeklarowalibyœmy przestrzeni nazw std, przed komendami tej przestrzeni nale¿a³oby u¿yæ zapisu std::
// np. std::cout<<"tekst";         
using namespace std;
struct t{
	double **tab;
	string s;
};

//w funkcji main mamy nasz g³ówny program,
int main (void) {
cout<<"Program pomocniczy do cw1\n";

//definiujemy nazwe pliku, musi istnieæ w katalogu programu
string nazwa_trn="SystemTreningowy.txt";

//korzystamy z funkcji umieszczonych w pliku matrix.h
// w celu znalezienia rozmiaru wczytywanego pliku,
//plik powinien byc w formacie
//6 2 5 6 1
//5 8 9 2 0
int wym2_trn=num_rows_file(nazwa_trn.c_str());
int wym1_trn=num_cols_file(nazwa_trn.c_str());

//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
int rows = wym2_trn+1;
std::string **G_trn;
G_trn = new std::string*[rows];
while(rows--) G_trn[rows] = new std::string[wym1_trn+1];

////wczytujemy tablice w postaci string, czyli jej elementy traktujemy jako stringi(ci¹gi znaków)
//wym2 to liczba wierszy
//wym1 to liczba kolumn
//G_trn nasza tablica stringów
//nazwap.c_str() podajemy nazwe wczytywanego pliku w odpowiednim formacie do funkcji.

cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwa_trn;
getchar();
wczytywanie(wym2_trn,wym1_trn,G_trn,nazwa_trn.c_str());
//wypisujemy wczytan¹ tablicê na ekran
cout<<"\nWypisujemy na ekran wczytana tablice\n\n";
for(int i=1;i<wym2_trn+1;i++){
  for(int j=1;j<wym1_trn+1;j++){
    cout<<" "<<G_trn[i][j];
  }
  cout<<"\n";
}

//definiujemy nazwe pliku, musi istnieæ w katalogu programu
string nazwa_tst="SystemTestowy.txt";

//korzystamy z funkcji umieszczonych w pliku matrix.h
// w celu znalezienia rozmiaru wczytywanego pliku,
//plik powinien byc w formacie
//6 2 5 6 1
//5 8 9 2 0

int wym2_tst=num_rows_file(nazwa_tst.c_str());
int wym1_tst=num_cols_file(nazwa_tst.c_str());

//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
rows = wym2_tst+1;
std::string **G_tst;
G_tst = new std::string*[rows];
while(rows--) G_tst[rows] = new std::string[wym1_tst+1];

////wczytujemy tablice w postaci string, czyli jej elementy traktujemy jako stringi(ci¹gi znaków)
//wym2 to liczba wierszy
//wym1 to liczba kolumn
//G nasza tablica stringów
//nazwap.c_str() podajemy nazwe wczytywanego pliku w odpowiednim formacie do funkcji.
cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwa_tst;
getchar();
wczytywanie(wym2_tst,wym1_tst,G_tst,nazwa_tst.c_str());

//wypisujemy wczytan¹ tablicê na ekran
cout<<"\nWypisujemy na ekran wczytana tablice\n\n";
for(int i=1;i<wym2_tst+1;i++){
  for(int j=1;j<wym1_tst+1;j++){
    cout<<" "<<G_tst[i][j];
  }
  cout<<"\n";
} 

//******************************************************
//MIEJSCE NA ROZWIAZANIE 
string tab_klas[wym2_tst];
int liczba_klas=0;
bool flaga;
 tab_klas[0]=G_tst[1][wym1_tst];
  for(int i=1;i<wym2_tst+1;i++)
  	{
  		flaga=true;
  		for(int j=0;j<=liczba_klas;j++){
		  
  			if(G_tst[i][wym1_tst]==tab_klas[j]){
  				flaga=false;
		  	}
		  }
		  if(flaga){
		  	liczba_klas++;
		  	tab_klas[liczba_klas]=G_tst[i][wym1_tst];
		  }
	  }
	    cout<<endl<<"Klasy decyzyjne to:"<<endl;
	  for(int j=0;j<=liczba_klas;j++){
    cout<<tab_klas[j]<<endl;
  }

  list<t>ltab;
  t element;
  
  rows = wym2_tst+1;
element.tab= new double*[rows];
while(rows--) element.tab[rows] = new double[wym2_tst+1];
 
 double **tab_euk;
 rows = wym2_tst+1;
tab_euk= new double*[rows];
while(rows--) tab_euk[rows] = new double[wym2_tst+1];
 
  double **tab_m;
 rows = wym2_tst+1;
tab_m= new double*[rows];
while(rows--) tab_m[rows] = new double[wym2_tst+1];
 double **tab_can;
 rows = wym2_tst+1;
tab_can= new double*[rows];
while(rows--) tab_can[rows] = new double[wym2_tst+1];
 
 double **tab_cz;
 rows = wym2_tst+1;
tab_cz= new double*[rows];
while(rows--) tab_cz[rows] = new double[wym2_tst+1];
 
 double **tab_p;
 rows = wym2_tst+1;
tab_p= new double*[rows];
while(rows--) tab_p[rows] = new double[wym2_tst+1];

double suma;
double suma2; 
double suma3;
double max;
double s_x;
double s_y;
double t_x;
double t_y;
double t_xy;
double min1[liczba_klas+2][wym2_tst+1];
double min2[liczba_klas+2][wym2_tst+1];
int id_min1[liczba_klas+2][wym2_tst+1];
int id_min2[liczba_klas+2][wym2_tst+1];
double summin[liczba_klas+2][wym2_tst+1];
double minsum[wym2_tst+1];
string idsum[wym2_tst+1];
int s_t=0;

double intmacipred[liczba_klas+3][liczba_klas+5];
int indexX,indexY;
 for(int i=1;i<=wym2_tst;i++)
 {
 	for(int j=1;j<=wym2_trn;j++)
	 {
	 	suma=0;
	 	suma2=0;
	 	suma3=0;
	 	s_x=0;
	 	s_y=0;
	 	max=abs(string_to_double(G_tst[i][1])-string_to_double(G_trn[j][1]));
	 	
	 	for(int k=1;k<wym1_trn;k++)
	 	 {
	 	 	suma+=pow((string_to_double(G_tst[i][k])-string_to_double(G_trn[j][k])),2);
	 	 	suma2+=abs(string_to_double(G_tst[i][k])-string_to_double(G_trn[j][k]));
	 	 	suma3+=abs((string_to_double(G_tst[i][k])-string_to_double(G_trn[j][k]))/(string_to_double(G_tst[i][k])+string_to_double(G_trn[j][k])));
	 	 	if(max<abs(string_to_double(G_tst[i][k])-string_to_double(G_trn[j][k]))){
	 	 		max=abs(string_to_double(G_tst[i][k])-string_to_double(G_trn[j][k]));
			  }
			s_x+=string_to_double(G_tst[i][k]);
			s_y+=string_to_double(G_trn[j][k]);
		 }
		 s_x=s_x/(wym1_tst-1);
		 s_y=s_y/(wym1_trn-1);
		 tab_euk[i][j]=sqrt(suma);
		 tab_m[i][j]=suma2;
		 tab_can[i][j]=suma3;
		 tab_cz[i][j]=max;
		 t_x=0;
		 t_y=0;
		 t_xy=0;
		 for(int k=1;k<wym1_tst;k++)
	 	 {
	 	 	t_x+=pow((string_to_double(G_tst[i][k])-s_x),2);
	 	 	t_y+=pow((string_to_double(G_trn[j][k])-s_y),2);
		  }
		  t_x=sqrt(t_x/(wym1_tst-1));
		  t_y=sqrt(t_y/(wym1_trn-1));
		  for(int k=1;k<wym1_tst;k++)
	 	 {
	 	 	t_xy+=((string_to_double(G_tst[i][k])-s_x)/t_x)*((string_to_double(G_trn[j][k])-s_y)/t_y);
		  }
		 tab_p[i][j]=1-abs(t_xy/(wym1_tst-1));
	 }
 }
 
 
  element.tab=tab_euk;
  element.s=" metryka Euklidesowa";
  ltab.push_back(element);
  
  element.tab=tab_m;
  element.s=" metryka Manhattan";
  ltab.push_back(element);
  
  element.tab=tab_can;
  element.s=" metryka Canberra";
  ltab.push_back(element);
  
  element.tab=tab_cz;
  element.s=" metryka Czebyszewa";
  ltab.push_back(element);
  
  element.tab=tab_p;
  element.s=" bezwzglednym wspolczynnikiem korelacji Pearsona";
  ltab.push_back(element);
  
  

 for( list<t>::iterator iter=ltab.begin(); iter != ltab.end(); iter++ ){
 
 cout<<endl<<"Macierz obliczona"<<iter->s<<endl;
 for(int i=1;i<wym2_tst+1;i++){
 	cout<<"x"<<i;
  for(int j=1;j<wym2_trn+1;j++){
     cout<<"\t";
printf("%.3f",iter->tab[i][j]);
  }
  cout<<"\n";
} 
 cout<<"\n";
  cout<<"\n";
}




int tmp;

 /////////////////////////////////////////////////////////////////////////////////////////////
  for( list<t>::iterator iter=ltab.begin(); iter != ltab.end(); iter++ ){
 	cout<<"\n\nWcisnij dowolny klawisz by przejsc dalej";
 	getchar();
 	cout<<"/////////////////////////////////////////////////////////////////////////////////////////////\n\n";

 
  cout<<endl<<"Klasyfikacja obliczona"<<iter->s<<endl;
 for(int j=1;j<wym2_tst+1;j++){
 	for(int i=1;i<=liczba_klas+1;i++){
 	tmp=1;
 	while(G_trn[tmp][wym1_trn]!=tab_klas[i-1]){
	 tmp++;
	 	}
 	min1[i][j]=iter->tab[j][tmp];
 	id_min1[i][j]=tmp;

  for(int k=1;k<wym2_trn+1;k++){
  	if(min1[i][j]>iter->tab[j][k]&&G_trn[k][wym1_trn]==tab_klas[i-1])
  	  {
  		min1[i][j]=iter->tab[j][k];
  		id_min1[i][j]=k;
	  }
  }
  
  	tmp=1;
 	while(G_trn[tmp][wym1_trn]!=tab_klas[i-1]||tmp==id_min1[i][j]){
	 tmp++;
	 	}
 	min2[i][j]=iter->tab[j][tmp];
 	id_min2[i][j]=tmp;
	
  for(int k=1;k<wym2_trn+1;k++){
  	if(min2[i][j]>iter->tab[j][k]&&G_trn[k][wym1_trn]==tab_klas[i-1]&&k!=id_min1[i][j])
  	  {
  		min2[i][j]=iter->tab[j][k];
  		id_min2[i][j]=k;
	  }
  }
  		summin[i][j]=min1[i][j]+min2[i][j];
 }
 }

 for(int j=1;j<wym2_trn+1;j++){
 	minsum[j]=summin[1][j];
 	idsum[j]=tab_klas[0];
  	for(int i=2;i<=liczba_klas+1;i++){
    if(minsum[j]>=summin[i][j])
    {
    	if(minsum[j]==summin[i][j]){
    			idsum[j]="r";
		}
		else{
				minsum[j]=summin[i][j];
 				idsum[j]=tab_klas[i-1];
		}
	}
  }

}

  cout<<"\n";
for(int j=1;j<wym2_trn+1;j++){
 	
 	cout<<"x"<<j;
  	for(int i=1;i<=liczba_klas+1;i++){
  		printf("\t| y%d+y%d\t%.3f\t+\t%.3f\t=%.3f",id_min1[i][j],id_min2[i][j],min1[i][j],min2[i][j],summin[i][j]);
  }
  cout<<"\t | "<<idsum[j]<<"\t="<<minsum[j]<<endl;

}



    cout<<"\n\tc\n";
 for(int j=1;j<wym2_trn+1;j++){
 	 cout<<"x"<<j<<"\t";
    cout<<G_tst[j][wym1_tst];
    if(idsum[j]=="r"){
    	cout<<"\tnie jest chwytany\n";
	}
	else{
		if(idsum[j]==G_tst[j][wym1_tst])
		{
			cout<<"\tdecyzja "<<idsum[j]<<", objekt jest poprawnie sklasyfikowany\n";
		}
		else
		{
			cout<<"\tdecyzja "<<idsum[j]<<", objekt jest blendnie sklasyfikowany\n";
		}
	}
  }
cout<<"\n";
cout<<"\n";

for(int i=1;i<=liczba_klas+2;i++){
for(int j=1;j<=liczba_klas+4;j++){
 	intmacipred[i][j]=0;
	 }
}
	
 for(int j=0;j<=liczba_klas;j++){
 	intmacipred[0][j+1]=string_to_double(tab_klas[j]);
	intmacipred[j+1][0]=string_to_double(tab_klas[j]);
}
 for(int k=1;k<wym2_tst+1;k++){
 	for(int j=0;j<=liczba_klas;j++){
	 if(G_tst[k][wym1_tst]==tab_klas[j])
	 intmacipred[j+1][liczba_klas+2]++;
	 }
 	if(idsum[k]!="r"){

for(int j=0;j<=liczba_klas;j++){

	if(idsum[k]==tab_klas[j])
	indexY=j+1;}
	for(int j=0;j<=liczba_klas;j++){

	if(G_tst[k][wym1_tst]==tab_klas[j])
	indexX=j+1;}
}
intmacipred[indexX][indexY]++;
}

for(int i=1;i<=liczba_klas+1;i++){
	s_t=0;
  for(int j=1;j<=liczba_klas+1;j++){
  	s_t+=intmacipred[j][i];
}
	intmacipred[liczba_klas+2][i]=intmacipred[i][i]/s_t;
}

for(int i=1;i<=liczba_klas+1;i++){
	s_t=0;
  for(int j=1;j<=liczba_klas+1;j++){
  	s_t+=intmacipred[i][j];
}
	intmacipred[i][liczba_klas+3]=intmacipred[i][i]/s_t;
	intmacipred[i][liczba_klas+4]=s_t/intmacipred[i][liczba_klas+2];
}


cout<<"\t ";
for(int j=1;j<=liczba_klas+1;j++){
	cout<<intmacipred[0][j]<<"\t";
}
cout<<"No. of obj\tAccuracy\tCoverage ";
 cout<<"\n";
 for(int j=0;j<=liczba_klas+6;j++){
	cout<<"________";
}
 cout<<"\n";

for(int i=1;i<=liczba_klas+1;i++){
	cout<<intmacipred[i][0]<<"\t|";
  for(int j=1;j<=liczba_klas+2;j++){
    cout<<intmacipred[i][j]<<"\t";
  }
  printf("\t%.3f\t\t%.3f",intmacipred[i][liczba_klas+3],intmacipred[i][liczba_klas+4]);
  
  cout<<"\n";

} 
 for(int j=0;j<=liczba_klas+6;j++){
	cout<<"________";
}
 cout<<"\n";
cout<<"TPR\t ";
for(int j=1;j<=liczba_klas+1;j++){
    printf("%.3f\t",intmacipred[liczba_klas+2][j]);
  }
  cout<<"\n";

}
///////////////////////////////////////////////////////////////////////////
 
//KONIEC MIEJSCA NA ROZWIAZANIE  
//******************************************************

cout<<"\n\nPrzykladowa konwersja string do double i operacja na skonwertowanych wartosciach";
getchar();
double temp1,temp2;
double wynik;
//wrzucam do temp1 i temp2 wartosci G[1][1],G[1][2] z mojej tablicy G i dodaje te wartoœci;
//pamietamy, ze wartosci tablicy sa typu string, stad zanim zaczniemy wykonywac operacje
// trzeba je przekonwertowac do odpowiedniego typu,
// w naszym przypadku potrzebujemy wartosci ca³kowitych stad uzywamy string_to_int,
temp1=string_to_double(G_trn[1][1]);
temp2=string_to_double(G_trn[1][2]);
wynik=temp1+temp2;

//wyswietlamy wynik
cout<<"\n"<<temp1<<" + "<<temp2<<" = "<<wynik;

//funkcja zapisuje tablice stringów do pliku, podajemy
string nazwa_temp="przyklad_zapisu.txt";
cout<<"\n\nNacisnij ENTER aby wykonac demonstracyjny zapis pliku o nazwie "<<nazwa_temp;
getchar();
zapis(wym2_trn,wym1_trn,G_trn,nazwa_temp.c_str());

//na koniec czyœcimy pamiêæ po naszej tablicy
for(int i=0;i<wym2_trn+1;i++)
{delete[] G_trn[i];}//czyscimy wiersze
delete[] G_trn;//zwalniamy tablice wskaznikow do wierszy

//na koniec czyœcimy pamiêæ po naszej tablicy
for(int i=0;i<wym2_tst+1;i++)
{delete[] G_tst[i];}//czyscimy wiersze
delete[] G_tst;//zwalniamy tablice wskaznikow do wierszy

cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();

//na koniec nasza funkcja zwraca wartoœæ 0 i program siê koñczy
return 0;
}
