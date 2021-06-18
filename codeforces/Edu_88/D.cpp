/*	2021-06-17	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<int> a;
vector<int> prefixsum;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	prefixsum.resize(n + 1);
	a.resize(n + 2);
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		prefixsum[i] = prefixsum[i - 1] + a[i];
	}
	
	// sparse table
	// first min
	// second max
	int H = (int)log2(n) + 1;
	vector<vector<ii>> jump(H + 1,vector<ii> (n + 1));
	for (int i = 0; i <= n; i++) jump[0][i] = {prefixsum[i],prefixsum[i]};
	
	for (int k = 1; k <= H; k++)
		for (int i = 0; i + (1 << k) - 1<= n; i++){
			int len2 = 1 << (k - 1);
			jump[k][i].first = min(jump[k - 1][i].first,jump[k - 1][i + len2].first);
			jump[k][i].second = max(jump[k - 1][i].second,jump[k - 1][i + len2].second);
			
		}
	

	// lambda function
	auto getmin = [&](int L,int R)-> int{
		if (R < L) return INF;
		int len = (int)log2(R - L + 1);
		return min(jump[len][L].first,jump[len][R - (1 << len) + 1].first);
		
	};
	
	auto getmax = [&](int L,int R)-> int{
		if (R < L) return -INF;
		int len = (int)log2(R - L + 1);
		return max(jump[len][L].second,jump[len][R - (1 << len) + 1].second);
		
	};
	
	// stack 
	stack<int> st;
	vector<int> left(n + 1);
	vector<int> right(n + 1);
	st.push(0);
	for (int i = 1; i <= n; i++){
		while (st.size() > 1 && a[i] >= a[st.top()]) st.pop();
		left[i] = st.top() + 1;
		st.push(i);
	}
	
	// clear stack
	while (!st.empty()) st.pop();
	
	st.push(n + 1);
	for (int i = n; i >= 1; i--){
		while (st.size() > 1 && a[i] >= a[st.top()]) st.pop();
		right[i] = st.top() - 1;
		st.push(i);
	}
	
	//for (int i = 1; i <= n; i++) cout << prefixsum[i] << ' ';
	//cout << '\n';
	//for (int i = 1; i<= n; i++) cout << left[i] << ' ';
	//cout << '\n';
	//for (int i = 1; i <= n; i++) cout << right[i] << ' ';
	//cout << '\n';
	
	int ans = -INF;
	
	
	for (int i = 1; i <= n; i++){
		//cout << getmin(left[i] - 1,i - 1) << ' ' << getmax(i,right[i]) << '\n';
		int sumL = getmin(left[i] - 1,i - 1);
		int sumR = getmax(i,right[i]);
		if (ans < sumR - sumL - a[i]){
			ans = sumR - sumL - a[i];
			//idx = i;
		}
	}
	
	//cout << idx << '\n';
	cout << ans;
	return 0;
}
