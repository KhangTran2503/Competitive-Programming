#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Test;
	cin >> Test;
	while (Test--){
		int n;
		cin >> n;
		int t = 0;
		while (n){
			t *= 10;
			t += (n % 10);
			n /= 10;
		}
		cout << t << '\n';
	}
	return 0;
}
