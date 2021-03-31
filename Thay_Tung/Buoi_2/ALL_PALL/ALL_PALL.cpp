#include <bits/stdc++.h>
using namespace std;
string s;
int64_t ans;
int n;

void calc_1()
{
    vector<int> d(n,0);
    int l=0, r=-1;
    for(int i=0; i<n; i++)
    {
        int k=0;
        if (i<=r) k=min(r-i,d[r-i+l]);
        while (i+k+1<n && i-k-1>=0 && s[i+k+1]==s[i-k-1]) ++k;
        d[i]=k;
        if (i+k>r) l=i-k, r=i+k;

    }
    for(int i=0; i<n; i++) ans+=d[i];
    return ;
}

void calc_2()
{
    vector<int> d(n,0);
    int l=0, r=-1;
    for(int i=0; i<n; i++)
    {
        int k=0;
        if (i<=r) k=min(r-i+1,d[r-i+l+1]);
        while (i+k<n && i-k-1>=0 && s[i+k]==s[i-k-1]) ++k;
        d[i]=k;
        if (i+k-l>r) l=i-k, r=i+k-1;
    }
    for(int i=0; i<n; i++) ans+=d[i];
    return;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    n=s.size();
    ans=n;
    calc_1();
    calc_2();
    cout<<ans;
    return 0;
}
