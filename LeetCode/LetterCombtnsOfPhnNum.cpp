#include <bits/stdc++.h>

using namespace std;

class solution {
    private:
    unordered_map<char, string> digToStr;
    string digits;

    public:

    solution(const string &digits){
        this-> digits = digits;
        this-> digToStr = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, 
        {'9', "wxyz"}};

        return;
    }

    void backTrack(const int &idx, vector<string> &ans, string &phrase){
        string letters = digToStr[digits[idx]];
        for(char letter: letters){
            phrase += letter;
            if(idx == digits.size()-1) ans.push_back(phrase);
            else backTrack(idx+1, ans, phrase);
            phrase.pop_back();
        }

        return;
    }
};

int main(){
    string digits, phrase = ""; cin >> digits;
    vector<string> ans;

    solution toSolve (digits);

    toSolve.backTrack(0, ans, phrase);

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}