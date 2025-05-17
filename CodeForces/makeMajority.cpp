#include <bits/stdc++.h>

using namespace std;

bool solve(const string &onesZeros){
    bool countZero = false;
    int countOnes = 0, countZeros = 0;

    for(int i = 0; i < onesZeros.size(); i++){
        if(onesZeros[i] == '1') {
            countZero = false;
            countOnes++;
        }
        
        if(onesZeros[i] == '0'){
            if(!countZero){
                countZero = true;
                countZeros++;
            }
        }
    }

    if(countOnes > countZeros) return true;
    else  return false;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string onesZeros; cin >> onesZeros;

        if(solve(onesZeros)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}