#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
struct Node{
    Node* children[27];
    bool isend;
    Node(int is){
        isend=is;
        for (int i=0; i<27; i++)
            children[i]=NULL;
    }
};
typedef Node* pNode;
string keys[N];
pNode root=new Node(0);

int n,q;


void Insert(pNode root,string key){
    pNode curNdoe=root;

    for(int i=0; i<key.size(); i++){
        int index=key[i]-'a';
        if (!curNdoe->children[index]) curNdoe->children[index]=new Node(0);
        curNdoe=curNdoe->children[index];
    }
    curNdoe->isend=1;

}

bool Search(pNode root,string key){
    pNode curNode=root;
    for(int i=0; i<key.size(); i++){
        int index=key[i]-'a';
        if (!curNode->children[index]) return false;
        curNode=curNode->children[index];
    }
    return (curNode!=NULL && curNode->isend);
}

int main()
{
    //cout << "Hello world!" << endl;
    freopen("Test.INP","r",stdin);
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>keys[i];
    for(int i=1; i<=n; i++)
        Insert(root,keys[i]);

    cin>>q;
    while(q--){
        string s;
        getline(cin,s);
        cout<<s<<'\n';
        Search(root,s)? cout<<"Yes\n" : cout<<"No\n";
    }
    return 0;
}
