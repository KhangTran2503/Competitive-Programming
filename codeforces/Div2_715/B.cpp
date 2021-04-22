/*	2021-04-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int T;

void solve(){
	string s;
	int n;
	cin >> n;
	cin >> s;
	vector<bool> pre(n);
	vector<bool> suff(n);
	int numT = 0;
	int numM = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'T') numT++;
		if (s[i] == 'M'){
			numM++;
			pre[i] = (numM <= numT);
		}
	}
	
	numT = 0;
	numM = 0;
	for (int i = n - 1; i >= 0; i--){
		if (s[i] == 'T') numT++;
		if (s[i] == 'M'){
			numM++;
			suff[i] = (numT >= numM);
		}
	}
	
	if (2*numM != numT){
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n; i++)
		if (s[i] == 'M'){
			if ((!pre[i]) || (!suff[i])) {
				cout << "NO\n";
				return;
			}
		}
	cout << "YES\n";
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	while (T--) solve();
	return 0;
}