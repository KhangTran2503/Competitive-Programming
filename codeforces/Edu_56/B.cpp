#include<bits/stdc++.h>
using namespace std;
int t;

int check(string x){
    int n=x.size();
    for (int i=0; i<n; i++)
        if (a[i]!=a[n-1-i]) return false;
    return true;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int n=s.size();
        if (check(s)) cout<<s<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
