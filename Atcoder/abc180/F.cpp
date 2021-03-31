/*	2020-12-02	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const ll Mod = (ll)(1e9) + 7;
ll inv2 = (Mod + 1) >> 1;
int n, m, l;
ll memo[301][301][2];
ll C[301][301];
ll p[301];

// dp[vertex][edges][is_max] là số lượng graph có đỉnh là vertex, cạnh là edges , và trạng thái (is_max)
// là đã có thành phần liên thông lớn nhất = l hay chưa
//  => Đồ thị chỉ có dạng đường thẳng hoặc vòng tròn
//  Dạng 1: Đường thẳng
//  
//
void init(){
	p[0] = 1;
	for (int i = 1; i <= 300; i++) p[i] = (p[i - 1]*i) % Mod;
	
	//for (int i = 0; i <= 300; i++) C[i][0] = 1;
	C[0][0] = 1;
	for (int i = 1; i <= 300; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
	}
}

void add(ll &a,ll b){
	a += b;
	if (a >= Mod) a -= Mod;
}

ll dp(int vertex,int edges,bool is_max){
	if (vertex == 0){
		if ((edges == 0) && (is_max == 1)) return 1;
		return 0;
	}
	ll &res = memo[vertex][edges][is_max];
	if (res != -1) return res;
	res = 0;
	//int can_choice = min(vertex,l);
	
	add(res,dp(vertex - 1,edges,is_max || (l == 1)));
	// k = 2
	if (l >= 2){
		if (vertex >= 2){
			if (edges >= 2) add(res,(dp(vertex - 2,edges - 2,is_max || (l == 2))*C[vertex - 1][1]) % Mod);
			if (edges > 0) add(res,(dp(vertex - 2,edges - 1,is_max || (l == 2))*C[vertex - 1][1]) % Mod);
		}
	}
	
	for (int k = 3; k <= l; k++){
		if (k > vertex) break;
		if (edges >= k - 1) {
			ll tmp1 = dp(vertex - k,edges - k + 1,is_max || (k == l)) % Mod;
			tmp1 = (tmp1*C[vertex - 1][k - 1]) % Mod;
			tmp1 = (tmp1*p[k]) % Mod;
			tmp1 = (tmp1*inv2) % Mod;
			add(res,tmp1);
			//add(res,(dp(vertex - k,edges - k + 1,is_max || (k == l))  % Mod);
		}
		if (edges >= k){
			ll tmp2 = dp(vertex - k,edges - k,is_max || (k == l)) % Mod;
			tmp2 = (tmp2*C[vertex - 1][k - 1]) % Mod;
			tmp2 = (tmp2*p[k - 1]) % Mod;
			tmp2 = (tmp2*inv2) % Mod;
			add(res,tmp2);
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> l;
	init();
	memset(memo,-1,sizeof(memo));
	
	cout << dp(n,m,0);
	return 0;
}