#include <bits/stdc++.h>
#define N int(1e6)+5
using namespace std;
int n,res=0;


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<int> a(n+1);
    vector<int> h(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=i;
    }


    res=1;
    h[1]=a[1];
    for(int i=2; i<=n; i++)
    {
        if (a[i]>h[res]) h[++res]=a[i];
        else
        {
            int pos=lower_bound(h.begin()+1,h.begin()+1+res,a[i])-h.begin();
            h[pos]=a[i];
        }
    }
    cout<<res;
    return 0;
}
