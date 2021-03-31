#include <bits/stdc++.h>
using namespace std;
int n;

int check(int a,int b,int c){
	if (a == b || a == c || b == c) return 0;
	if (a + b <= c) return 0;
	if (a + c <= b) return 0;
	if (c + b <= a) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	vector<int> L(n);
	for (int &l: L) cin >> l;

	int ans = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				ans += check(L[i],L[j],L[k]);
	cout << ans;
	return 0;
}
