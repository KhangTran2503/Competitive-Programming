///tinh phi ham Euler cho 1 so n cho tr
#include <bits/stdc++.h>
using namespace std;
int64_t n;

int64_t Phi(int64_t x)
{
    int64_t res=x;
    for(int i=2; i*i<=x; i++)
        if (x%i==0)
    {
        res-=res/i;
        while (x%i==0) x/=i;
    }
    if (x!=1) res-=res/x;
    return res;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    cout<<Phi(i)<<' ';
    return 0;
}
