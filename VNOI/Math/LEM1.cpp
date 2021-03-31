/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (db)(x)*(db)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define eps (db)(0.000000000000001)
using namespace std;
//typedef long double ld;
const db Pi = acos(-1);
int n;
/// ko hieu s chua AC =))
int check(db x){
    if (fabs(x-2.0*Pi) < eps) return 1;
    if (x > 2.0*Pi) return 2;
    return 0;
}

/*db angle(db a, db b, db c){
    db tmp = 0;

}*/
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    vector<db> r(n);
    db lo = 0, hi = 0;
    for (int i = 0; i < n; i++){
        cin >> r[i];
        hi += r[i];
    }
        db mid = (lo + hi)/2.0;
    while (lo != mid && hi != mid){
        db tmp = 0;
        for (int i = 0; i < n-1; i++){
            db tmp1 = acos((-sqr(r[i]+r[i+1])+sqr(mid+r[i])+sqr(mid+r[i+1]))/((db)2.0*(mid+r[i])*(mid+r[i+1])));
            tmp += tmp1;
        }
        tmp += acos((-sqr(r[0]+r[n-1])+sqr(mid+r[0])+sqr(mid+r[n-1]))/((db)2.0*(mid+r[0])*(mid+r[n-1])));
        //int ck = check(tmp);
        /*if (ck == 1){
            cout << prec(3) << mid;
            return 0;
        }
        if (ck == 0) hi = mid;
        else lo = mid;*/
        if (tmp == 2.0*Pi){
            cout << prec(3) << mid;
            return 0;
        }
        else if (tmp > 2.0*Pi) hi = mid;
        else lo = mid;
        mid = (lo + hi)/2.0;
    }
    //cout << hi;
    return 0;
}
