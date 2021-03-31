/*	2020-12-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int H, W;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> H >> W;
	int Mina = INF;
	vector<vector<int>> a(H,vector<int>(W,0));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++){
			cin >> a[i][j];
			Mina = min(Mina,a[i][j]);
		}
	
	int ans =0 ;
	for (int i =0; i < H; i++)
		for (int j = 0; j < W; j++) ans += (a[i][j] - Mina);
	
	cout << ans;
	return 0;
}