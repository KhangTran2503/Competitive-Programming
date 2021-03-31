#include <bits/stdc++.h>
#define N 5*int(1e5)+5
using namespace std;
typedef long long ll;
bool okprime[N]={0};
vector<int> prime;
int64_t a,b;
int t;

void era()
{
    for(int i=2; i<N; i++)
        if (!okprime[i])
    {
        prime.push_back(i);
        if (i<=int(sqrt(N-1)))
        {
            for(int j=i*i; j<N; j+=i) okprime[j]=1;
        }
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    era();
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if (a-b==1)
        {
           int64_t t=sqrt(a+b);
           bool ok=true;
           for(auto x: prime)
             if (x<=t)
             {
                 if ((a+b)%x==0)
                 {
                     ok=false;
                     break;
                 }
             }
             else break;
             if (ok) cout<<"YES\n";
             else cout<<"NO\n";
        }
        else cout<<"NO\n";

    }
    return 0;
}
