//EduardoCalvoMartinez
#include <bits/stdc++.h>

using namespace std;

int numberOfSeconds(const int &n, const int &k){
    int counterofGb = 0, counterofSeconds = 0;

    while(counterofGb < n-1) {
        counterofGb++;
        counterofSeconds += k;
    }
    
    counterofSeconds++;

    return counterofSeconds;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        cout << numberOfSeconds(n, k) << endl;
    }

    return 0;
}