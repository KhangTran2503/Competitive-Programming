#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int n;
vector<vector<int>> STable;
vector<int> a;

void Build(){
	STable.assign(n,vector<int> (20,INF));
	
	for (int i = 0; i < n; i++) STable[i][0] = a[i];
	for (int k = 1; k < 20; k++){
		int shift = (1 << k);
		for (int i = 0; i + shift <= n; i++)
			STable[i][k] = min(STable[i][k - 1],STable[i + (shift >> 1)][k - 1]);
	}		
}

int get(int u,int v){
	int len = log2(v - u + 1);
	return min(STable[u][len],STable[v - (1 << len) + 1][len]);
}


void solve(){
	cin >> n;
	a.assign(n,0);
	for (int i = 0; i < n; ++i) cin >> a[i];
	Build();
	vector<int> prefix(n), suffix(n);
	prefix[0] = a[0];
	for (int i = 1; i < n; i++) prefix[i] = max(prefix[i - 1],a[i]);
	suffix[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) suffix[i] = max(a[i],suffix[i + 1]);
	
	for (int i = 0; i < n - 2; i++){
		int lef = i + 1;
		int rig = n - 2;
		while (lef <= rig){
			int mid = (lef + rig) >> 1;
			int middle  = get(i + 1,mid);
			if (middle > prefix[i]) lef = mid + 1;
			else if (middle < prefix[i]) rig = mid - 1;
			else {
				if (suffix[mid + 1] > prefix[i]) lef = mid + 1;
				else if (suffix[mid + 1] < prefix[i]) rig = mid - 1;
				else {
					cout << "YES\n";
					cout << i + 1 << ' ' << mid - i << ' ' << n - mid - 1 << '\n';
					return;
				}
			}
		}
	}
	
	cout << "NO\n";
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	
	return 0;
}