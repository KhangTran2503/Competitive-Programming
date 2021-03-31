#include <bits/stdc++.h>

using namespace std;
int64_t n,L,a;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>L>>a;
    if (n==0) cout<<L/a;
    else
    {
        int64_t res=0;
        vector<int> r(n+1);
        r[0]=0;
        for(int i=1; i<=n; i++)
        {
            int64_t x,y;
            cin>>x>>y;
            res+=(x-r[i-1])/a;
            r[i]=x+y;
        }
        res+=(L-r[n])/a;
        cout<<res;
    }
    return 0;
}
