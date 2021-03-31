#include <iostream>
using namespace std;
typedef long long ll;
ll n,m;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    cout<<max(0LL,n-2*m)<<' ';
    int r=-1;
    for(int i=n; i>=1; i--)
    if ((ll)(ll(i)*ll((i-1)))<2*m)
    {
         r=i;
         break;
    }
    cout<<n-r-1;
    return 0;
}
