#include <bits/stdc++.h>

using namespace std;


void countUniques(const int &n, const int &Ncase){
    unordered_map<int,int> freqStamps, ownerStamps;
    vector<int> uniqueCount(n+1, 0);
    set<int> distType[n+1];

    for (int i = 0; i < n; i++){//n = cantity of friends
        int m; cin >> m;// m = cantity of stamps

        while(m--){
            int stamp; cin >> stamp;

            if(distType[i+1].find(stamp) != distType[i+1].end()) continue;

            distType[i+1].insert(stamp);

            if (freqStamps.find(stamp) == freqStamps.end()) freqStamps[stamp] = 1;
            else freqStamps[stamp]++;

            ownerStamps[stamp] = i+1;
        }
    }

    int totalUnique = 0;

    for (auto stamp: freqStamps){
        if (stamp.second == 1){
            int owner = ownerStamps[stamp.first];

            uniqueCount[owner]++; 
            totalUnique++;
        }
    }

    cout << "Case " << Ncase << ":";

    for (int i = 1; i <= n; i++){
        double p;
        if(totalUnique == 0) p = 0.00;
        else p = (uniqueCount[i] * 100.00)/ totalUnique;

        cout << " " << fixed << p << "%";
    }

    cout << endl;
    return;
}

int main(){
    int T; cin >> T;

    for (int i  = 0; i < T; i++){
        int n; cin >> n; 
        countUniques(n, i+1);
    }

    return 0;
}