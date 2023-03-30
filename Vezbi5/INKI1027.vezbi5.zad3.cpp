//Teodor Smilevski INKI1027
#include <iostream>
#include <cstring>
using namespace std;
string promenaNaIme(string ime, string char1);
string promenaNaPrezime(string prezime, string char2);
int main()
{
	string ime = "Teodor",prezime = "Smilevski";
	string char1 = "!@#$", char2 = "%^&*";
	cout<<ime<<" => "<<promenaNaIme(ime,char1)<<"\n"<<prezime<<" => "<<promenaNaPrezime(prezime,char2);
	return 0;
}
string promenaNaIme(string ime, string char1)
{
	int i;
	for(i=0;i<4;i++)
	{
		ime[i] = char1[i];
	}
	return ime;
}
string promenaNaPrezime(string prezime, string char2)
{
	int i;
	for(i=0;i<4;i++)
	{
		prezime[i] = char2[i];
	}
	return prezime;
}
