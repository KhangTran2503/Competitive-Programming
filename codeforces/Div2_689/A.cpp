/*	2020-12-15	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
char a[3] = {'a','b','c'};
int t;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		int r = (n % k);
		int cur = 0;
		for (int i = 0; i < (n/k); i++){
			for (int j = 0; j < k; j++) cout << a[cur];
			cur = (cur + 1) % 3;
		}
		for (int i = 0; i < r; i++) cout << a[cur];
		cout << '\n';
	}
	return 0;
}