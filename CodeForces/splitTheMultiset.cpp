#include <bits/stdc++.h>

using namespace std;

int solve(int &n, const int &k){
    int count = 0;
    while(n > 1){
        count++;

        if(n > k) n -= (k-1);
        else n -= k;
    
    }

    return count;
}


int main(){
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        cout << solve(n, k) << endl;
    }

    return 0;
}
