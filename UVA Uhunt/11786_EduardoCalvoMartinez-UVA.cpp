#include <bits/stdc++.h>

using namespace std;

int waterUnits(){
    string s; cin >> s;

    stack<int> downs;
    int waterUnits = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == char(92)) 
            downs.push(i);
        else if (s[i] == '/' && !downs.empty()){
            int j = downs.top(); downs.pop();
            waterUnits += i - j;
        }
    }

    return waterUnits;
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++) cout << waterUnits() << endl;

    return 0;
}