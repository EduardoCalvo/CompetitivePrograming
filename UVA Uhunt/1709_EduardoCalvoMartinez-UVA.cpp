//Eduardo Calvo
#include <bits/stdc++.h>

using namespace std;

long double price(int p, int a, int b, int c, int d, int k){
    long double A = sin(a*k + b);
    long double B = cos(c*k + d) + 2;

    return p*(A+B);
}

long double maxDecline(const vector<long double> &prices){
    long double max = prices[0];
    long double dec = 0;

    for (int i = 0; i < prices.size(); i++){
        if (max < prices[i]) max = prices[i];

        long double piv = max - prices[i];
        if (piv > dec) dec = piv; 
        //cout << "Valor de piv: "<< piv << endl;
    }

    return dec;
}

int main(){
    int p, a, b, c, d, n;

    while (cin >> p){
        cin >> a >> b >> c >> d >> n;

        vector<long double> prices;

        for(int i = 0; i < n; i++) prices.push_back(price(p, a, b, c ,d, i+1));

        long double answer = maxDecline(prices);

        if (answer != 0) printf("%Lf\n",answer);
        else cout << "0.00" <<endl;
    }
    
    return 0;
}