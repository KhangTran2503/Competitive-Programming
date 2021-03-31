#include <bits/stdc++.h>
using namespace std;
map<string,int> d;
int Count=0;

void gen(int step,int pre,int cnt,string s)
{
    for(int i=pre+1; i<=26; i++)
    {
        string tmp=s+char(i+'a'-1);
        if (step==cnt) d[tmp]=++Count;
        else gen(step+1,i,cnt,tmp);
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    for(int i=1; i<=5; i++)
      gen(1,0,i,"");

    string a;
    while(cin>>a)
        cout<<d[a]<<'\n';
    return 0;
}
