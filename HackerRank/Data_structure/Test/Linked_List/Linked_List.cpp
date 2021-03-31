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

class List{
    public :
        Node* Head;
        Node* Tail;

    void Init(){
        this -> Head = nullptr;
        this -> Tail = nullptr;
    }
    void Add_Head(int data){
        Node* new_Node = new Node(data);
        if (this -> Head == nullptr){
            this -> Head = new_Node;
            this -> Tail = this -> Head;
        }
        else{
            new_Node -> next = this -> Head;
            this -> Head = new_Node;
        }
    }

    void Add_Tail(int data){
        Node* new_Node = new Node(data);
        if (this -> Head == nullptr){
            this -> Head = new_Node;
            this -> Tail = this -> Head;
        }
        else {
            this -> Tail -> next = new_Node;
            this -> Tail = new_Node;
        }
    }
    void Add_position(int pos,int data){
        if (pos == 0) (*this).Add_Head(data);
        else {
            Node* curNode = this -> Head;
            Node* new_Node = new Node(data);
            while (pos - 1 > 0){
                curNode = curNode -> next;
                pos --;
            }
            new_Node -> next = curNode -> next;
            curNode -> next = new_Node;
        }

    }

    int Find_element(int val){
        Node* curNode = this -> Head;
        while (curNode != nullptr){
            if (curNode -> data == val) return 1;
            curNode = curNode -> next;
        }
        return 0;
    }

    void DeleteList(int pos){
        if (this -> Head == nullptr) return ;
        Node* preNode = this -> Head;
        Node* curNode = this -> Head;
        if (pos == 0){
            this -> Head = (this -> Head) -> next;
            if (this -> Head == nullptr) this -> Tail = nullptr;
            return;
        }
        while (pos > 0){
            preNode = curNode;
            curNode = curNode -> next;
            pos --;
        }
        if (curNode == NULL) return;
        preNode -> next = curNode -> next;
        delete curNode;

    }
    void Print_List(){
        Node* curNode = this -> Head;
        while (curNode != nullptr){
            cout << curNode -> data << ' ';
            curNode = curNode -> next;
        }
        cout << '\n';
    }

    void SortList(){
        Node* cur1Node = this -> Head;
        while (cur1Node -> next != nullptr){
            Node* cur2Node = cur1Node -> next;
            while (cur2Node != nullptr){
                if (cur2Node -> data < cur1Node -> data) swap(cur1Node -> data,cur2Node -> data);
                cur2Node = cur2Node -> next;
            }
            cur1Node = cur1Node -> next;
        }
    }


};

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int n;
    List llist;
    llist.Init();
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        llist.Add_Head(x);
    }

    llist.Add_position(0,-1);
    //llist.DeleteList(llist,0);
    //llist.SortList(llist);
    llist.Print_List();
    llist.SortList();
    llist.Print_List();
    cout << llist.Find_element(6);
    return 0;
}
