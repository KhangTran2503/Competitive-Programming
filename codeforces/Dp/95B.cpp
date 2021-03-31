/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
string n;
vector<char> ans;
int len;

void dq(int pos,bool high,int num4,int num7){

    if (high){
        for (int i = 0; i < pos; i++) cout << ans[i];
        for (int i = 0; i < (len/2 - num4); i++) cout << '4';
        for (int i = 0; i < (len/2 - num7); i++) cout << '7';
        //for (int i = 0; i < len; i++) cout << ans[i];
        exit(0);
    }
    if (pos == len){
        for (int i = 0; i < len; i++) cout << ans[i];
        exit(0);
    }
    
    if (n[pos] <= '4'){
        if (num4 + 1 <= len/2){
            ans.eb('4');
            dq(pos + 1,high || (n[pos] < '4'),num4 + 1,num7);
            ans.pop_back();
        }
    }
    if (n[pos] <= '7'){
        if (num7 + 1 <= len/2){
            ans.eb('7');
            dq(pos + 1,high || (n[pos] < '7'),num4,num7 + 1);
            ans.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    len = n.size();
    if (len & 1){
        for (int i = 0; i < (len + 1)/2; i++) cout << '4';
        for (int i = 0; i < (len + 1)/2; i++) cout << '7';
    }
    else {
        //vector<char> tmp;
        dq(0,0,0,0);
        for (int i = 0; i < (len + 2)/2; i++) cout << '4';
        for (int i = 0; i < (len + 2)/2; i++) cout << '7';
    }
    return 0;
}