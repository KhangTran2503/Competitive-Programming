#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int Maxn = int(1e6);
int N, A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> A >> B;
	vector<ld> E(Maxn + 1,0.0);
	vector<ld> sumE(Maxn + 1,0.0);
	int L = B - A + 1;
	for (int i = 1; i < A; i++) E[i] = 1.0;
	if (A > 0){
		for (int i = 1; i < A; i++) sumE[i] = sumE[i - 1] + 1.0;
		for (int i = A; i <= N; i++){
			int j = max(i - B - 1,0);
			E[i] = 1.0 + 1/(ld)L*(sumE[i - A] - sumE[j]);
			sumE[i] = sumE[i - 1] + E[i];
		}
		
	}
	else {
		for (int i = 1; i <= N; i++){
			int j = max(i - B - 1,0);
			E[i] = ((ld)L/(ld)(L - 1))*(1 + 1/(ld)L*(sumE[i - 1] - sumE[j]));
			sumE[i] = sumE[i - 1] + E[i];
		}
	}
	cout << fixed << setprecision(5) << E[N];
	return 0;
}
