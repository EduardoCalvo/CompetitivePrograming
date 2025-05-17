#include <bits/stdc++.h>

using namespace std;

int puntaje(char c){
    if (int (c) <= int ('9') && int(c) >= int('0')) 
        return int(c) - int('0');
    else if (int(c) <= int('Z') && int(c) >= int('A')) 
        return (int(c) - int('A') + 10)*2;
    else if (int(c) <= int('z') && int(c) >= int('a'))
        return (int(c) - int('a') + 10);
}

int main(){
    string A, B; cin >> A >> B;
    int puntA = 0, puntB = 0;

    for(int i = 0; i < A.size(); i++) puntA += puntaje(A[i]);
    for(int i = 0; i < B.size(); i++) puntB += puntaje(B[i]);

    if (puntA > puntB) cout << "Ana " << puntA << endl;
    else cout << "Carolina " << puntB << endl;

    return 0; 
}