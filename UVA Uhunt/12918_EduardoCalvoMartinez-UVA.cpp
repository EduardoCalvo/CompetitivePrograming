#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(const int &n, const int &m){
    return (unsigned long long) (n*m - (m*(m+1))/2);
}

int main(){
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        unsigned long long m, n; cin >> m >> n;
        cout << (unsigned long long) (solve(n , m)) << endl;
    }

    return 0;
}