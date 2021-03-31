///Cay BIT
///Con 1 phien ban khac dung Heap
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int fen[N],n;

void update(int x){
    for(int i=x; i<N; i+=(i& -i)) fen[i]++;
}

int get(int x){
    int res=0;
    for(int i=x; i>0; i-=(i& -i)) res+=fen[i];
    return res;
}

int Find(int x){
    int l=1, r=N-1;
    int res=0;
    while (l<=r){
        int mid=(l+r)>>1;
        if (get(mid)>=x){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        update(x+1);
        if (i&1) cout<<fixed<<setprecision(1)<<(Find(i/2+1)-1)*1.0<<'\n';
        else{
            int x1=Find(i/2)-1;
            int x2=Find(i/2+1)-1;
            cout<<fixed<<setprecision(1)<<(x1+x2)/2.0<<'\n';
        }
    }
    return 0;
}
