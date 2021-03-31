///y tuong
///khi chia cac so cho GCD thi cac so con lai se nguyen to cung nhau
///nen pai bo bot 1 so so sao cho day co GCD>2
///Chon day co nhieu phan tu chung nhat khi ma pt ra nt
#include <bits/stdc++.h>
#define N 15000005
#define NN 3*int(1e5)+5
using namespace std;
int prime[N]={0},cnt[N],a[NN],res=0,G=0;
int n;

void Era()
{
    for (int i=2; i*i<=15000000; i++)
        if (prime[i]==0)
           for (int j=i*i; j<=15000000; j+=i) prime[j]=i;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        G=__gcd(G,a[i]);
    }

    res=0;
    for(int i=1; i<=n; i++)
    {
        a[i]/=G;
        if (a[i]==1) res++;
    }

    if (res==n) cout<<-1;
    else
    {
        Era();
        int res=0;
        for (int i=1; i<=n; i++)
            if (a[i]!=1)
        {
            set<int> s;
            while (prime[a[i]])
            {
                s.insert(prime[a[i]]);
                a[i]/=prime[a[i]];
            }
            if (a[i]>1) s.insert(a[i]);
            for (auto x: s)
            {
                cnt[x]++;
                res=max(res,cnt[x]);///chon so pt co nhieu thua so chung nhat
            }
        }
        if (n-res==n) cout<<-1;
        else cout<<n-res;

    }
    return 0;
}
