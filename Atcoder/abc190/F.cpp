/*	2021-07-18	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<int> a;
vector<int> b;
vector<int> tmp;
int n;

// similar mergesort

ll merge(int l,int mid, int r){
	int idl = l;
	int idr = mid + 1;
	
	ll cnt = 0;
	for (int i = l; i <= r; i++){
		if ((idl <= mid) && (idr <= r)){
			if (b[idr] <= b[idl]){
				tmp[i] = b[idr++];
				cnt += (ll)(mid - idl + 1);
			}
			else tmp[i] = b[idl++];
		}
		else if (idl <= mid) tmp[i] = b[idl++];
		else tmp[i] = b[idr++];
	}
	
	for (int i = l; i <= r; i++) b[i] = tmp[i];
	return cnt;
	
}

ll calc_inversion(int l,int r){
	if (l >= r) return 0;
	int mid = (l + r) >> 1;
	ll cnt = 0;
	cnt += calc_inversion(l,mid);
	cnt += calc_inversion(mid + 1,r);
	cnt += merge(l,mid,r);
	return cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	b = a;
	tmp.resize(n);
	ll inv = calc_inversion(0,n - 1);
	// case i = 0;
	cout << inv << '\n';
	for (int i = 1; i < n; i++){
		inv += (n - 1 - a[i - 1] - a[i - 1]);
		cout << inv << '\n';
	}
	return 0;
}
