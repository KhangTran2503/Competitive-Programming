///kiem tra l-> r co tao dc hay ko
///nguoc lai r->l
#include<bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int n;
int a[N];

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    stack<int> st1;
    stack<int> st2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok1 = true, ok2 = true;
    for(int i = 1; i <= n; i++){
        if (!st1.empty()){
            if (a[i] == st1.top()){
                st1.pop();
                continue;
            }
            if (a[i] < st1.top()) {
                st1.push(a[i]);
                continue;
            }
            if (a[i] > st1.top()){
                ok1 = false;
                break;
            }
        }
        else st1.push(a[i]);
    }

    ok1&=(st1.size() < 2);

    for(int i = n; i >= 1; i--){
        if (!st2.empty()){
            if (a[i] == st2.top()){
                st2.pop();
                continue;
            }
            if (a[i] < st2.top()) {
                st2.push(a[i]);
                continue;
            }
            if (a[i] > st2.top()){
                ok2 = false;
                break;
            }
        }
        else st2.push(a[i]);
    }
    ok2&=(st2.size() < 2);
    if (ok1 && ok2) cout << "YES";
    else cout << "NO";
}
