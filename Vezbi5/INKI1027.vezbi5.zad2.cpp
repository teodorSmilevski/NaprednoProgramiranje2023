//Teodor Smilevski INKI1027
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int sobiranje(int a, int b)
{
	return a+b;
}
int odzemanje(int a, int b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
float delenje(int a, int b)
{
	if(a>b)
	return a/b;
	else
	return b/a;
}
double stepenuvanje(int a, int b)
{
	return pow(a,b);
}
int main()
{
	string ime="Teodor", prezime="Smilevski";
	int x=(int)ime[0];
	int y=(int)prezime[0];
	void* a=&x;
	void* b=&y;
	cout<<"Operacii na broevite "<<*(int *)a<<" i "<<*(int *)b<<" :\n";
	cout<<"Sobiranje : "<<sobiranje(*(int *)a,*(int *)b)<<"\n";
	cout<<"Odzemanje : "<<odzemanje(*(int *)a,*(int *)b)<<"\n";
	cout<<"Delenje : "<<delenje(*(int *)a,*(int *)b)<<"\n";
	cout<<"Stepenuvanje : "<<stepenuvanje(*(int *)a,*(int *)b)<<"\n";
	return 0;
}
