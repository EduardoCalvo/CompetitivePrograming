#include <bits/stdc++.h>

using namespace std;

void updtLastBlood(vector<vector <int>> &problems){
    int t, id; char problem; string veredict;
    cin >> t >> id >> problem >> veredict; 

    int row = problem - 'A';
    if(veredict == "Yes"){
        if (t >= problems[row][0] && problems[row][1+id] == -1){
            problems[row][0] = t;
            problems[row][1] = id;
            problems[row][1+id] = 1;
        }
    }

    return;
}

int main(){
    int n, t, m; cin >> n >> t >> m;

    vector<vector<int>> problems (n, vector<int>(2+t, -1));

    for(int i = 0; i < m; i++){
        updtLastBlood(problems);
    }

    for(int i = 0; i < problems.size(); i++){
        if (problems[i][0] != -1) 
            cout << char(65 + i) << " " << problems[i][0]<< " " << problems[i][1] << endl;
        else 
            cout << char(65 + i) << " - -" << endl;
    }

    return 0;
}