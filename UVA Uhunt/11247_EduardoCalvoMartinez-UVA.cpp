#include <bits/stdc++.h>
using namespace std;

int main(){
    long long m, v, x;
    cin >> m >> x;
    
    while(m != 0 || x != 0){
        if(x != 100) v = (long long)(m-1)*100/(100-x);
        else v = 0;

        if(v*(100-x)/100 == m-1) v--;

        if(v < m )  cout << "Not found" << endl;
        else cout << v << endl;
        
        cin >> m >> x;
    }

    return 0;
}