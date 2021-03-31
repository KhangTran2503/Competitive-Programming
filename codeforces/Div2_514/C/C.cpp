#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    int cur=1;
    while (n)
    {
        if (n==3)
        {
            cout<<cur<<' '<<cur<<' '<<3*cur;
            break;
        }
        for(int i=1; i<=n; i+=2) cout<<cur<<' ';
        cur*=2;
        n/=2;
    }
    return 0;
}
