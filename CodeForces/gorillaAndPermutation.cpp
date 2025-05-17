#include <bits/stdc++.h>

using namespace std;

vector<int> permutation(const int &n, const int &m, const int &k){
    vector<int> ans; 

    for(int i = n; i >= k; i--) ans.push_back(i);
    for(int i = m+1; i < k; i++) ans.push_back(i);
    for(int i = 1; i <= m; i++) ans.push_back(i);
    
    return ans;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n, m, k; cin >> n >> m >> k;
        vector<int> ans = permutation(n, m, k);

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}