// Delenje na karti - Teodor Smilevski INKI1027
/* Ovoj kod e sostaven vrz osnova na bitolskata igra beljot. Vo ovaa igra ne se igra so site karti tuku samo 
 so 32 karti(7, 8, 9, 10, J, Q, K, A) i bez jokeri. Kartite se mesaat i se secat na polovina - gorniot del odi dolu. 
 Se delat po 8 karti na igrac. Prviot pat se delat po 5 karti(eden krug 3, vtor krug po 2). Slednata karta sto sledi
 se vadi na sredina za igra. Koga nekoj igrac ja zemi taa karta, bojata stanuva adut. Na igracot sto ja zede kartata mu
 se dodeluvaat 2 karti, a na ostanatite igraci po 3. */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int brojKarti = 32;
int bojaGolemina = 8;
// Kupa - srce, Crno - list, Karo - baklava, Spato - detelina
string boja[4] = {"kupa", "crno", "karo", "spato"};
string broj[8] = {"7", "8", "9", "10", "J", "Q", "K", "A"};

void pecatiSpil(string spil[], int n) {
	for(int i=0; i<n; i++) {
		i % 8 == 0 && cout<<endl;
		cout<<spil[i]<<" ";
	}
}
void mesanjeNaKarti(string spil[], int n) {
	for(int i=0; i<n; i++) {
		int random = rand() % n;
		string temp = spil[i];
		spil[i] = spil[random];
		spil[random] = temp;
	}
}
void seciSpil(string spil[], int n) {
	string temp[n];
	int j = n/2, x = 0;
	for(int i=0; i<n/2; i++) {
		temp[i] = spil[i];
		spil[i] = spil[j];
		j++;
	}
	for(int i=n/2; i<n; i++) {
		spil[i] = temp[x];
		x++;
	}
}
void zemaIgrac1(string igrac1[],string igrac2[],string igrac3[],string igrac4[],string kartaSredina,string spil[]) {
	igrac1[5] = kartaSredina; igrac1[6]=spil[21]; igrac1[7]=spil[22];
	igrac2[5] = spil[23]; igrac2[6] = spil[24]; igrac2[7] = spil[25];
	igrac3[5] = spil[26]; igrac3[6] = spil[27]; igrac3[7] = spil[28];
	igrac4[5] = spil[29]; igrac4[6] = spil[30]; igrac4[7] = spil[31];
}
void zemaIgrac2(string igrac1[],string igrac2[],string igrac3[],string igrac4[],string kartaSredina,string spil[]) {
	igrac1[5] = spil[21]; igrac1[6] = spil[22]; igrac1[7] = spil[23];
	igrac2[5] = kartaSredina; igrac2[6]=spil[24]; igrac2[7]=spil[25];
	igrac3[5] = spil[26]; igrac3[6] = spil[27]; igrac3[7] = spil[28];
	igrac4[5] = spil[29]; igrac4[6] = spil[30]; igrac4[7] = spil[31];
}
void zemaIgrac3(string igrac1[],string igrac2[],string igrac3[],string igrac4[],string kartaSredina,string spil[]) {
	igrac1[5] = spil[21]; igrac1[6] = spil[22]; igrac1[7] = spil[23];
	igrac2[5] = spil[24]; igrac2[6] = spil[25]; igrac2[7] = spil[26];
	igrac3[5] = kartaSredina; igrac3[6]=spil[27]; igrac3[7]=spil[28];
	igrac4[5] = spil[29]; igrac4[6] = spil[30]; igrac4[7] = spil[31];
}
void zemaIgrac4(string igrac1[],string igrac2[],string igrac3[],string igrac4[],string kartaSredina,string spil[]) {
	igrac1[5] = spil[21]; igrac1[6] = spil[22]; igrac1[7] = spil[23];
	igrac2[5] = spil[24]; igrac2[6] = spil[25]; igrac2[7] = spil[26];
	igrac3[5] = spil[27]; igrac3[6] = spil[28]; igrac3[7] = spil[29];
	igrac4[5] = kartaSredina; igrac4[6]=spil[30]; igrac4[7]=spil[31];
}
void delenjeKarti(string spil[], int n) {
	string igrac1[8], igrac2[8], igrac3[8], igrac4[8], kartaSredina;
	int i1=0,i2=0,i3=0,i4=0;
	// for loop za delenje na karti (prv krug po 3, vtor krug po 2)
		for(int j=0; j<20; j++) {
			if((j<3) || (j>11&&j<14)) {
				igrac1[i1] = spil[j];
				i1++;
			} 
			if((j>2&&j<6) || (j>13&&j<16)) {
				igrac2[i2] = spil[j];
				i2++;
			}
			if((j>5&&j<9) || (j>15&&j<18)) {
			igrac3[i3] = spil[j];
				i3++;	
			}
			if((j>8&&j<12) || (j>17&&j<20)) {
			igrac4[i4] = spil[j];
				i4++;	
			}
		}
	// karta na sredina - ADUT
	kartaSredina = spil[20];
	cout<<"IGRAC 1\t\tIGRAC 2\t\tIGRAC 3\t\tIGRAC 4\n";
	for(int i=0; i<5; i++) {
		cout<<igrac1[i]<<"\t"<<igrac2[i]<<"\t"<<igrac3[i]<<"\t"<<igrac4[i]<<"\n";
	}
	cout<<"\n\t\t KARTA NA SREDINA: "<<kartaSredina<<"\n";
	int igrac;
	cout<<"\n Koj igrac ja zema kartata? 1, 2, 3 ili 4? => ";
	cin>>igrac;	
	int max = 3;
	if(igrac == 1) zemaIgrac1(igrac1,igrac2,igrac3,igrac4,kartaSredina,spil);
	if(igrac == 2) zemaIgrac2(igrac1,igrac2,igrac3,igrac4,kartaSredina,spil);
	if(igrac == 3) zemaIgrac3(igrac1,igrac2,igrac3,igrac4,kartaSredina,spil);
	if(igrac == 4) zemaIgrac4(igrac1,igrac2,igrac3,igrac4,kartaSredina,spil);
	
	// pecatenje na krajniot izvejstaj na podeleniot spil karti.
	cout<<endl;
	cout<<"\n\t\tPODELENI SE SITE KARTI. \n";
	cout<<"IGRAC1\t\tIGRAC2\t\tIGRAC3\t\tIGRAC4\n";
	for(int i=0; i<8; i++) {
		cout<<igrac1[i]<<"\t"<<igrac2[i]<<"\t"<<igrac3[i]<<"\t"<<igrac4[i]<<"\n";
	}
}

int main() {
	string spil[brojKarti];
	int index = 0;
	
	for(int i=0; i<bojaGolemina; i++)
	for(int j=0; j<4; j++) {
		spil[index] = "["+broj[i]+"-"+boja[j]+"]";
		index++;
	}
	
	cout<<"\nPodreden spil:";
	pecatiSpil(spil,brojKarti);
	cout<<endl;
	
	// mesanje na karti
	mesanjeNaKarti(spil, brojKarti);
	//	pecatiSpil(spil, brojKarti);

	cout<<"\nIzmesan spil i secen na pola:";
	// secenje spil na pola (gornata polovina odi dolu)
	seciSpil(spil, brojKarti);
	pecatiSpil(spil, brojKarti);
	
	/////////////////////////////////////////////////////
	cout<<endl;
	cout<<"\n\t\t == PODELENI KARTI == \n";
	delenjeKarti(spil, brojKarti);
	
	return 0;
}

