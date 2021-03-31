#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int64_t n;

int64_t sum(int64_t x)
{
    int64_t res=0;
    while (x>0)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
int main()
{


    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    if (n<=10) cout<<n;
    else
    {
        int64_t x=9;
        int64_t ans=0;
        for(;;)
        {
            if (x>n) break;
            ans=max(ans,sum(x)+sum(n-x));
            x=x*10+9;
        }
        cout<<ans;
    }
    return 0;
}
