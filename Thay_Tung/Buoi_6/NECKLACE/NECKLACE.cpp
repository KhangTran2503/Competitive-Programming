///??????????/// Bai Mau
#include <bits/stdc++.h>
using namespace std;
vector<int> white;
vector<int> black;
vector<vector<int>> ans;
string s;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0; i<n; i++)
    {
        if (s[i]=='0')
        {
            if (!black.empty())
            {
                ans[black.back()].push_back(i);
                white.push_back(black.back());
                black.pop_back();
            }
            else
            {
                white.push_back(ans.size());
                ans.push_back(vector<int> (1,i));
            }
        }
        else
        {
            if (white.empty())
            {
                cout<<0;
                return 0;
            }
            ans[white.back()].push_back(i);
            black.push_back(white.back());
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].size()<<' ';
        for(int j=0; j<ans[i].size(); j++)
          cout<<ans[i][j]+1<<' ';
        cout<<'\n';
    }
    return 0;
}
