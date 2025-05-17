#include <bits/stdc++.h>

using namespace std;

int movements(const vector<int> &numbers){
    int maxVal = max_element(numbers.begin(), numbers.end()) - numbers.begin();
    int movements = 0;

    for(int i = 0; i < numbers.size(); i++){
        if (maxVal == i) continue;
        movements += 2*numbers[i] - 1;
    }

    return movements;
}

int main(){
    int t; cin >> t;
    
    while(t--){
        int lenght, k; cin >> lenght >> k;
        vector<int> pieces(k);

        for(int i = 0; i < k; i++) cin >> pieces[i];

        cout << movements(pieces) << endl;
    }

    return 0;
}