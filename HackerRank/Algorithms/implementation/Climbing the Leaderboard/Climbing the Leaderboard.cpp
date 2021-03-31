#include<bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int n,m;

int scores[N];

int Find(int x){
    int l=1, r=n;
    int res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if (x>=scores[mid]){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<int> b(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        b[i]=x;
    }
    sort(b.rbegin(),b.rend());
    b.erase(unique(b.begin(),b.end()),b.end());
    n=b.size();
    for (int i=0; i<b.size(); i++)
        scores[i+1]=b[i];

    cout<<n<<'\n';
    cout<<scores[n]<<'\n';
    cin>>m;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        if (x>scores[1]) cout<<1<<'\n';
        else if (x<scores[n]) cout<<n+1<<'\n';
        else cout<<Find(x)<<'\n';
    }
    return 0;
}
