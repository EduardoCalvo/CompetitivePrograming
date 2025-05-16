#include <bits/stdc++.h>

using namespace std;

void simulBattle(vector<vector<int>> &kingdom, const int &k){
    int f = kingdom.size(), c = kingdom[0].size();
    vector<vector<int>> afterBattle(f, vector<int>(c, 0));

    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            int heir = kingdom[i][j];
            int hater = (k + heir - 1)%k;

            if(j-1 >= 0 && kingdom[i][j-1] == hater) afterBattle[i][j] = hater;
            else if (j+1 < c && kingdom[i][j+1] == hater) afterBattle[i][j] = hater;
            else if (i-1 >= 0 && kingdom[i-1][j] == hater) afterBattle[i][j] = hater;
            else if (i+1 < f && kingdom[i+1][j] == hater) afterBattle[i][j] = hater;
            else afterBattle[i][j] = kingdom[i][j];
        }
    }

    kingdom = afterBattle;
    return;
}
/* 
3 4 4 3 
0 1 2 0 
1 0 2 0 
0 1 2 0 
0 1 2 2 
4 2 3 4 
1 0 3  
2 1 2 
8 4 2 1 
0 7
1 6
2 5
3 4 
0 0 0 0
 */
int main(){
    int N, R, C ,K;
    cin >> N >> R >> C >> K;

    while (N || (R || (C || K))){
        vector<vector<int>> kingdom (R, vector<int>(C, 0));

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> kingdom[i][j];
            }
        }

        for(int i = 0; i < K; i++){
            simulBattle(kingdom, N);
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if (j != C-1) cout << kingdom[i][j] << " ";
                else cout << kingdom[i][j];
            }
            cout << endl;
        }

        cin >> N >> R >> C >> K;
    }

    return 0;
}