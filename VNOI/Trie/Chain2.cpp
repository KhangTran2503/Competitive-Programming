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
struct Node
{
    int isend;
    Node* child[26];
    Node(){
        isend = 0;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};
typedef Node* pNode;
pNode root = new Node();
int ans = 0;
int n;

void Insert(string t){
    pNode tmp = root;
    for (int i = 0; i < sz(t); i++){
        int id = t[i] - 'a';
        if (tmp->child[id] == NULL) tmp->child[id] = new Node();
        tmp = tmp->child[id];
    }
    tmp->isend = 1;
}

/// Dem so luong xau ket thuc trong 1 nhanh Trie
void dfs(pNode u,int t){
    ans = max(ans,t + u->isend);
    for (int i = 0; i < 26; i++)
        if (u->child[i] != NULL) dfs(u->child[i],t + u->isend);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        Insert(x);
    }
    pNode tmp = root;
    dfs(tmp,0);
    cout << ans;
    return 0;
}
