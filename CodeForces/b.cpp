//EduardoCalvoMartinez
#include <bits/stdc++.h>

using namespace std;
/* 
int nonOrd(vector<int> a){
    int countNonOrd = 0;

    for(int i = 1; i < a.size(); i++) if(a[i-1] > a[i]) countNonOrd++;

    return countNonOrd;
} */

vector<int> differences(vector<int> a){
    int countNonOrd = 0;
    vector<int> differences;

    for(int i = 1; i < a.size(); i++) if(a[i-1] > a[i]) differences.push_back(a[i-1] - a[i]);  

    sort(differences.begin(), differences.end());
    return differences;
}

int solve(const vector<int> &diff){
    int coinsCounter = 0;
    int accDif = 0;

    for(int i = 0; i < diff.size(); i++){
        int piv = (diff[i] - accDif);

        coinsCounter += piv*(diff.size() - (i - 1));
        accDif += piv;
    }

    return coinsCounter;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> a(n);
    
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> diff = differences(a);
        
        cout << solve(diff) << endl;
    }

    return 0;
}