#include <bits/stdc++.h>
#define N 3*int(1e5)+5
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll Mod=ll(1e9)+11;
const ll base1=500011;
const ll base2=777777;
ii Pow[N],Hash[N],rHash[N];
string s;
int len1,len2,n;

void init()
{
    Pow[0]=ii(1,1);
    for (int i=1; i<=n; i++) {
            Pow[i].first=(Pow[i-1].first*base1);
            Pow[i].second=(Pow[i-1].second*base2)%Mod;
    }
    Hash[0]=rHash[n+1]=ii(0,0);
    for(int i=1; i<=n; i++) {
            Hash[i].first=(Hash[i-1].first*base1+s[i-1]);
            Hash[i].second=(Hash[i-1].second*base2+s[i-1])%Mod;
    }
    for(int i=n; i>=1; i--) {
            rHash[i].first=(rHash[i+1].first*base1+s[i-1]);
            rHash[i].second=(rHash[i+1].second*base2+s[i-1])%Mod;
    }
}

ii gethash(int l,int r)
{
     ll tmp1=(Hash[r].first-Hash[l-1].first*Pow[r-l+1].first);
     ll tmp2=(Hash[r].second-Hash[l-1].second*Pow[r-l+1].second+Mod*Mod)%Mod;
     return ii(tmp1,tmp2);
}
ii getrhash(int l,int r)
{
    ll tmp1=(rHash[l].first-rHash[r+1].first*Pow[r-l+1].first);
    ll tmp2=(rHash[l].second-rHash[r+1].second*Pow[r-l+1].second+Mod*Mod)%Mod;
    return ii(tmp1,tmp2);
}
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>s;
    n=s.size();
    init();
    for(int i=n; i>=1; i--)
       if (Hash[i]==getrhash(1,i))
       {
           len1=i;
           break;
       }

    for(int i=1; i<=n; i++)
        if (rHash[i]==gethash(i,n)){
            len2=n-i+1;
            break;
        }

    string t;
    if (len1>=len2){
       if (len1==n) cout<<s;
       else{
            t=s.substr(len1,n-len1);
            reverse(t.begin(),t.end());
            cout<<t<<s;
       }
    }
    else{
        if (len2==n) cout<<s;
        else
        {
            t=s.substr(0,n-len2);
            reverse(t.begin(),t.end());
            cout<<s<<t;
        }
    }
    return 0;
}
