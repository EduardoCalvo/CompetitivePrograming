#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string,int> totalScore; // Le asignamos una clave a cada participante
    set<pair<int,int>> finalScores; //
    unordered_map <string, vector<int>> solved;// Para los problemas que han resuelto el score
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string part; char problem; int score;
        cin >> part >> problem >> score;

        if(solved.find(part) == solved.end()){
            int probNum = int(problem) - int('A');

            solved[part] = vector<int>(8, 0);
            solved[part][probNum] = score;
            totalScore[part] = score;
        } else {
            int probNum = int(problem) - int('A');

            if(solved[part][probNum] < score) {
                totalScore[part] -= solved[part][probNum];
                totalScore[part] += score;
                solved[part][probNum] = score;
            }
        }
    }

    set<pair<int, string>> finalTable;

    for(auto par : totalScore) {
        finalTable.insert({100 - par.second, par.first});
    }

    int count = 0;

    for(auto par : finalTable ) {
        if(count == 4) break;
        cout << par.second << endl;
        count++;
    }

    return 0;
}

