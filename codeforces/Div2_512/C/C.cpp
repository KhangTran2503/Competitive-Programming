#include<bits/stdc++.h>
#define N 105
using namespace std;
int a[N],n;


int Find(int l,int r,int x,int pre)
{
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (a[mid]-a[pre]==x)
        {
            int mid1=mid;
            while (mid1<=n && a[mid1]==a[mid]) mid1++;
            return mid1-1;
        }
        if (a[mid]-a[pre]>=x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

bool check()
{
    int pos,sum;
    for(int i=1; i<n; i++)
    {
        sum=a[i]-a[0];
        pos=i;
        while (1)
        {
            int vt=Find(pos+1,n,sum,pos);
            if (vt==n) return true;
            if (vt==-1) break;
            pos=vt;

        }
    }
    return false;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char x;
        cin>>x;
        a[i]=a[i-1]+x-'0';
    }
    if (check()) cout<<"YES";
    else cout<<"NO";
    return 0;
}
