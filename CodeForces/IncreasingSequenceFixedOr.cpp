#include <bits/stdc++.h>

using namespace std;

vector<int> solve(const int &n){
    vector<int> ans;
    int last = n, actual = n-1;

    ans.push_back(last);

    while(actual > 0){
        if((last|actual) == n) {
            last = actual;
            ans.push_back(actual);
        }
        actual--;
    }

    return ans;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> ans = solve(n);

        cout << ans.size() << endl;
        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}