#include<bits/stdc++.h>

using namespace std;

struct Time{
    int d, m, y;
};

int calc(Time x) {
        if (x.m < 3) {
            x.y--;
            x.m += 12;
        }
        return 365*x.y + x.y/4 - x.y/100 + x.y/400 + (153*x.m - 457)/5 + x.d - 306;
}

int main(){

    Time u;
    cin >> u.d >> u.m >> u.y;

    int n; 
    cin >> n;
    while (n--){
        Time v;
        cin >> v.d >> v.m >> v.y;

        v.y += 18;

        int uu = calc(u);
        int vv = calc(v);


        if (uu >= vv) cout << "YES\n"; 
        else cout << vv - uu << '\n';
    }

}