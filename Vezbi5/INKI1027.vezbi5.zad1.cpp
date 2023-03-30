//Teodor Smilevski INKI1027
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char pesna[]="This is the life - Amy Macdonald";
	int n=strlen(pesna);
	char *poc=pesna;
	cout<<"Cela pesna : "<<poc<<endl<<"Pocetna pozicija na pokazuvacot : "<<*poc<<"\nAdresa na pocetok : "<<&poc;
	int i,k=1;
	for(i=0;i<n;i++)
	{
		k=k+1;
		if(pesna[i]=='-')
		break;
	}
	poc+=k;
	cout<<"\nPomestuvanje do ime na izveduvach\nSodrzina po premesten pochetok : "<<poc<<"\nAdresa od koja pocnuva segashnata sodrzina "<<(&poc+k);
	return 0;
}
