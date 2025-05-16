#include <bits/stdc++.h>

using namespace std;

void checkRequests(){
    set<int> alreadyLock;
    set<int> deniedTrans;
    unordered_map<int, set<int>> xReq;
    unordered_map<int, set<int>> sReq;

    char req; int traid, item;
    
    cin >> req;
    while(req != '#'){
        cin >> traid >> item;

        if (deniedTrans.find(traid) != deniedTrans.end()){
                cout << "IGNORED" << endl;
        } else if(alreadyLock.find(item) == alreadyLock.end()){
            alreadyLock.insert(item);
            if(req == 'S') sReq[item].insert(traid);
            else xReq[item].insert(traid);

            cout << "GRANTED" << endl;
        } else {
            if(req == 'S'){
                int isIn = xReq[item].find(traid) != xReq[item].end();
                
                if(xReq[item].size() - isIn >= 1) {
                    deniedTrans.insert(traid);
                    cout << "DENIED" << endl;
                } else {
                    sReq[item].insert(traid);
                    cout << "GRANTED" << endl;
                }
            } else {
                int isInS = sReq[item].find(traid) != sReq[item].end();
                int isInX = xReq[item].find(traid) != xReq[item].end();
                
                if(sReq[item].size() - isInS >= 1) {
                    deniedTrans.insert(traid);
                    cout << "DENIED" << endl;
                } else if(xReq[item].size() - isInX >= 1) {
                    deniedTrans.insert(traid);
                    cout << "DENIED" << endl;
                } else {
                    xReq[item].insert(traid);
                    cout << "GRANTED" << endl;
                }
            }
        }
        
        cin >> req;
    }
}

int main(){
    int T; cin >> T;

    while(T--){
        checkRequests();
        if(T != 0) cout << endl;
    }

    return 0;
}