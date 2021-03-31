#include <bits/stdc++.h>
using namespace std;
int a, b, c;

// Extended_Euclid
int gcd(int a,int b,int &x,int &y){
	if (a == 0){
		x = 0; y = 1;
		return b;
	}
	int x1, y1, d;
	d = gcd(b % a, a,x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

//find_any_solution

bool find_any_solution(int a,int b,int c,int &x0,int &y0,int &g){
	if (a == b && a == 0) return false;
	g = gcd(abs(a),abs(b),x0,y0);
	if (c % g) return false;

	x0 *= (c/g);
	y0 *= (c/g);
	//cout << x0 << ' ' << y0 << '\n';
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

// find all solution

void shift_solution(int &x,int &y,int a,int b,int cnt){
	x += cnt*b; // x = x0 + k(b/g)
	y -= cnt*a; // y = y0 - k(a/k)
}

int find_all_solution(int a,int b,int c,int minx,int maxx,int miny,int maxy){
	int x, y, g;
	if (!find_any_solution(a,b,c,x,y,g)) return 0;

	a /= g;
	b /= g;
	int sign_a = (a > 0) ? 1 : -1;
	int sign_b = (b > 0) ? 1 : -1;

	shift_solution(x,y,a,b,(minx - x)/b);
	if (x < minx) shift_solution(x,y,a,b,sign_b);
	if (x > maxx) return 0;
	int lx1 = x;

	shift_solution(x,y,a,b,(maxx - x)/b);
	if (x > maxx) shift_solution(x,y,a,b,-sign_b);
	if (x < minx) return 0;
	int rx1 = x;

	shift_solution(x,y,a,b, -(maxy - y)/a);
	if (y > maxy) shift_solution(x,y,a,b,sign_a);
	if (y < miny) return 0;
	int lx2 = x;

	shift_solution(x,y,a,b,-(minx - y)/a);
	if (y < miny) shift_solution(x,y,a,b,-sign_a);
	if (y > maxy) return 0;
	int rx2 = x;

	if (lx2 > rx2) swap(lx2,rx2);

	int lx = max(lx1,lx2);
	int rx = min(rx1,rx2);
	if (lx > rx) return 0;
	return ((rx - lx)/abs(b) + 1);


}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	int x0 , y0, g;
	find_any_solution(a,b,c,x0,y0,g);
	cout << x0 << ' ' << y0;
	return 0;
}