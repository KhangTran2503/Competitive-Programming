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
#define matrix vector<vector<ll>>
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
using namespace std;
const int INF = int(1e9);
int cost[] = {25,50,75,100};
int cnt[4][4], d1[4], d2[4], d3[4];
int val;

void dq(int pos,int sum){
    if (pos == 4){
        val = max(val,sum);
        return;
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (!d1[i] && !d2[j] && !d3[k]){
                    d1[i] = 1;
                    d2[j] = 1;
                    d3[k] = 1;
                    if (cnt[i][j] == 0) dq(pos + 1,sum - 100);
                    else dq(pos + 1,sum + cnt[i][j]*cost[k]);
                    d1[i] = 0;
                    d2[j] = 0;
                    d3[k] = 0;
                }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    int sum = 0;
    while (T--){
        int n;
        cin >> n;
        ms(cnt,0);
        ms(d1,0);
        ms(d2,0);
        ms(d3,0);
        vector<vector<int>> ticket(4);
        while (n--){
            char x; int y;
            cin >> x;
            cin >> y;
            cnt[x - 'A'][(y/3) - 1]++;
            //ticket[x - 'A'].emplace_back(y);
        }

        val = -INF;
        dq(0,0);
    
        /*for (int i = 0; i < 4; i++) 
            if (ticket[i].empty()) val -= 100;*/
        cout << val << '\n';
        sum += val;
    }
    cout << sum;
    return 0;
}