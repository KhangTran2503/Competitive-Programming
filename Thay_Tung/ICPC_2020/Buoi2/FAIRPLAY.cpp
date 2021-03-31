#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;

pair<bool,ll> check(ll x){
	if (x == 1) return {true,0};
	for (ll i = 2; i*i <= x; i++)
		if (x % i == 0){
			return {false,i};
		}
	return {true,0};
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	
	pair<bool,ll> c = check(k);
	if (c.first) {
		cout << "1\n0";
	}
	else{
		ll a = c.second;
		ll b = k/a;
		pair<bool,ll> cb = check(b);
		if (cb.first){
			cout << "2\n0"; 
		}
		else {
			cout << 1 << '\n' << a*cb.second;
		}
	}
	return 0;
}
