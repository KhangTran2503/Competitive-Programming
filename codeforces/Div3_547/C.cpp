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
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 2*int(1e5) + 5
using namespace std;
const db Pi = acos(-1);
ll q[N];
ll pi_p1[N] = {0};
ll pi[N];
int kt[N] = {0};
ll sum = 0, sumA = 0;
int n;
/*Nhan Xet:
    p2 - p1 = q1
    p3 - p2 = q2
    ..
    ..
    pn - p(n-1) = q(n-1)
    => qi_q1 = p(i+1) - p1 = sigma q1 ... qi

    => (n*(n+1))/2 - np1 = sigma q2_q1..... qi_q1

    => tim dc p1
    => tim dc cac pi
    => check xem thu  pi >=1 && pi <= n

*/





bool check(){
    for (int i = 1; i <= n; i++)
        if (kt[i] == 0) return false;
    return true;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) cin >> q[i];


    for (int i = 1; i < n; i++){
        pi_p1[i] = pi_p1[i-1] + q[i];
        sumA += pi_p1[i];
    }

    sum = ((ll)n*(ll)(n+1)) / 2;
    ll np1 = sum - sumA;
    if (np1 % n != 0){
        cout << -1;
        return 0;
    }
    ll p1 = np1 / n;
    pi[1] = p1;
    if (p1 <= n && p1 >= 0)  kt[p1] = 1;
    for (int i = 1; i < n; i++){
        pi[i + 1] = p1 + pi_p1[i];
        if (pi[i+1] <= n && pi[i+1] >= 0) kt[pi[i + 1]] = 1;
    }

    if (check()){
        for (int i = 1; i <= n; i++) cout << pi[i] << ' ';
    }
    else cout << -1;


    return 0;
}
