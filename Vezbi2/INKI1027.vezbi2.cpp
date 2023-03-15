#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int deckSize = 54;
const int suitSize = 13;

string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string ranks[suitSize] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string jokers[2] = {"Black Joker", "Red Joker"};

void shuffleDeck(string deck[], int size) {
	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		string temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}
void printDeck(string deck[], int size) {
	for (int i = 0; i < deckSize; i++) {
		cout<<deck[i]<<" \n";
	}	
}

int main() {
string deck[deckSize];
int index = 0;
// sostavuvanje na spil karti
for (int i = 0; i < 4; i++) {
for (int j = 0; j < suitSize; j++) {
deck[index] = ranks[j] + "[" + suits[i] + "]";
index++;
}}
deck[index] = jokers[0];
deck[index+1] = jokers[1];

cout<<"\n Podredeni:\n";
printDeck(deck, deckSize);

cout<<endl;

srand(time(NULL)); // sluchaen broj generator
shuffleDeck(deck, deckSize); // go mesha shpilot karti
cout<<"\n Izmesani:\n";
printDeck(deck,deckSize);

return 0;
}
/*  Algoritmot raboti taka sto gi spojuva trite stringovi suits, ranks i jokers vo eden string sto ni go oznacuva spilot karti
	t.e. deck so golemina od 54.
	Za meshanjeto na shpilot karti se koristat navedenite funkcii od <cstdlib> bibliotekata	t.e. rand() i srand().
	Teodor Smilevski INKI1027
*/
