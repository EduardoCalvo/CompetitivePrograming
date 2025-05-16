#include <bits/stdc++.h>

using namespace std;
vector<string> students;

void studentRef(const int &r){
    int i = r, countRight = 0, countleft = 0;

    if(students[r-1] != "?") {
        cout << students[r-1] << endl;
        return;
    }

    while (students[i] == "?" && i < students.size()){
        countRight++;
        i++;
    }

    i = r-2;

    while (students[i] == "?" && i >= 0){
        countleft++;
        i--;
    }/* 

    cout << countleft << " " << countRight << endl; */

    if (countleft == countRight && (r-2-countleft >= 0 && r + countRight <= students.size()-1)){
        cout << "middle of " << students[r-2-countleft] << " and " << students[r+countRight];
        cout << endl;
        return;
    } 
    if (countleft < countRight && r-2-countleft >= 0){
        for (int j = 0; j <= countleft; j++) cout << "right of ";
        cout << students[r-2-countleft] << endl;
        return;
    } 
    if  (countleft > countRight && r + countRight <= students.size()-1) {
        for (int j = 0; j <= countRight; j++) cout << "left of ";
        cout << students[r+countRight] << endl;
        return;
    }
    if (r + countRight >= students.size()){
        for (int j = 0; j <= countleft; j++) cout << "right of ";
        cout << students[r-2-countleft] << endl; return;
    }
    if (r-2-countleft < 0){
        for (int j = 0; j <= countRight; j++) cout << "left of ";
        cout << students[r+countRight] << endl;
        return;
    }

    return;
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string piv; cin >> piv;
        students.push_back(piv);
    }

    int q; cin >> q;
    while(q){
        int r; cin >> r;
        studentRef(r);
        q--;
    }

    return 0;
}