#include<bits/stdc++.h>
using namespace std;
string s,ans;
int n,k;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>k;
    cin>>s;
    int pos=1,cnt=1;
    ans=s;
    while (cnt<k)
    {
        if (pos>=ans.size())
        {
            ans+=s;
            cnt++;
        }
        else
        {
            bool ok=true;
            int len=0;
            for(int i=0; i<s.size(); i++)
            {
                if (pos+i>=ans.size()) break;
                len++;
                if (ans[pos+i]!=s[i]) ok=false;
            }
            if (ok)
            {
                ans+=s.substr(len);
                cnt++;
            }
        }
        pos++;
    }
    cout<<ans;
    return 0;
}
