/*	2021-02-23	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tup;
const int INF = (int)(1e9) + 10;
vector<tup> seg;
int n;

struct fenwicktree{
	vector<int> bit;
	int size;
	fenwicktree(int sz){
		(this->size) = sz;
		bit.assign(sz + 1,0);
	}
	
	void add(int id,int val = 1){
		for (; id <= (this->size); id += (id & -id)) bit[id] += val;
	}
	
	void update(int id,int val = 0){
		if (id < 1) return;
		int old_val = this->get(id) - this->get(id - 1);
		this->add(id,val - old_val);
	}
	
	int get(int id){
		int sum = 0;
		for (; id > 0; id -= (id & -id)) sum += bit[id];
		return sum; 
	}
	
	int get_range(int l,int r){
		return this->get(r) - this->get(l - 1);
	}
	
	void reset(){
		bit.assign(this->size + 1,0);
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	seg.resize(n);
	vector<int> zip;
	
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		seg[i] = make_tuple(l,-r,i);
		zip.push_back(l);
		zip.push_back(r);
	}
	
	sort(all(seg));
	sort(all(zip));
	
	uni(zip);
	
	
	fenwicktree BIT((int)zip.size() + 1);
	int maxrange = (int)zip.size();

	
	vector<int> ans2(n);
	for (int i = 0; i < n; i++){
		int l, r, id;
		tie(l,r,id) = seg[i];
		r = -r;
		
		int n_l = upper_bound(all(zip),l) - zip.begin();
		int n_r = upper_bound(all(zip),r) - zip.begin();
		//cout << n_l << ' ' << n_r << ' ' << id << '\n';
	
		//if (d.find(l) != d.end()) d.erase(l);
		BIT.update(n_l);

		//if (d.lower_bound(r) != d.end()) ans2[id] = 1;
		ans2[id] = BIT.get_range(n_r,maxrange);
		//d[r] = 1;
		BIT.add(n_r);
	}
	
	BIT.reset();
	vector<int> ans1(n);
	for (int i = n - 1; i >= 0; i--){
		int l, r, id;
		tie(l,r,id) = seg[i];
		r = -r;
		int n_l = upper_bound(all(zip),l) - zip.begin();
		int n_r = lower_bound(all(zip),r) - zip.begin();
		
		//cout << l << ' ' << r << ' ' << id << '\n';

		//if (d.lower_bound(-r) != d.end()) ans1[id] = 1;
		ans1[id] = BIT.get(n_r);
		BIT.add(n_r);
	}
	
	
	for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
	cout << '\n'; 
	for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
	return 0;
}