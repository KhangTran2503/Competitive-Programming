#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    //sort(a.begin(),a.end());
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (sum == x){
            if (i == n - 1){
                cout << "NO\n";
                return;
            }
            swap(a[i],a[i + 1]);
            break;
        }
    }
    cout << "YES\n";
    for (int ai: a) cout << ai << ' ';
    cout << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
