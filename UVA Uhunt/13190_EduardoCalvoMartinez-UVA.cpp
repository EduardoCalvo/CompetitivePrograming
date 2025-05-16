#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string>> listOfMed(const vector<pair<string, int>> &medicines, const int &k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> whatNext;
    vector<pair<int, string>> treatment;

    for(int i = 0; i < medicines.size(); i++) whatNext.push({medicines[i].second, i});
    
    for(int i = 0; i < k; i++){
        int idx = whatNext.top().second, time = whatNext.top().first;/* 
        cout << whatNext.top().first << " " << whatNext.top().second << endl; */
        whatNext.pop();

        treatment.push_back({time, medicines[idx].first});
        whatNext.push({time + medicines[idx].second, idx});
    }

    return treatment;
}

int main(){
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        int n, k; cin >> n >> k;
        vector<pair<string,int>> meds; vector<pair<int,string>> ans;

        for(int j = 0; j < n; j++){
            string med; int frec;
            cin >> med >> frec;

            meds.push_back({med, frec});
        }

        ans = listOfMed(meds, k);

        for(int j = 0; j < ans.size(); j++){
            cout << ans[j].first << " " << ans[j].second << endl;
        }
    }

    return 0;
}