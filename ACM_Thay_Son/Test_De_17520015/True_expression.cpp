#include <bits/stdc++.h>
using namespace std;
int N, S;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> S;

	int SumAll = N*(N + 1)/2;
	if (SumAll < S){
		cout << "NO_SOLUTION";
		return 0;
	}

	int shift = SumAll;
	vector<vector<bool>> dp(N + 1,vector<bool> (SumAll + shift + 1,false));
	
	dp[0][0 + shift] = 1;

	for (int i = 1; i <= N; i++)
		for (int j = -SumAll; j <= SumAll; j++){
			//dp[i][j + shift] = dp[i - 1][j + shift];
			if (j - i >= -SumAll) dp[i][j + shift] = (dp[i - 1][j - i + shift] || dp[i][j + shift]);
			if (j + i <= SumAll) dp[i][j + shift] = (dp[i - 1][i + j + shift] || dp[i][j + shift]);
		}


	if (!dp[N][S + shift]) cout << "NO_SOLUTION";
	else {
		stack<char> ans;
		for (int i = N, j = S; i > 0; i--){
			if (j - i >= -SumAll && dp[i - 1][j - i + shift]){
				ans.push('+');
				j -= i;
			}
			else if (j + i <= SumAll && dp[i - 1][j + i + shift]){
				ans.push('-');
				j += i;
			}
		}

		while (!ans.empty()){
			cout << ans.top();
			ans.pop();
		}
	}
	return 0;
}