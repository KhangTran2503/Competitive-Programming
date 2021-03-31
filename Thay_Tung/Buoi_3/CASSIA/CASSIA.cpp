#include <bits/stdc++.h>
#define oo int(1e9)
#define N int(1e5)+5
using namespace std;
int a[N],n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    int res=oo;
    int j=1;
    for(int i=1; i<=n; i++)
    {
        while (j<=n && a[j]-a[i]<n)
            j++;
        int cnt=j-i;
        res=min(res,n-cnt);
    }
    cout<<res;
    return 0;
}
