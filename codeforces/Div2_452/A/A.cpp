#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt1,cnt2,x,res,n;

int main()
{
   // cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if (x==1) cnt1++;
        else cnt2++;
    }
    res=min(cnt1,cnt2);
    if (cnt1>cnt2) res+=(cnt1-cnt2)/3;
    cout<<res;
    return 0;
}
