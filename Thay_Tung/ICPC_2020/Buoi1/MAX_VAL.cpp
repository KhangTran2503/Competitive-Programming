#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(2e18);
vector<int> sign;
vector<ll> a;
vector<ll> pw10(11);
ll ans = -INF;
ll sum = 0;



void change(int i){
	if (i > 0){
		string t = to_string(a[i]);
		ll delta = (ll)sign[i - 1]*a[i - 1]*pw10[(int)t.size()] + a[i];
		delta -= (ll)sign[i - 1]*a[i - 1];
		delta -= (ll)sign[i]*a[i];
		ans = max(ans,sum  + delta);
	}	
    
	string t = to_string(a[i]);
	for (int p = 0; p < (int)t.size(); p++){
		ll n_val = (a[i]/pw10[(int)t.size() - p])*pw10[(int)t.size() - p -1] + a[i] % pw10[(int)t.size() - p - 1];
		ll delta = -(ll)sign[i]*a[i] + (ll)sign[i]*n_val;
		ans = max(ans,sum + delta);  
	}
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x;
	cin >> x;
	a.emplace_back(x);
	sign.emplace_back(1);
	char sgn;
	while (cin >> sgn >> x){
		a.emplace_back(x);
		if (sgn == '+') sign.emplace_back(1);
		else sign.emplace_back(-1);
	}
	
	//ll sum = 0;
	for (int i = 0; i < (int)sign.size(); i++) sum += (ll)sign[i]*(ll)a[i]; 
	
	pw10[0] = 1LL;
	for (int i = 1; i < 11; i++) pw10[i] = pw10[i - 1]*10LL;
	
	
	for (int i = 0; i < (int)sign.size(); i++)
		change(i);	
	 
	cout << ans;
	return 0;
}
