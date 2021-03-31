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
/// MLE
struct Node{
    Node* lef;
    Node* rig;
    int rangeL, rangeR;
    int sum;
    char lazy;
    Node(){}
    Node(int _ll,int _rr){
        lef = nullptr;
        rig = nullptr;
        rangeL = _ll, rangeR = _rr;
        sum = 0;
        lazy = -1;
    }

    void down(){
        if (rangeL != rangeR){
            int mid = (rangeL + rangeR) >> 1;
            if (!lef) lef = new Node(rangeL,mid);
            if (!rig) rig = new Node(mid + 1,rangeR);
        }
        if (lazy != -1){
            if (lazy == 0) sum = 0;
            else sum = (rangeR - rangeL  + 1);
            if (lef) lef->lazy = lazy;
            if (rig) rig->lazy = lazy;
            lazy = -1;
        }
    }


    void update(int L,int R,int ok){
        down();
        if (rangeL > R || rangeR < L) return;
        if (rangeL >= L && rangeR <= R){
            lazy = ok;
            down();
            return;
        }
        lef->update(L,R,ok);
        rig->update(L,R,ok);
        sum = (lef->sum) + (rig->sum);

    }

    int get(int L,int R){
        down();
        if (rangeL > R || rangeR < L) return 0;
        if (rangeL >= L && rangeR <= R) return sum;
        return lef->get(L,R) + rig->get(L,R);
    }    
    ~Node(){}
};
//typedef Node* pNode;

struct SegTree{
    SegTree(){}
    Node* root;
    
    SegTree(int rangeL,int rangeR){root = new Node(rangeL,rangeR);}
    void inc_range(int L,int R,char ok){
        root->update(L,R,ok);
    }
    int get_range(int L,int R){
        return root->get(L,R);
    }
    ~SegTree(){}
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    SegTree ST(1,n);

    while (q--){
        int l, r, k;
        cin >> l >> r >> k;
        if (k == 1) ST.inc_range(l,r,1);
        else ST.inc_range(l,r,0);
        cout << n - ST.get_range(1,n) << '\n';
    }
    return 0;
}