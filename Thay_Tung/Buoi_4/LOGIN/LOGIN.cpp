///tam ok, ve can xem them
#include <bits/stdc++.h>
using namespace std;
int n;
unordered_set<string> s;
unordered_map<string,int> cnt;


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<string> pw(n);
    for(int i=0; i<n; i++)
    {
        cin>>pw[i];
        int m=pw[i].size();
        s.clear();
        for (int j=0; j<m; j++)
        {
            string curr;
            for(int k=j;k<m; k++)
            {
                curr.push_back(pw[i][k]);
                s.insert(curr);
            }
        }
        for (auto x: s) cnt[x]++;
    }
    int64_t ans=0;
    for(auto str: pw) ans+=(int64_t)cnt[str];
    cout<<ans-n;
    return 0;
}
