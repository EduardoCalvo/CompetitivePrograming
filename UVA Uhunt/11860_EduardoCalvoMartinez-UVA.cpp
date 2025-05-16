#include <bits/stdc++.h>

using namespace std;

vector<string> getCorrectDocument(unordered_map<string, int> &words){
    string line;
    vector<string> listofWords;
    
    while(getline(cin, line) && line != "END"){
        string piv = "";

        for(int i = 0; i < line.size(); i++){
            
            if (int(line[i]) <= int('z') && int(line[i]) >= int('a')) 
                piv.push_back(line[i]);
            else if (piv.size() > 0){
                listofWords.push_back(piv);
                words[piv] = 0;
                piv = "";
            }

            if(piv.size() > 0 && i == line.size()-1){
                listofWords.push_back(piv);
                words[piv] = 0;
                piv = "";
            }
        }
    }

    return listofWords;
}   

pair<int,int> getInterval(unordered_map<string, int> &words, const vector<string> &text){
    int left = 0, right = 0, uniqueElemts = 0, totalW = words.size();
    int smallDif = INT_MAX;
    pair <int,int> ans;

    while(right < text.size()){
        words[text[right]]++;
        if (words[text[right]] == 1) uniqueElemts++;
        
        while (uniqueElemts >= totalW) {
            if(right - left < smallDif){
                smallDif = right - left;
                ans = make_pair(left, right);
            }

            words[text[left]]--;
            if(words[text[left]] == 0) uniqueElemts--;
            left++;
        }

        right++;
    }

    return ans;
}

int main(){
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        vector<string> text;
        unordered_map<string,int> words;

        text = getCorrectDocument(words);
        pair<int,int> ans = getInterval(words, text);

        cout << "Document " << i+1 << ": " << ans.first+1 << " " << ans.second+1 << endl;
    }

    return 0;
}