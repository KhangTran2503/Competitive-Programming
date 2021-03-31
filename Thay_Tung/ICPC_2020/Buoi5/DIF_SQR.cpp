#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll x, y;
	if (n == 1 || n == 2 || n == 4){
		cout << "No";
		return 0;
	}
	if (n & 1) x = (n + 1)/2, y = (n - 1)/2;
	else{
		if (n % 4 != 0){
			cout << "No";
			return 0;
		}
		x = (n/2 + 2)/2;
		y = (n/2 - 2)/2;
	}  
	if (x >= 0 && y >= 0){
		cout << "Yes\n" << x << ' ' << y;
	}
	else cout << "No";
	return 0;
}
