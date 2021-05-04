#include <bits/stdc++.h>
using namespace std;

bool is_square(int x){
    int sqrt_x = sqrt(x);
    while (sqrt_x*sqrt_x < x) sqrt_x++;
    return (x == sqrt_x*sqrt_x);
}

void solve(){
    int n;
    cin >> n;
    if (n % 2 == 0 && is_square(n/2)) cout << "YES\n";
    else if (n % 4 == 0 && is_square(n/4)) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
