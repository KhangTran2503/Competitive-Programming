///Dung 2 cay heap min,max
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pqmax;
priority_queue<int, vector<int> ,greater<int> > pqmin;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if (pqmax.empty() || pqmax.top()>=x) pqmax.push(x);
        else pqmin.push(x);
        while (pqmax.size()>pqmin.size()){
            pqmin.push(pqmax.top());
            pqmax.pop();
        }
        while(pqmax.size()<pqmin.size()){
            pqmax.push(pqmin.top());
            pqmin.pop();
        }
        if (i&1) cout<<fixed<<setprecision(1)<<pqmax.top()*1.0<<'\n';
        else cout<<fixed<<setprecision(1)<<(pqmax.top()+pqmin.top())/2.0<<'\n';

    }
    return 0;
}
