#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2*int(1e6) + 5;
int n;
int t;
vector<int> a;

int check(int s){
    int sum = 0;
    for (int i = 0; i < n; i++){
        int li = a[i]/(s + 1) + (a[i] % (s + 1) != 0);
        int ri = a[i]/s;
        if (li <= ri) sum += li;
        else return int(1e9);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        
        cin >> n;
        vector<int> cnt(n + 1,0);
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        a.clear();
        for (int i = 0; i <= n; i++) 
            if (cnt[i]) a.push_back(cnt[i]);
        n = a.size();
        int mina = *min_element(a.begin(),a.end());
        int ans = int(1e9);
        //int sqrt_a = sqrt(mina + 1);
        for (int s = 1; s <= mina + 1; s++){
            ans = min(ans,check(s));
        }    
        cout << ans << '\n';    
    }
    return 0;
}