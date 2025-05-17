#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map <string, string> adelante;
    set<string> people, isNotFirst;
    string start;   
    vector <string> fila;

    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        string fir, sec; cin >> fir >> sec;
        adelante[fir] = sec;

        people.insert(fir); people.insert(sec);
        isNotFirst.insert(sec);
    }

    //Encontramos que persona no tiene a alguien atrás
    for(auto person:people){
        if (isNotFirst.find(person) == isNotFirst.end()){
            start = person;
            break;
        }
    }
    
    fila.push_back(start);
    string actual = start;

    for(int i = 0; i < n-1; i++){
        string piv = adelante[actual];
        fila.push_back(piv);
        adelante.erase(actual);
        actual = piv;         
    }

    for(int i = fila.size() - 1; i >= 0; i--) cout << fila[i] << endl;

    return 0;
}