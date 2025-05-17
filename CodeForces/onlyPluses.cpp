#include <bits/stdc++.h>

using namespace std;


long long int mximum(vector<int> &kmesNums){

    for(int i = 0; i < 5; i++){
        auto smaller = min_element(kmesNums.begin(), kmesNums.end());

        (*smaller)++;
    }

    int max = kmesNums[0]*kmesNums[1]*kmesNums[2];
    
    return max;
}

int main(){
    int t; cin >> t;

    while(t--){
        vector<int> kmesNums(3);

        for(int i = 0; i < 3; i++) cin >> kmesNums[i];

        cout << mximum(kmesNums) << endl;
    }

    return 0;
}