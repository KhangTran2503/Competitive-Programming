#include <bits/stdc++.h>
using namespace std;
string a, b;
string ans = "";
vector<vector<int>> nxt_a, nxt_b;
vector<vector<int>> memo;
vector<vector<char>> trace;
int n, m;

int dp(int i,int j){
	if (i == n && j == m) return 0;
	if (memo[i][j] != -1) return memo[i][j];
	
	int tmp0 = dp(nxt_a[i][0],nxt_b[j][0]);
	int tmp1 = dp(nxt_a[i][1],nxt_b[j][1]);
	if (tmp0 <= tmp1) trace[i][j] = '0';
	else trace[i][j] = '1';
	
	return memo[i][j] = min(tmp0,tmp1) + 1;
	
}


void getans(int i,int j){
	if (i == n && j == m) return;
	char cur_char = trace[i][j];
	ans.push_back(cur_char);
	getans(nxt_a[i][cur_char - '0'],nxt_b[j][cur_char - '0']);
}

void build_next(){
	nxt_a.assign(n + 1,vector<int> (2,n));
	nxt_b.assign(m + 1,vector<int> (2,m));
	
	for (int i = n - 2; i >= 0; i--)
		for (int c = 0; c < 2; c++)
			nxt_a[i][c] = (c == a[i + 1] - '0') ? i + 1 : nxt_a[i + 1][c];
	
	for (int i = m - 2; i >= 0; i--)
		for (int c = 0; c < 2; c++)
			nxt_b[i][c] = (c == b[i + 1] - '0') ? i + 1 : nxt_b[i + 1][c];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	cin >> b;
	a = "0" + a;
	b = "0" + b;
	
	n = (int)a.size();
	m = (int)b.size();
	build_next();
	memo.assign(n + 1,vector<int> (m + 1,-1));
	trace.assign(n + 1,vector<char> (m + 1,'0'));
	dp(0,0);
	getans(0,0);
	
	cout << ans;
	return 0;
}
