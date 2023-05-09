#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;


int main() {
	 
	 // kreiranje na mapa
	 map<string, int> temp = { { "Bitola", 10 }, { "Kumanovo", 13 }, { "Skopje", 8 }, { "Prilep", 11 }, { "Ohrid", 14 },
	  { "Debar", 15 } , { "Tetovo", 9 } , { "Strumica", 16 }  };
    
    // otvaranje na datoteka
     ofstream file("INKI1027.TeodorSmilevski.txt");
	

	// pecatenje na nesortirana mapa
    map<string, int>::iterator it = temp.begin();
    cout<<"\n Pecatenje na nesortirana mapa\n";
	for(int i = 0; i < 8; i++){
   	 	std::cout<< it->first << " - " << it->second << std::endl;
    	it++;
	}
	
	temp["INKI"] = 1027;
    temp["Teodor"] = 610;
    
    // Deklariranje komparator koj prima 2 para i vrakja bool vrednost
	typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
	
	 // Deklariranje funkcija za sporeduvanje na dva para. 
	 Comparator compFunctor =
            [](pair<string, int> elem1 ,pair<string, int> elem2)
            {
                return elem1.second < elem2.second;
            };
            
    // Deklariranje na set koj skladira parovite koristejki na gorenavedenata logika
    set<pair<string, int>, Comparator> setOfWords(
            temp.begin(), temp.end(), compFunctor);
    
    // Pecati sortirana mapa
    cout<<"\n Pecatenje na sortirana mapa \n";    
    for (pair<string, int> element : setOfWords) {
        cout << element.first << " - " << element.second << endl;
    
        // Ispisuvanje vo datoteka
        if (file.is_open()) {
            file << element.first << " " << element.second << endl;
        }
    }
    file.close();
   
  return 0;
	 
}
