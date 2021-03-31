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
#define vii vector<ii>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
vii a;
int n, p, q;
ll ans = 0;


int get_p(){
    for (int i = q; i < n; i++){
        if (a[i].fir == a[i + 1].fir){p = i; return p;}
    }
    p = n + 1;
    return p;
}
int get_q(){
    for (int i = p; i < n; i++){
        if (a[i].fir != a[i + 1].fir){q = i; return q;};
    }
}

int get_p_e(){
    for (int i = q; i < n; i++){
        if (a[i] == a[i + 1]){p = i; return p;}
    p = n + 1;
    return p;
}

int get_q_e(){
    for(int i = p; i < n; i++)
        if (a[i] != a[i + 1]){q = i; return q;}
}

ll calc(){
    p = q = 0;
    ll r = 0;
    while (p < n){
        get_p();
        if (p < n){
            get_q();
            ll t = q - p;
            r = t*(t + 1) /2;
        }

    }
    return r;
}

ll calc_e(){
    p = q = 0;
    ll r = 0;
    while (p < n){
        get_p_e();
        if (p < n){
            get_q_e();
            ll t = q - p;
            r = t*(t + 1) /2;
        }

    }
    return r;
}

{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = ii(x,y);
    }
    a.pb(ii(oo,oo + 1));
    sort(all(a));
    ans += calc();
    for (auto &i : a) swap(i.fir, i.sec);
    sort(all(a));
    ans += calc();
    ans -= calc_e();
    cout << ans;
    return 0;
}
