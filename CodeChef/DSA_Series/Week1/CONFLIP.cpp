#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--){
		int G;
		cin >> G;
		while (G--){
			int N, I, Q;
			cin >> I >> N >> Q;
			if (N % 2 == 0){
				cout << N/2 << '\n';
			}
			else {
				if (I != Q) cout << N/2 + 1 << '\n';
				else cout << N/2 << '\n';
			}
		}
				
	}
	return 0;
}
