#include <bits/stdc++.h>
using namespace std;

int A[131072], B[131072], C[131072];

int main() {
	int testcase, n, m; cin >> testcase;
    
	while (testcase--) {
        int n, m; cin >> n >> m;

		for (int i = 0; i < n; i++){cin >> A[i]; C[i] = A[i];}

		for (int i = 0; i < m; i++){cin >> B[i]; C[i+n] = B[i];}
        
		C[n+m] = 0;

		sort(A, A+n); sort(B, B+m); sort(C, C+n+m+1);
		
		int price = 0, angry = INT_MAX;
		int idx = 0, jdx = 0;

		for (int i = 0; i <= n+m; i++) {
			int test = C[i];

			while (jdx < m && B[jdx] < test) jdx++;
			while ( idx < n && A[idx] <= test) idx++;

			int v = n - idx + jdx;

			if (v < angry) {angry = v; price = test;}
		}
        
        cout << price << " " << angry << endl;
	}
	return 0;
}