#include <iostream>
#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n,k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    vector<int> res;
    int rr=oo;
    for(int i=1; i<=min(k+1,n); i++)
    {
        vector<int> r;
        int j=i+k;
        r.push_back(i);
        if (j>=n)
        {
            res=r;
            break;
        }
        j++;
        while (j+k<=n)
        {
           r.push_back(j+k);
           if (j+2*k>=n) break;
           j+=2*k;
           j++;

        }
        if (j+k<=n && rr>=r.size() && r.size()!=0)
        {
            rr=r.size();
            res=r;
        }
    }
    cout<<res.size()<<'\n';
    for(int i=0; i<res.size(); i++) cout<<res[i]<<' ';
    return 0;
}
