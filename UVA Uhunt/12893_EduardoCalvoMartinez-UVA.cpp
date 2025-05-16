#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void count(){
    unsigned long long  n; cin >> n;
    unsigned long long mask = 1, ans = 0;

    while(n >= mask){
        if( (n & mask) != 0) ans++;
        mask <<= 1;
    }

    cout << ans << endl;
}

int main(){ 
    int t; cin >> t;
    while(t--) count();

	return 0;
}