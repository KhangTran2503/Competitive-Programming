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
int n;


struct Node
{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data): data(data){}
};

Node* Insert(Node* node,int data){
    if (node == nullptr) return new Node(data);
    if (data < node -> data)
        node -> left = Insert(node -> left, data);
    else if (data > node -> data)
        node -> right = Insert(node -> right, data);
    return node;
}

Node* Find(Node* node, int data){
    if (node == nullptr) return nullptr;
    if (data < node -> data) return Find(node -> left, data);
    if (data > node -> data) return Find(node -> right, data);
    return node;
}

Node* Find_remove(Node* node,int data){
    if (node == nullptr) return nullptr;
    if (node -> data == data){
        if (node -> left == nullptr && node -> right) return nullptr;
        if (node -> left != nullptr && node -> right != nullptr){
            Node* succesor = node -> right;
            while (succesor -> left != nullptr) succesor = succesor -> left;

            node -> data = succesor -> data;
            node -> right = Find_remove(node -> right, succesor -> data);
            return node;
        }
        if (node -> left != nullptr) return node -> left;
        else return node -> right;

    }
    if (data > node -> data) node -> right = Find_remove(node -> right, data);
    else node -> left = Find_remove(node -> left, data);
    return  node;
}

void Print_BST(Node* root){
    if (root == nullptr) return;
    cout << root -> data << ":\n";
    if (root -> left != nullptr) cout << "left: " << (root -> left) -> data << "  ";

    if (root -> right != nullptr) cout << "right: " << (root -> right) -> data << '\n';

    Print_BST(root -> left);
    Print_BST(root -> right);

}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root -> data << '\n';
        inorder(root->right);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = Insert(root,x);
    }
    Print_BST(root);
    //inorder(root);


    return 0;
}
