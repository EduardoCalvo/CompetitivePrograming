#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
    int target;
    int sum;
    vector<int> candidates;

    bool valid(const int &n){
        if(sum + n <= target) return true;

        return false;
    }

    void backTrack(vector<int> &combination, set<vector<int>> &ans){
        //No es necesario correr por todos los elementos cada iteracion. Basta con correr desde donde nos quedamos hasta el ultimo.
        // Si no se empiezan a repetir casos
        for(int candidate:candidates){
            if(!valid(candidate)) break;
            sum += candidate;
            combination.push_back(candidate);

            if(sum == target) {
                vector<int> piv = combination;
                sort(piv.begin(), piv.end());
                ans.insert(piv);
            }
            else backTrack(combination, ans);

            sum -= candidate;
            combination.pop_back();
        }

        return;
    }

    public:
    vector<vector<int>> combinationSum (vector<int> &candidates, const int &target){
        this-> candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        this-> target = target;
        this-> sum = 0;
        set<vector<int>> ans;
        vector<vector<int>> trueAns;
        vector<int> combination;

        backTrack(combination, ans);

        for(auto elem:ans) trueAns.push_back(elem);

        return trueAns;
    }
};

int main(){
    int n, target; cin >> n;
    vector<int> candidates(n);

    for(int i = 0; i < n; i++) cin >> candidates[i];
    cin >> target;

    Solution answer;
    vector<vector<int>> ans = answer.combinationSum(candidates, target);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}