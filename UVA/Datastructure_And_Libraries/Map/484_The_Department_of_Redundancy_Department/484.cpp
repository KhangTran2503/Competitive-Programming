#include <bits/stdc++.h>
using namespace std;
map<int,int> d;
vector<int> a;
int x;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    while(cin>>x)
    {
        a.push_back(x);
        d[x]++;
    }
    for(int i=0; i<a.size(); i++)
        {
            int tmp=d[a[i]];
            if (tmp!=0)
            {
                cout<<a[i]<<' '<<tmp<<'\n';
                d[a[i]]=0;
            }

        }
    return 0;
}
