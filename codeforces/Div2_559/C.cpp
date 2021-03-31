#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
/*
    Y tuong : thay doi vt ko quan trong => sort lai
    Proof:
        Max(min(ai,j)) <= Min(max(ai,j)) <=> Max(bi) <= Min(gi)

    => -1 neu ko thoa
    => nhan xet chi can thay doi 2 hang cuoi neu cho bi nam ngang con gi doc
    an2 -> ann chi gan gt g2 -> gm
    a(n - 1)2 -> a(n -1)n  gan b(n-1)
    if (bn = g1) thi an1 = g1 va a(n-1)1 = b(n-1)
    else an1 = bn va a(n-1)1 = g1

    ans = (sigma bi/ i= 1-> n-2)*m +         


*/


int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> m;
	vector<ll> b(n);
	vector<ll> g(m);
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cin >> g[i];
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());
	if (b[n - 1] > g[0]){
	    cout << -1;
	    return 0;
	}
	ll ans = 0;
	for (int i = 0; i < n - 2; i++) ans += b[i];
	ans *= (ll)m;
	for (int i = 0; i < m; i++) ans += g[i];
	ans += (ll)(m - 1)*b[n - 2];

	if (b[n - 1] == g[0]) ans += b[n - 2];
	else ans += b[n - 1];
	cout << ans;
	return 0;
}
