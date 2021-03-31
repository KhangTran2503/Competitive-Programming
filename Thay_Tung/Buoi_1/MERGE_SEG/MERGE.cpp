///Cho n doan thang, doan thu i co toa do diem dau va cuoi la
/// a va b.Hay tinh do dai cac doan hop da cho
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,bool> ii;
int64_t ans;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<ii> a(2*n);
    for(int i=0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        a[2*i]=ii(u,0);
        a[2*i+1]=ii(v,1);
    }
    sort(a.begin(),a.end());
    int c=1;
    ans=0;
    for(int i=1; i<2*n; i++)
    {
        if (c) ans+=a[i].first-a[i-1].first;
        if (a[i].second) c--;
        else c++;
    }
    cout<<ans;
    return 0;
}
