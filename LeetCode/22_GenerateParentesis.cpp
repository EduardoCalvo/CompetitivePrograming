#include <bits/stdc++.h>

using namespace std;

class Solution {
    private: 
    string parenthesis = "()";
    int opnCount, clsCount;
    int n;

    bool valid(const char &paren){
        if (paren == '('){
            if(opnCount >= clsCount && opnCount < n){
                opnCount++;
                return true;
            }
        } else {
            if(opnCount > clsCount){
                clsCount++;
                return true;
            }
        }

        return false;
    }

    void backTrack(string &comb, vector<string> &ans){
        for (char paren:parenthesis){
            if(valid(paren)){
                comb += paren;
                
                if (comb.size() == 2*n) ans.push_back(comb);
                else backTrack(comb, ans);

                if(paren == '(') opnCount--;
                else clsCount--;

                comb.pop_back();
            }
        }

        return;
    }

    public:

    vector<string> generateParenthesis(const int &n){
        opnCount = 0;
        clsCount = 0;
        this-> n = n;
        vector<string> ans;
        string comb = "";

        backTrack(comb, ans);

        return ans;
    }

};

int main(){
    int n; cin >> n;

    Solution pivot;

    vector<string> ans = pivot.generateParenthesis(n);

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}