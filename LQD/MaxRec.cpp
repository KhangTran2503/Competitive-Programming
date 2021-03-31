#include <bits/stdc++.h>
#define N int(1e6)+5
using namespace std;
typedef long long ll;
vector<int> a(N),b(N);
int m, n;

ll calc(const vector<int>& arr){
    deque<int> dq;
    vector<int> l(N), r(N);
    dq.push_back(0);
    for (int i=1; i<=n; i++)
    {
         while(!dq.empty() && arr[i]<=arr[dq.back()]) dq.pop_back();
         l[i]=dq.back()+1;
         dq.push_back(i);
    }
    dq.clear();
    dq.push_back(n+1);
    for (int i=n; i>=1; i--)
    {
         while (!dq.empty() && arr[i]<=arr[dq.back()]) dq.pop_back();
         r[i]=dq.back()-1;
         dq.push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) 
        ans = max(ans,(ll)(r[i] - l[i] + 1)*(ll)(arr[i]));
    return ans;

} 
 
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>m >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = m - a[i];
    }
    a[0] = b[0] = -1;
    a[n + 1] = b[n + 1] = -1;
    cout << max(calc(a),calc(b));
    return 0;
}
 
