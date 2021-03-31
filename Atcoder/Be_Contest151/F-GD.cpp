// Use gradient descent
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<double,double> pi;
vector<pi> point;
int n;

double dis(pi A,pi B){
    return sqrt((A.X - B.X)*(A.X - B.X) + (A.Y - B.Y)*(A.Y - B.Y));
}

double f(pi p){
    double res = 0;
    for (pi x: point) res = max(res,dis(p,x));
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    point.resize(n);
    for (int i = 0; i < n; i++) cin >> point[i].X >> point[i].Y;
    
    double ans = 200000;
    double px = 0, py = 0, alpha = 1e2, delta = 1e-7;
    for (int Loop = 0; Loop < 20000; Loop++){
        double dx = (f(pi(px + delta,py)) - f(pi(px - delta,py)))/(2*delta);
        double dy = (f(pi(px,py + delta)) - f(pi(px,py - delta)))/(2*delta);
        px -= alpha*dx;
        py -= alpha*dy;
        alpha *= 0.999;
    }
    cout << fixed << setprecision(8) << f(pi(px,py));

    return 0;
}