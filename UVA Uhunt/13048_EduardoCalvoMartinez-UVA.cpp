#include <bits/stdc++.h>

using namespace std;

bool directlyCond(const string &s, const int &idx){
    return !(s[idx] == 'B' || (s[idx] == 'D' || s[idx] == 'S'));
}

bool beforeBusCond(const string &s, const int &idx){
    bool ans = true;
    if (s[idx + 1] == 'B' && idx + 1 < s.size()) ans = false;
    if (s[idx + 2] == 'B' && idx + 2 < s.size()) ans = false;
    return ans;
}

bool sideStrCond(const string &s, const int &idx){
    bool ans = true;
    if (s[idx + 1] == 'S' && idx + 1 < s.size()) ans = false;
    if (s[idx - 1] == 'S' && idx - 1 >= 0) ans = false;
    return ans;
}

int possibleSpaces(const string &s){
    int count = 0;

    for (int i = 0; i < s.size(); i++){
        if (!directlyCond(s, i)) continue;
        if (!beforeBusCond(s, i)) continue;
        if (!sideStrCond(s, i)) continue;

        count++;
    }

    return count;
}

int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        string street; cin >> street;
        int ans = possibleSpaces(street);

        cout << "Case " << i+1 << ": " << ans << endl;
    }

    return 0;
}