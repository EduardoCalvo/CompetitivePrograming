#include <bits/stdc++.h>

using namespace std;

int maxEmptySpace(const string &s){
    int counter = 0, max = 0; 
    bool firstX = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.') {
            counter++;
            if(i == s.size()-1 &&  counter-1 > max) max = counter - 1; 
        }

        if(s[i] == 'X'){
            if (firstX) {
                if (counter  - 1 > max) max = counter - 1; 
                firstX = false;
            }

            if(counter % 2 == 0){
                if((counter/2) - 1 > max) max = (counter/2) - 1;
                counter = 0; 
            } else { 
                if(counter/2 > max) max = counter/2;
                counter = 0;
            }
        }
    }

    return max;
}

int main(){
    string s;

    while(cin >> s){
        int max = maxEmptySpace(s);
        cout << max << endl;
    }

    return 0;
}
