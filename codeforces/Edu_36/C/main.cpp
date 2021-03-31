#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define Name "Test"
using namespace std;
ll a,b;
vector<int> A,B;
int cnt[20];
vector<int> ans;

void dq(int pos,int tight)
{
    if (pos==-1)
    {
         for(int i=0; i<ans.size(); i++) cout<<ans[i];
         exit(0);
    }
    int hi=9;
    if (tight) hi=B[pos];
    for(int j=hi; j>=0; j--)
    if (cnt[j])
    {
        cnt[j]--;
        ans.push_back(j);
        dq(pos-1,tight&(j==hi));
        ans.pop_back();
        cnt[j]++;
    }
}

//================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
   cin>>a>>b;
    while (a)
    {
        A.push_back(a%10);
        a/=10;
    }

    while (b)
    {
        B.push_back(b%10);
        b/=10;
    }
    sort(A.begin(),A.end());
    if (A.size()<B.size())
    {
        for(int i=A.size()-1; i>=0; i--) cout<<A[i];
    }
    else
       {
           for(int i=0; i<A.size(); i++) cnt[A[i]]++;
           dq(B.size()-1,1);
       }

    return 0;
}
