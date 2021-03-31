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

bool check(int x,int base){
	while (x){
		if (x % base == 7) return false;
		x /= base;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++)
		if (check(i,10) && check(i,8)) ans++;
	cout << ans;
	return 0;
}