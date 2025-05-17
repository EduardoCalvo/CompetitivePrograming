//Eduardo Calvo Martinez
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;

    if (N < 0 || N > 99999) cout << 0 << endl;
    else {
        int sum = 0;
        while(N){
            sum += N % 10;
            N /= 10;
        }

        cout << sum;
    }

    return 0;
}