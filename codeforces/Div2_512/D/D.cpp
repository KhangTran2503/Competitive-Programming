#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m>>k;
    ll M=m;
    ll Gcd=__gcd(m,k);
    m/=Gcd;
    k/=Gcd;

    Gcd=__gcd(n,k);
    n/=Gcd;
    k/=Gcd;
    if (k>2) cout<<"NO";
    else
    {
        if (k==1)
        {
           if (2*m<=M) m*=2;
           else n*=2;
        }
        cout<<"YES"<<'\n';
        cout<<0<<' '<<0<<'\n';
        cout<<0<<' '<<m<<'\n';
        cout<<n<<' '<<0<<'\n';
    }
    return 0;
}
