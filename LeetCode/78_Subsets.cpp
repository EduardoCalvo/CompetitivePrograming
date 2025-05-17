    #include <bits/stdc++.h>

    using namespace std;

    class Solution {
        private:
        void backTrack(vector<int> &subset, vector<vector<int>> &ans, const vector<int> &nums, const int &idx){
            ans.push_back(subset);

            for(int i = idx; i < nums.size(); i++){
                subset.push_back(nums[i]);
                backTrack(subset, ans, nums, i+1);

                subset.pop_back();
            }

            return;
        }

        public:
        vector<vector<int>> subsets(const vector<int> &nums){
            vector<vector<int>> ans;
            vector<int> subset;

            backTrack(subset, ans, nums, 0);

            return ans;
        }
    };


int main(){
    
}