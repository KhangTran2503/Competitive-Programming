#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

bool check(int p){
    for (int i = 0; i < n; i++)
        if (abs(a[(p + i) % n] - (i + 1)) > 1) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &x: a) cin >> x;
    
    //int min_x = *min_element(a.begin(),a.end());
    
    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] == 0 || a[i] == 1 || a[i] == 2) pos.emplace_back(i);

    for (int p: pos){
       if (check(p)){
            cout << "YES\n" << p + 1;
            return 0;
       }
    }
    cout << "NO";

    return 0;
}
