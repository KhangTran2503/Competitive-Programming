/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
vector<ii> p;
int H, W, n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	p.resize(n);
	for (ii &x: p) cin >> x.first >> x.second;
	p.emplace_back(H,W);
	
	return 0;
}