#include <bits/stdc++.h>
using namespace std;

vector<int> dp(2000001, 0), arr = dp;

bool cmp(int a, int b){
    return (dp[a] == dp[b])? a < b : dp[a] < dp[b];
}

int main(){
    arr[1] = 1; dp[1] = 1;

    for(int i = 2; i <= 2000000; i++){
        arr[i] = i; int x = i;
        
        map<int, int> primes; primes.clear();
        for(int j = 2; j <= sqrt(x); j++){
            while(x%j == 0){
                primes[j]++;
                x /= j;
            }
        }

        if(x > 1) primes[x]++;

        for(auto p : primes) dp[i] += p.second;
    }

    sort(arr.begin(), arr.end(), cmp);

    int n, c = 1;

    while(cin >> n && n) cout << "Case " << c++ << ": " << arr[n] << endl;

    return 0;
}