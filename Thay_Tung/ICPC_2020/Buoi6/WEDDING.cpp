#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;

struct CountBit{
	vector<int> bit;
	vector<int> a;
	vector<int> firstxor;
	int number;
	int curxor;
	
	CountBit(){
		number = 0;
		curxor = 0;
		bit.resize(32);
	}
	
	void add(int x){
		a.emplace_back(x);
		firstxor.emplace_back(curxor);
		number++;
		for (int i = 0; i < 32; i++)
			if ((x >> i) & 1) bit[i]++;
		
	}
	void xor_all(int x){
		for (int i =0 ; i < 32; i++)
			if ((x >> i) & 1) bit[i] = number - bit[i];
		curxor ^= x; 
	}
	
	void sub(int pos){
		int need_sub = a[pos]^curxor^firstxor[pos];
		for (int i = 0; i < 32; i++)
			if ((need_sub >> i) & 1) bit[i]--;
		a[pos] = 0;
		number--;
	}
	ll get_ans(){
		ll ans = 0;
		for (int i = 0; i < 32; i++)
			ans += (ll)bit[i]*(ll)(1 << i);
		return ans;
	}
	
	
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	CountBit solver;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		solver.add(x);
	}
	while (q--){
		int c, v;
		cin >> c >> v;
		if (c == 1){
			solver.add(v);
			cout << solver.get_ans() << '\n';
		}
		else if (c == 2){
			v--;
			solver.sub(v);
			cout << solver.get_ans() << '\n';
		}
		else {
			solver.xor_all(v);
			cout << solver.get_ans() << '\n';
		}
	}
	return 0;
}
