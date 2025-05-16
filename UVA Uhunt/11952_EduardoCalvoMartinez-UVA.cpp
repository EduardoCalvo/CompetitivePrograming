#include <bits/stdc++.h>
using namespace std;

int returnNumber(char c){ return (int) c-(int) '0';}

void eval(int b, int& len, bool& finish, string a){

	for(int j=0; j<a.size(); j++){

		if(b==1 && returnNumber(a[a.size()-1-j])!=1){ finish=false; return;}
        else if(returnNumber(a[a.size()-1-j])>=b && b>1){ finish=false; return;}
		
		len+=returnNumber(a[a.size()-1-j])*pow(b, j);
	}
}

void arithmetics(){
	string a, b, c; char letter;
	cin >> a >> letter >> b >> letter >> c;
	
	int len1, len2, len3; bool finish;

	for(int i=1; i<=19; i++){
		finish=true; len1=0, len2=0, len3=0;

		eval(i, len1, finish, a);
		eval(i, len2, finish, b);
		eval(i, len3, finish, c);
		
		if(!finish) continue;
		else if(len1+len2==len3){
			cout << i << endl; return;
		}
	}

	cout << 0 << endl;
}

int main(){
	int n; cin >> n;

	while(n--) arithmetics();
	
	return 0;
}