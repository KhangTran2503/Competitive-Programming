/*	2021-02-23	*/
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


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	map<int,int> d;
	for (int i = 1; i <= 10; i++) d[i] = 1;
	
	if (d.find(1) == d.begin()) cout << "YES\n";
	d.erase(1);
	if (d.find(2) == d.begin()) cout << "YES\n";
	
	return 0;
}