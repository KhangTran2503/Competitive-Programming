/*	2021-05-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
ll n, p;
int Q;
ll C[2005][2005];



void init(){
	for (int i = 0; i <= 2000; i++) C[0][i] = 1;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= i; j++)
			C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % p;
}

ll calc(ll x){
	return C[x][x + x - 1];
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> Q >> p;
	init();
	
	while (Q--){
		cin >> n;
		cout << calc(n) << '\n';
	}
	return 0;
}