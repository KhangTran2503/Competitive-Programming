// Prefection
// AC
/*	2021-06-21	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
bool is_start = true;


int perfect(int x){
	int sum = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0) sum += i;
	
	if (sum < x) return -1;
	else if (sum == x) return 0;
	return 1;
}

bool solve(){
	int N;
	cin >> N;
	if (N == 0){
		cout << "END OF OUTPUT\n";
		return false;
	}
	if (is_start){
		cout << "PERFECTION OUTPUT\n";
		is_start = false;
	}
	
	cout << setw(5) << N << "  ";
	int val = perfect(N);
	if (val == 1) cout << "ABUNDANT\n";
	else if (val == 0) cout << "PERFECT\n";
	else cout << "DEFICIENT\n";

	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	while (solve());
	return 0;
}
