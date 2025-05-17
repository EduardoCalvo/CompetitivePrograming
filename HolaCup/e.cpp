#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    while(n){
        vector<int> B(n), A;

        for(int i = 0; i < n; i++) cin >> B[i];

        int actXor = 0;

        for(int i = 0; i < n; i++){
            int pivot = actXor^B[i];    
            A.push_back(pivot);
            actXor = actXor^pivot;
        }
        
        for(int i = 0; i < n; i++) cout << A[i] << " ";
        cout << endl;
        
        cin >> n;
    }

    return 0;
}