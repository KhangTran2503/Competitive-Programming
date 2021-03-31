#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tibi;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<tibi> s;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        s[2*i]=make_tuple(x,0,i);
        s[2*i+1]=make_tuple(y,1,i);
    }
    sort(s.begin(),s.end());

    vector<int> ans(n,0);
    int a,tx,t,id,q=-1;
    for(int i=0; i<s.size(); i++)
    {
        tie(a,t,id)=s[i];
        if (t==0)
        {
            if (id>q && q>=0)
            {
                ans[q]=2;
                mx.push(q);
                q=id;
                continue;
            }
            if (id>q && q<0)
            {
                tx=-1;
                while (!mx.empty() && ans[mx.top()]==1) mx.pop();
                if (!mx.empty()) tx=mx.top();
                if (id>tx)
                {
                    q=id;
                    continue;
                }
            }
            mx.push(id); ans[id]=2; continue;
        }
        else
        {
            if (id==q)
            {
                q=-1;
                continue;
            }
            else ans[id]=1;
        }
    }

    x=n;
    for(int i=0; i<ans.size(); i++)
    {
        x-=ans[i];
        cout<<x<<'\n';
    }
    return 0;
}
