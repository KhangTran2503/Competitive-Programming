#include <iostream>
#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef long long ll;
ll s[N],h[N],k,du=0;
int n;


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>h[i];
    }
    sort(h+1,h+1+n);
    for(int i=1; i<=n; i++) s[i]=s[i-1]+h[i];
    if (h[1]==h[n]) cout<<0;
    else
    {
        ll target=h[1]*(ll)n;
        int R=h[n],res=0;
        while(s[n]>target)
        {
            int l=h[1],r=R-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                int pos=upper_bound(h+1,h+1+n,mid)-h;
                if (s[n]-s[pos-1]-(ll)mid*(ll)(n-pos+1)<=k)
                {
                    du=s[n]-s[pos-1]-(ll)mid*(ll)(n-pos+1);
                    R=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            s[n]-=du;
            res++;
        }
        cout<<res;
    }
    return 0;
}
