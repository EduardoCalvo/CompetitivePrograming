//Eduardo Calvo Martinez
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; 

    while(cin >> s){
        int countIn = 0, countOut = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+') countIn++;
            else countOut++;
        }

        int lower = min(countIn, countOut);
        int ans = s.size() - 2*lower;

        cout << ans << endl;
    }
    

    return 0;
}