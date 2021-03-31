#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int64_t ans;

void calc_1()
{
    vector<int> d1(n,0);
    int l=0,r=-1;
    for(int i=0; i<n; i++)
    {
        int k=0;
        if (i<=r) k=min(r-i,d1[l+r-i]);
        while (i+k+1<n && i-k-1>=0 && s[i+k+1]==s[i-k-1]) k++;
        d1[i]=k;
        if (i+k>r)
        {
            l=i-k;
            r=i+k;
        }
    }

    for(int i=0; i<n; i++) ans+=(int64_t)d1[i];
}


void calc_2()
{
    vector<int> d2(n,0);
    int l=0,r=-1;
    for(int i=0; i<n; i++)
    {
        int k=0;
        if (i<=r) k=min(d2[l+r-i+1],r-i+1);
        while (i+k+1<n && i-k-1>=0 && s[i+k]==s[i-k-1]) k++;
        d2[i]=k;
        if (i+k-1>r)
        {
            l=i-k;
            r=i+k-1;
        }
    }

    //for(int i=0; i<n; i++) ans+=(int64_t)d2[i];
    //for(auto x:d2) cout<<x<<' ';
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    n=s.size();
    calc_1();
    calc_2();


    return 0;
}
