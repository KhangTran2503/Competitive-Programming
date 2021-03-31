#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
using namespace std;
int t;



int min2(int a,int b,int c)
{
    vector<int> v;
    v.push_back(a); v.push_back(b); v.push_back(c);
    sort(all(v));
    return v[1];

}
//=============================
int main()
{

    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<i<<": "<<min2(a,b,c)<<'\n';
    }
    return 0;
}
