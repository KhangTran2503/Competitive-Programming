#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, rs;
int n;

struct FenwickTree{
	vector<int> bit;
	int sz;
	FenwickTree(int size){
		sz = size;
		bit.assign(sz + 1,0);
	}
	
	void update(int id,int delta = 1){
		id++;
		for (; id <= sz; id += (id & -id)) bit[id] += delta;
	}
	
	ll get(int id){
		ll sum = 0;
		id++;
		for (; id > 0; id -= (id & -id)) sum += (ll)bit[id];
		return sum;
	}
	
};


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	cin >> s;
	
	rs = s;
	reverse(rs.begin(),rs.end());
	//cout << rs << '\n';
	
	vector<vector<int>> rs_idx(26);
	vector<int> cnt(26,0);
	for (int i = 0; i < n; i++) rs_idx[rs[i] - 'a'].emplace_back(i);
	
	//vector for premutation, swap two adj element
	vector<int> per(n);
	
	for (int i = 0; i < n; i++){
		per[i] = rs_idx[s[i] - 'a'][cnt[s[i] - 'a']];
		cnt[s[i] - 'a']++;
	}
	
	//for (int i = 0; i < n; i++) cout << per[i] << ' ';
	//cout << '\n';
	// calculate in permutation
	FenwickTree fen(n);
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--){
		ans += fen.get(per[i] - 1);
		fen.update(per[i]);
	}
	
	cout << ans;
	return 0;
}
