#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int H, W;
vector<vector<char>> S;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> H >> W;
	S.resize(H + 1,vector<char> (W + 1,'.'));
	
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) cin >> S[i][j];
	
	vector<vector<ll>> dp(H + 1,vector<ll> (W + 1,0));
	vector<vector<ll>> pre_right(H + 1,vector<ll> (W + 1,0));
	vector<vector<ll>> pre_down(H + 1,vector<ll> (W + 1,0));
	vector<vector<ll>> pre_diag(H + 1,vector<ll> (W + 1,0));
	
	dp[1][1] = 1;
	pre_right[1][1] = 1;
	pre_down[1][1] = 1;
	pre_diag[1][1] = 1;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++){
			if (i == 1 && j == 1) continue;
			if (S[i][j] != '#'){
				if (S[i - 1][j] != '#') dp[i][j] = (dp[i][j] + pre_down[i - 1][j]) % Mod; 
				if (S[i][j - 1] != '#') dp[i][j] = (dp[i][j] + pre_right[i][j - 1]) % Mod; 
				if (S[i - 1][j - 1] != '#') dp[i][j] = (dp[i][j] + pre_diag[i - 1][j - 1]) % Mod;
			}
			pre_down[i][j] = dp[i][j]; 
			pre_right[i][j] = dp[i][j]; 
			pre_diag[i][j] = dp[i][j];
			
			if (S[i - 1][j] != '#') pre_down[i][j] = (pre_down[i][j] + pre_down[i - 1][j]) % Mod;
			if (S[i][j - 1] != '#') pre_right[i][j] = (pre_right[i][j] + pre_right[i][j - 1]) % Mod;
			if (S[i - 1][j - 1] != '#')pre_diag[i][j] = (pre_diag[i][j] + pre_diag[i - 1][j - 1]) % Mod; 
		}
	
	cout << dp[H][W];
	return 0;
}
