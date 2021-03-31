#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int n,a,b;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n>>a>>b;

    int Final=int(log2(n));
    int res=0;
    for(int i=1; i<=n; i++) d.push_back(i);
    for(res=1; res<=Final; res++)
    {
        vector<int> B;
        for(int i=0; i<d.size(); i+=2)
        {
            if ((d[i]==a && d[i+1]==b) || (d[i]==b && d[i+1]==a))
            {
                if (res==Final) cout<<"Final";
                else
                cout<<res;
                return 0;
            }
            if (d[i]==a || d[i+1]==a) B.push_back(a);
            else if (d[i]==b || d[i+1]==b) B.push_back(b);
            else B.push_back(d[i]);
        }
        d=B;
    }
    return 0;
}
