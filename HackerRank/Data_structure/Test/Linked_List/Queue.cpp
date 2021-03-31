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

    Node(int data){
        this -> next = nullptr;
        this -> data = data;
    }
};

class Queue{
    public :
        Node* head;
        Node* tail;

    Queue(){
        this -> head = this -> tail = nullptr;
    }

    void Push(int data){
        Node* new_Node = new Node(data);
        if (this -> head == nullptr){
            this -> head = this -> tail = new_Node;
        }
        else {
            (this -> tail) -> next = new_Node;
            (this -> tail) = new_Node;
        }
    }

    int Front(){
        return (this -> head) -> data;
    }

    bool Empty(){
        return (this -> head == nullptr);
    }

    void Pop(){
        (this -> head) = (this -> head) -> next;
    }
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int n;
    Queue q;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.Push(x);
    }

    while (!q.Empty()){
        cout << q.Front() << ' ';
        q.Pop();
    }
    return 0;
}
