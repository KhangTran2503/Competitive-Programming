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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
struct Node{
    int cnt;
    Node* child[2];
    Node(){
        cnt = 0;
        for (int i = 0; i < 2; i++) child[i] = NULL;
    }
};
typedef Node* pNode;
pNode root1 = new Node();
pNode root2 = new Node();
int m,n;

void Insert1(vi x){
    pNode tmp = root1;
    for (int i = 0; i < sz(x); i++){
        int id = x[i];
        if (tmp->child[id] == NULL) tmp->child[id] = new Node();
        tmp = tmp->child[id];
        (tmp->cnt)++;
    }
}
void Insert2(vi x){
    pNode tmp = root2;
    for(int i = 0; i < sz(x); i++){
        int id = x[i];
        if (tmp->child[id] == NULL) tmp->child[id] = new Node();
        tmp = tmp->child[id];
    }
    (tmp->cnt)++;
}

int Search1(vi x){
    pNode tmp = root1;
    int cnt = 0;
    for(int i = 0; i < sz(x); i++){
        int id = x[i];
        if (tmp->child[id] == NULL) return 0;
        tmp = tmp->child[id];
    }
    cnt = tmp->cnt;
    return cnt;
}

int Search2(vi x){
    pNode tmp = root2;
    int cnt = 0;
    for(int i = 0; i < sz(x); i++){
        int id = x[i];
        if (tmp->child[id] == NULL) return cnt;
        tmp = tmp->child[id];
        cnt += (tmp->cnt);
    }
    cnt -= (tmp->cnt);
    return cnt;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        vi a(x);
        for (int j = 0; j < x; j++) cin >> a[j];
        Insert1(a);
        Insert2(a);
    }

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        vi a(x);
        for(int j = 0; j< x; j++) cin >> a[j];
        int ans = Search1(a) + Search2(a);
        cout << ans << '\n';
    }

    return 0;
}
