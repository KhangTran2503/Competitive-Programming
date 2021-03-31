// Greedy
// same Trie O(30*n) , don't proof :'(
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll solve(const vector<ll> &x,int pos){
    if (pos == -1) return 0;
    vector<ll> zero;
    vector<ll> one;
    for (ll y: x)
        if ((y >> pos) & 1) one.emplace_back(y);
        else zero.emplace_back(y);
    
    if (one.empty()) return solve(zero,pos - 1);
    if (zero.empty()) return solve(one,pos - 1);
    return (1LL << pos) + min(solve(zero,pos - 1),solve(one,pos - 1)); 
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    cout << solve(a,29);
    return 0;
}