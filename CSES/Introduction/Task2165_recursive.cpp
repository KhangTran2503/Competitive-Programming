/*	2021-01-30	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;
vector<ii> ans;

void tower_ha_noi(int disk,int from_rod,int to_rod,int mid_rod){
	if (disk == 1){
		ans.push_back(make_pair(from_rod,to_rod));
		return;
	}
	tower_ha_noi(disk - 1,from_rod,mid_rod,to_rod);
	ans.push_back(make_pair(from_rod,to_rod));
	tower_ha_noi(disk - 1,mid_rod,to_rod,from_rod);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	tower_ha_noi(n,1,3,2);
	cout << (int)ans.size() << '\n';
	for (ii &x: ans) cout << x.first << ' ' << x.second << '\n';
	return 0;
}