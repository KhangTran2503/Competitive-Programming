#include <bits/stdc++.h>
using namespace std;
int n;

void solve(){
    int n;
    cin >> n;
    int N = n*n;
    if (N == 1){
        cout << 1 << '\n';
        return;
    }
    int step = 0;
    for (int i = 2; i < N - 1; i++)
        if (__gcd(i,N) == 1){
            step = i;
            break;
        }
    if (step == 0){
        cout << -1 << '\n';
        return;
    }
    int start = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (start == 0) start = N;
            cout << start << ' ';
            start = (start + step) % N;
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
