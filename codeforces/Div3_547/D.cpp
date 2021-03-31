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
using namespace std;
const db Pi = acos(-1);
priority_queue<ii> pq1;
priority_queue<ii> pq2;
vii pq3;
vii pq4;
vii ans;
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        pq1.push(ii(x-'?',i));
    }
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        pq2.push(ii(x-'?',i));
    }

    while (!pq1.empty() && !pq2.empty()){
        ii u = pq1.top(), v = pq2.top();
        if (u.fir == v.fir){
            if (u.fir == 0){
                pq3.push_back(u);
                pq4.push_back(v);
            }
            else ans.push_back(ii(u.sec,v.sec));
            pq1.pop();
            pq2.pop();
        }
        else if (u.fir < v.fir) {
            pq4.push_back(v);
            pq2.pop();
        }
        else {
            pq3.push_back(u);
            pq1.pop();
        }
    }
    while (!pq1.empty()){
        pq3.push_back(pq1.top());
        pq1.pop();
    }
    while (!pq2.empty()){
        pq4.push_back(pq2.top());
        pq2.pop();
    }

    sort(all(pq3));
    sort(rall(pq4));


    vector<bool> kt(sz(pq3), false);
    for (int i = 0; i < pq3.size(); i++)
        if (!kt[i] && (pq3[i].fir == 0 || pq4[i].fir == 0)){
            ans.push_back(ii(pq3[i].sec, pq4[i].sec));
            kt[i] = true;
        }
    for (int i = sz(pq3) - 1; i >= 0; i--)
        if (!kt[i] && (pq3[i].fir == 0 || pq4[i].fir == 0)){
            ans.push_back(ii(pq3[i].sec, pq4[i].sec));
            kt[i] = true;
        }

    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) cout << ans[i].fir << ' ' << ans[i].sec << '\n';

    return 0;
}
