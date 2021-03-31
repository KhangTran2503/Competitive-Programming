/*	2020-12-07	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const int Maxn = int(1e3) + 5;
string s, t,tmp;
int memo[2*Maxn][2*Maxn];
int n, m;

int dp(int i,int j){
	if (i == 0 && j == 0) return 1;
	if (i < 0 || j < 0) return 0;
	int &res = memo[i][j];
	if (res != -1) return res;
	res  = 0;
	//if ((s[i] != '*') && (s[i] != t[j])) return 0;
	if (s[i] == '*'){
		if (i >= 2) res |= dp(i - 2,j);
		if (j >= 1 && (s[i - 1] == t[j])) res |= dp(i,j - 1);
		if ((i >= 2) && (j >= 1) && (s[i - 1] == t[j]))res |= dp(i - 2,j - 1);
	}
	else if (s[i] == t[j]) res |= dp(i - 1,j - 1);
	else res = 0; 
	return res;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> tmp;
	
	for (char x: tmp){
		if (x == '+'){
			char y = s.back();
			s.push_back(y);
			s.push_back('*');
		}
		else s.push_back(x);
	}
	cin >> t;
	n = (int)s.size();
	s = ' ' + s;
	m = (int)t.size();
	t = ' ' + t;
	memset(memo,-1,sizeof(memo));
	cout << (dp(n,m) ? "Yes" : "No") << '\n';
	//cout << s;
	return 0;
}