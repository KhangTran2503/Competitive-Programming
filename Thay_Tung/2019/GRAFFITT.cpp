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
#define N 200005
using namespace std;
const db Pi = acos(-1);
map<ii,int> col;
struct Node{
    int Min, lazy;
    Node(){}
    Node(int _Min,int _lazy): Min(_Min), lazy(_lazy){}
};
vector<Node> T;
int n, m, q, x, y;
bool isB;
string ans = "";

void down(int id,int l,int r){
    if (T[id].lazy){
        T[id].Min += T[id].lazy;
        if (l < r){
            T[2*id].lazy += T[id].lazy;
            T[2*id + 1].lazy += T[id].lazy;
        }
        T[id].lazy = 0;
    }
}

void Update(int id,int l,int r,int u,int v,int val){
    down(id,l,r);
    if (r < u || l > v || r < l) return;
    if (u <= l && r <= v){
        T[id].Min += val;
        if (l < r){
            T[2 * id].lazy += val;
            T[2 * id + 1].lazy += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    Update(2 * id, l, mid, u, v, val);
    Update(2 * id + 1, mid + 1, r,u , v, val);
    T[id].Min = min(T[2*id].Min, T[2*id + 1].Min);
}

int main()
{
    //cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);

    scanf("%d%d%d",&n, &m, &q);
    T.resize(4*n + 8);
    //for (int i = 0; i < 4*n + 100; i++) T[i] = Node(0,0);
    int w = (m + 1) /2;
    int b = m / 2;
    for (int i = 0; i < n; i++){
        Update(1, 0, n + 1, 0, i ,b);
        Update(1, 0, n + 1, i + 1, n + 1 ,w);
        swap(w,b);
    }

    while (q--){
        scanf("%d%d",&x, &y);
        x --, y --;
        isB = (x + y + (++col[ii(x,y)])) & 1;
        if (isB) {
            Update(1, 0, n + 1, 0, x , 1);
            Update(1,)
        }
        ans += to_string(T[1].Min) + '\n';
    }

    T.clear();
    col.clear();
    printf("%s", ans.c_str());
    return 0;
}
