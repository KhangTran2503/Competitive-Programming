#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int d[30];

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        memset(d,0,sizeof(d));
        priority_queue<int> pq;
        string t="";
        for(int j=i; j<s.size(); j++)
        {
            t+=s[j];
            d[s[j]-'a']++;
            pq.push(d[s[j]-'a']);
            if (pq.top()<=(j-i+1)/2)
            {
                cout<<"YES\n";
                cout<<t;
                return 0;
            }

        }
    }
    cout<<"NO";
    return 0;
}
