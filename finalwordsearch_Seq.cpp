#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string substring(int start, int length, string strword) {
    string a = "";
    for (int i = start; i < length; i++) {
        a += strword[i];
    }
    return a;
}
int find_all(string sen, string word) {
    int wordLen = word.length();
    int start = 0;
    int endword = wordLen;
    int finLength = sen.length();
    int count = 0;
    string senWord = "";
    for (int i = 0; i <= sen.length(); i++) {
        if (endword > finLength) {
            break;
        }
        senWord = substring(start, endword, sen);
        if ((senWord.compare(word)) == 0){
            count++;
            if (endword > finLength) {
                break;
            }
        }
        start += 1;
        endword += 1;
    }
    return count;
}
int display(string path, string word_to_search) {
    int totalCount = 0;
    string line;
    int count = 1;
    ifstream myfile(path);

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            totalCount += find_all(line, word_to_search);
            count++ ;

        }
    }
    else {
        cout << "File not open\n" << endl;
    }
    return totalCount; }
int main() {
    
    string word_to_search = "";
    cout << "Entrer le mot à rechercher : ";
    cin >> word_to_search;
    double start = omp_get_wtime();
    string Path = "/Users/mohamedabdallaoui/Desktop/test011_2/999txtfiles/";
 
    // #pragma omp parallel 
    
    //  #pragma omp for
    

      
    for (int i = 1; i <= 999; i++) {
        string npath = Path + "File" + to_string(i) + ".txt";
    //    #pragma omp critical
        cout << "Le mote existe  " + to_string(display(npath, word_to_search)) << " fois dans le fichier " + to_string(i) << endl;
    }
    double end = omp_get_wtime();

    cout << "Temps d'execution :" + to_string(end - start);
    return 0;
}


// entrer la commande "g++-11 -fopenmp finalwordsearch.cpp -o my1 && ./my1"