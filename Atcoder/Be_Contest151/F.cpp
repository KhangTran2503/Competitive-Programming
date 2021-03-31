// Chat tam phan
#include <bits/stdc++.h>
using namespace std;
vector<pair<double,double>> p;
int n;


double dis(pair<double,double> u,pair<double,double> v){
    return sqrt((u.first - v.first)*(u.first - v.first) + (u.second - v.second)*(u.second - v.second));
}

double f(double x,double y){
    double ans = 0;
    for (auto pp : p) ans = max(ans,dis(pp,make_pair(x,y)));
    return ans;
}


double g(double y){
    double lef = 0, rig = 1000;
    for (int Loop = 0; Loop < 1000; Loop++){
        double x1 = (lef*2 + rig)/3;
        double x2 = (lef + 2*rig)/3;
        if (f(x1,y) < f(x2,y)) rig = x2;
        else lef = x1;
    }
    return f(lef,y);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    double lef = 0, rig = 1000;
    for (int Loop = 0; Loop < 100; Loop++){
        double y1 = (2*lef + rig)/3;
        double y2 = (lef + 2*rig)/3;
        if (g(y1) < g(y2)) rig = y2;
        else lef = y1;
    }
    cout << fixed << setprecision(10) << g(lef);
    return 0;
}

