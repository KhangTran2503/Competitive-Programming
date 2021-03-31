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
    Node *child[10];
    bool isend = 0;
    Node(){
        for (int i = 0; i < 10; i++) child[i] = NULL;
        isend = 0;
    }
} Trie;
typedef Node* pNode;
pNode root = new Node();
int n;
string s;

void Insert(string t){
    pNode tmp = root;
    for (int i = 0; i < sz(t); i++){
        int id = t[i] - 'a';
        if (tmp->child[id] == NULL) tmp->child[id] = new Node();
        tmp = tmp->child[id];
    }
    tmp->isend = 1;
}

bool Search1(string t){
    pNode tmp = root;
    bool ok = 0;
    for(int i = 0; i < sz(t); i++){
        int id = t[i] - 'a';
        ok |= tmp->isend;
        if (tmp->child[id] == NULL) break;
        //ok |= tmp->isend;
        tmp = tmp->child[id];
    }
    //ok |= tmp->isend;
    return ok;
}

bool Search2(string t){
    pNode tmp = root;
    for (int i = 0; i < sz(t); i++){
        int id = t[i] - 'a';
        if (tmp->child[id] == NULL) return false;
        tmp = tmp->child[id];
    }
    return true;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        if (Search1(s)){
            cout << "BAD SET\n";
            cout << s;
            return 0;
        }
        if (Search2(s)){
            cout << "BAD SET\n";
            cout << s;
            return 0;
        }
        Insert(s);
    }
    cout << "GOOD SET";



    return 0;
}
