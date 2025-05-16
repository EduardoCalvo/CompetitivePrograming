#include <bits/stdc++.h>

using namespace std;

void UpToDown(vector<char> &upPile, vector<char> &downPile){
    /* for(int i = upPile.size()-1; i >= 0 ; i--){
        downPile.push_back(upPile[i]);
    } */

    int n = upPile.size();

    for(int i = 0; i < n; i++){
        downPile.push_back(upPile.back());
        upPile.pop_back();
    }/* 
    upPile.resize(0); */
}

void UpToUp(vector<char> &upFrom, vector<char> &upDest){
    /* for(int i = 0; i < upFrom.size(); i++) cout << upFrom[i];
    cout << endl; */

    for(int i = 0; i < upFrom.size(); i++){
        upDest.push_back(upFrom[i]);
    }

    upFrom.resize(0);
}

void snapGame(vector<char> &downJane, vector<char>&downJohn){
    vector<char> upJane, upJohn;

    for(int i = 0; i < 1000; i++){
        char lastJane, lastJohn;

        
       

        if(!downJane.empty()){
            lastJane = downJane.back(); downJane.pop_back();
            upJane.push_back(lastJane);
        }
        else {
            UpToDown(upJane, downJane);
            /* for(int j = 0; j < downJane.size(); j++) cout << downJane[j] ;
            cout << " ";
            for(int j = 0; j < upJane.size(); j++) cout << upJane[j] ;
            cout << endl; */
            lastJane = downJane.back(); downJane.pop_back();
            upJane.push_back(lastJane);
        }
        if(!downJohn.empty()){
            lastJohn = downJohn.back(); downJohn.pop_back();
            upJohn.push_back(lastJohn);
        }
        else {
            UpToDown(upJohn, downJohn);
            /* for(int j = 0; j < downJohn.size(); j++) cout << downJohn[j] ;
            cout << " ";
            for(int j = 0; j < upJohn.size(); j++) cout << upJohn[j] ;
            cout << endl; */
            lastJohn = downJohn.back(); downJohn.pop_back();
            upJohn.push_back(lastJohn);
        }
        
        /* cout << lastJane << " " << lastJohn << endl; */
        if(lastJane == lastJohn){
            bool snap = random()/141 % 2;
            
            if(!snap){
                /* for(int j = upJane.size() - 1; j >= 0; j--) cout << upJane[j];
                cout << endl;
                for(int j = upJohn.size() - 1; j >= 0; j--) cout << upJohn[j];
                cout << endl; */
                UpToUp(upJohn, upJane);
                cout << "Snap! for Jane: ";
                for(int j = upJane.size() - 1; j >= 0; j--) cout << upJane[j];
                cout << endl;
            } else {
                /* for(int j = upJane.size() - 1; j >= 0; j--) cout << upJane[j];
                cout << endl;
                for(int j = upJohn.size() - 1; j >= 0; j--) cout << upJohn[j];
                cout << endl; */
                UpToUp(upJane, upJohn);
                cout << "Snap! for John: ";
                for(int j = upJohn.size() - 1; j >= 0; j--) cout << upJohn[j];
                cout << endl;
            }
        }

        if(downJohn.empty() && upJohn.empty()){
            cout << "Jane wins." << endl;
            return;
        }
        if(downJane.empty() && upJane.empty()){
            cout << "John wins." << endl;
            return;
        }
        /* char c; cin >> c; */
    }

    cout << "Keeps going and going ..." << endl;
    return;
}

/* 1

ABCDA 
CBADC */

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        if (i != 0) cout << endl;
        vector<char> downJane, downJohn;
        string pivot; cin >> pivot;
        /* cout << pivot << endl; */
        for(int i = pivot.size() - 1; i >= 0; i--)downJane.push_back(pivot[i]);

        cin >> pivot;
        /* cout << pivot << endl; */
        for(int i = pivot.size() - 1; i >= 0; i--) downJohn.push_back(pivot[i]);

        /* for(int i = 0; i < downJane.size(); i++) cout << downJane[i];
        cout << endl;
        for(int i = 0; i < downJohn.size(); i++) cout << downJohn[i];
        cout << endl; */
        snapGame(downJane, downJohn);
    }
    return 0;
}
