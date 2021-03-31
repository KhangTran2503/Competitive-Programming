#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//const INFLL=ll(1e18);
int n,k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll res=ll(1e18);
    for(int i=-1; i<=1; i+=2)
    {
        vector<int> tmp=a;
        for(int j=0; j<n; j+=2)
            tmp[j]+=k*i;
        //auto tmp2=tmp;
        ll sum=0;
        nth_element(tmp.begin(),tmp.begin()+tmp.size()/2,tmp.end());
        int val=tmp[tmp.size()/2];
        //for(int num: tmp) sum+=abs((ll)num-val);
        for(int i=0; i<n; i++) sum+=abs((ll)a[i]-val);
        //cout<<'\n';
        if (sum<res) res=sum;
    }
    cout<<res;
    return 0;
}
