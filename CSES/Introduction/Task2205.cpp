/*	2021-01-28	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

int gray_code(int n){
	return n^(n >> 1);
}
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int msk = 0; msk < (1 << n); msk++){
		int g = gray_code(msk);
		for (int i = 0; i < n; i++) cout << ((g >> i) & 1);
		cout << '\n';
	}
	return 0;
}