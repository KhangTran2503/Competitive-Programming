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

class Node{
    public :
        int data;
        Node* next;
    Node (int data){
        this -> next = nullptr;
        this -> data = data;
    }
};

class Stack{
    public :
        Node* Head;
        Node* Tail;

    Stack(){
        this -> Head = this -> Tail = nullptr;
    }
    void Push(int data){
        Node* new_Node = new Node(data);
        new_Node -> next = this -> Head;
        this -> Head = new_Node;
    }

    int Top(){
        return (this -> Head) -> data;
    }

    bool Empty(){
        return (this -> Head == nullptr);
    }

    void Pop(){
        (this -> Head ) = (this -> Head) -> next;
    }
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    Stack St;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        St.Push(x);
    }

    while (!St.Empty()){
        cout << St.Top() << ' ';
        St.Pop();
    }

    return 0;
}
