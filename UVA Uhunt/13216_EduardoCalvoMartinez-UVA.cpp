#include <bits/stdc++.h>

using namespace std;

long long int answer(string n){
    long long int answer = 1;
    int no = n[n.size()-1] - '0';

    if(no == 0 && n.size() == 1) return 1;
    if(no == 1 && n.size() == 1) return 66;
    else {
        if(no == 0) no = 5;
        if(no == 1) no = 6;

        answer = (66*66)%100;
        for(int i = 0; i < ((no-2) + 5)%5; i++){
            answer = (answer * 66)%100;
        }

        return answer;
    }
}

int main(){
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        string n; cin >> n;
        cout << answer(n) << endl;
    }

    return 0;
}