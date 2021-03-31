#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
typedef vector<int> vi;
map<int,vi> Hash;
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	int l = -1, r = -1;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		Hash[a].eb(i + 1);
		for (int id: Hash[x - a])
			if (id != i + 1){
				cout << min(id,i + 1) << ' ' << max(id,i + 1);
				return 0;
			}
			
	}

	cout << "IMPOSSIBLE";
	return 0;
}
