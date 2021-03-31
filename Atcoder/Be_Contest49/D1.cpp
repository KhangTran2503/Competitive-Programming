// Greedy
#include <bits/stdc++.h>
using namespace std;
int n, k, R, S, P;
string T;
string v;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> R >> S >> P;
    cin >> T;
    
    int ans = 0;
    for (int i = 0; i < k; i++){
        if (T[i] == 'r'){
            ans += P;
            v.push_back('p');
        }
        if (T[i] == 'p'){
            ans += S;
            v.push_back('s');
        }
        if (T[i] == 's'){
            ans += R;
            v.push_back('r');
        }
    }

    for (int i = k; i < n; i++){
        if (T[i] == 'r'){
            if (v[i - k] != 'p'){
                ans += P;
                v.push_back('p');
            }
            else v.push_back('?');    
        }
        if (T[i] == 'p'){
            if (v[i - k] != 's'){
                ans += S;
                v.push_back('s');
            }
            else v.push_back('?');    
        }
        if (T[i] == 's'){
            if (v[i - k] != 'r'){
                ans += R;
                v.push_back('r');
            }
            else v.push_back('?');    
        }
    }
    cout << ans;
    return 0;
}