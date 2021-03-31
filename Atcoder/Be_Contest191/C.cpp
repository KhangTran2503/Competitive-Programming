/*	2021-02-17	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H + 1,vector<char> (W,'.'));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) cin >> a[i][j];
		
	int sides = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++){
			int adj = 0;
			if (a[i][j] == '#') adj++;
			if (a[i + 1][j] == '#') adj++;
			if (a[i][j + 1] == '#') adj++;
			if (a[i + 1][j + 1] == '#') adj++;
			if (adj == 1 || adj == 3) sides++;
		}
	
	cout << sides;
	return 0;
}