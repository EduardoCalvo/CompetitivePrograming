#include <bits/stdc++.h>
using namespace std;

void WeighingMachine(int c){
    vector<int> weights(10); int totalSum = 0;
    for(int i = 0; i < 10; i++){
        cin >> weights[i]; totalSum += weights[i];
    }
    
    vector<int> p(5), current;

    for(p[0] = 1; p[0] <= weights[0]/2; p[0]++){
        p[1] = weights[0] - p[0];
        
        for(p[3] = p[1]; p[3] <= weights[9]/2; p[3]++){
            p[4] = weights[9] - p[3];
            p[2] = totalSum/4 - p[0] - p[1]- p[3] - p[4];

            if(!current.empty()) current.clear();
            
            for(int i = 0; i < 4; i++)
                for(int j = i + 1; j < 5; j++)
                    current.push_back(p[i] + p[j]);
                    
                    
            sort(current.begin(), current.end());
            
            if(current == weights){
                cout << "Case " << c << ":";
                for(auto value : p)
                    cout << " " << value;
                cout << endl;
                return;
            }
        }
    }    
}

int main(){
    int t; cin >> t;
    for( int k=1; k<=t; k++) WeighingMachine(k);

	return 0;
}