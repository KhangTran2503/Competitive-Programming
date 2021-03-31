// Use Trie
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* child[2];
    Node(){
        for (int i = 0; i < 2; i++) child[i] = nullptr;
    }
};

typedef long long ll;
typedef Node* pNode;

struct Trie
{
    private: 
        Node* root = new Node();
        ll calcnode(pNode curNode,int h){
            if (!curNode->child[0] && !curNode->child[1]) return 0;
            if (!curNode->child[0]) return calcnode(curNode->child[1],h - 1);
            if (!curNode->child[1]) return calcnode(curNode->child[0],h - 1);
            return (1LL << h) + min(calcnode(curNode->child[0],h - 1),calcnode(curNode->child[1],h - 1));
        }
    public:
        void Insert(int x){
            pNode curNode = root;
            for (int pos = 29; pos >= 0; pos--){
                int bit = (x >> pos) & 1;
                if (!curNode->child[bit]) curNode->child[bit] = new Node();
                curNode = curNode->child[bit];
            }
        }

        long long calc(){
            return calcnode(root,29);
        }
};


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Trie T;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        T.Insert(x);
    }
    cout << T.calc();
    return 0;
}