#include <bits/stdc++.h>

using namespace std;


int recon(int i, const vector<string> &matrx){
    string firstRow;
    for(int j = i; j < i+3; j++) firstRow.push_back(matrx[0][j]);

    if (firstRow == ".*.") return 1;
    else if (firstRow == "***"){
        string forthRow;
        for(int j = i; j < i+3; j++) forthRow.push_back((matrx[3])[j]);
        
        if(forthRow == "*..") return 2; 
        else if(forthRow == "..*") return 3;
    }

    return 0;
}


int main(){
    vector<string> matrx;
    vector<int> ans;
    int n; cin >> n;

    for(int i = 0; i < 5; i++){
        string piv; cin >> piv;
        matrx.push_back(piv);
    }

    for(int i = 0; i < 4*n; i+=4){
        int res = recon(i, matrx);
        ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i];

    cout << endl;
    return 0;
}