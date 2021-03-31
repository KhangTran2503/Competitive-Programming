#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;
ll L,R;
int q;

int Cal(ll L,ll R)
{
   vector<ii> st;
   for(int k=2;k<=18; k++)
   {
      int l=ceil(pow(L,1.0/k)), r=floor(pow(R,1.0/k));
      if (l<=r && l>0) st.push_back(ii(l,r));
      else break;
   }
   if (st.empty()) return 0;
   sort(st.begin(),st.end());
   int bd=st[0].f, kt=st[0].s,res=0;
   for(int i=1; i<st.size(); i++)
   {
       if (st[i].f<=st[i-1].s) kt=st[i].s;
       else
       {
           res+=(kt-bd+1);
           bd=st[i].f; kt=st[i].s;
       }
   }
   res+=(kt-bd+1);
   return res;

}
//=====================================
int main()
{
   // cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>q;
    while (q--)
    {
        cin>>L>>R;
        cout<<Cal(L,R)<<'\n';
    }
    return 0;
}
