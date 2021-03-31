/*	2021-02-17	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll LIM = (ll)(1e9);
const ll offset = 10000;
double X, Y, R;
ll x, y, r;

ll Sqrt(ll num){
	if (num < 0) return -1;
	if (num == 0) return 0;
	ll res = (ll)sqrt(num) - 1;
	//while (res*res > num) res--;
	while ((res + 1LL)*(res + 1LL) <= num) res++;
	return res;
}

ll get_down(ll num){
	if (num >= 0) return (num/offset)*offset;
	return (num/offset)*offset - (ll)(num % offset != 0)*offset;
}

ll get_up(ll num){
	if (num <= 0) return (num/offset)*offset;
	return (num/offset)*offset + (ll)(num % offset != 0)*offset;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> X >> Y >> R;
	
	x = round(X*offset);
	y = round(Y*offset);
	r = round(R*offset);
	//cout << x << ' ' << y << ' ' << r << '\n';
	
	ll sqr_r = r*r;
	ll left_x = get_up(x - LIM);
	ll right_x = get_down(x + LIM);
	
	//cout << left_x << ' ' << right_x << '\n';
	
	ll ans = 0;
	for (ll x0 = left_x; x0 <= right_x; x0 += offset){
		//cout << x0 << '\n';
		ll A = Sqrt(sqr_r - (ll)(x0 - x)*(x0 - x));
		if (A == -1) continue;
		ll y_left = get_up(-A + y);
		ll y_right = get_down(A + y);
		//cout << x0 << ' ' << y_left << ' ' << y_right << '\n';
		ans += max(0LL,(y_right - y_left)/offset + 1);
	}
	cout << ans;
	return 0;
}