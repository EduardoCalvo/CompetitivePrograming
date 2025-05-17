#include <bits/stdc++.h>

using namespace std;

class Solution{
    private:
    vector<bool> added;

    void backTrack(vector<int> &permutation, vector<vector<int>> &ans, const vector<int> &nums){
        for(int i = 0; i < nums.size(); i++){
            if (added[i]) continue;
            permutation.push_back(nums[i]);
            added[i] = true;

            if (permutation.size() == nums.size()) ans.push_back(permutation);
            else backTrack(permutation, ans, nums);

            permutation.pop_back();
            added[i] = false;
        }
    }

    public:
    vector<vector<int>> permute(const vector<int> &nums){
        this-> added = vector<bool>(nums.size(), false);
        vector<int> permutation;
        vector<vector<int>> ans;

        backTrack(permutation, ans, nums);

        return ans;
    }
};

int main(){
    
}