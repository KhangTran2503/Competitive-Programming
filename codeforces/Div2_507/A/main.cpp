#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c[25],a[2],n;

void check()
{
    int res=0;
    for(int i=1; i<=n/2; i++)
    {
        int j=n+1-i;
        if ((c[i]!=c[j]))
        {
            if (c[i]==2 || c[j]==2)
            {
                if (c[i]==c[j]) res+=2*min(a[0],a[1]);
                else if (c[i]==2) res+=a[c[j]];
                     else res+=a[c[i]];
            }
            else
            {
                cout<<-1;
                return;
            }
        }
        else
        {
            if (c[i]==2) res+=2*min(a[0],a[1]);
        }

    }
    if (n%2==1 && c[n/2+1]==2) res+=min(a[0],a[1]);
    cout<<res;
}
//===================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>a[0]>>a[1];
    for(int i=1; i<=n; i++) cin>>c[i];
    check();
    return 0;
}
