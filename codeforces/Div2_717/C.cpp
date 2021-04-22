/*	2021-04-22	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int MaxW = 200000 + 5;
int n;
bitset<MaxW> dp;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	int sumW = 0;
	for (int &x: a) {
		cin >> x;
		sumW += x;
	}
	 
	
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = MaxW - 1; j >= a[i]; j--)
			if (dp[j - a[i]]) dp[j] = 1;
	
	if ((sumW % 2 == 1) || (dp[sumW / 2] == 0)) cout << 0;
	else {
		for (int i = 0; i < 15; i++)
			for (int j = 0; j < n; j++)
				if ((a[j] >> i) & 1){
					cout << 1 << '\n' << j + 1;
					return 0;
				}
	}
	
	return 0;
}