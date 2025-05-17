#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        int sumR = 0, sumC = 0;

        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sumR += (n-j) * (n-i);
                if (j == i) sumC += (n-j) * (n-i);
            }
        }

        cout << sumC << " " << sumR << endl;
    }

    return 0;
}