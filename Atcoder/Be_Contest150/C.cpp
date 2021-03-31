#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> P(n);
    for (int &i: P) cin >> i;
    vector<int> Q(n);
    for (int &i: Q) cin >> i;

    vector<int> per(n);
    for (int i = 0; i < n; i++) per[i] = i + 1;
    int cnt = 0;
    int timeP = 0;
    int timeQ = 0;
    
    do{
        cnt++;
        if (per == P) timeP = cnt;
        if (per == Q) timeQ = cnt;
    }
    while (next_permutation(per.begin(),per.end()));
    cout << abs(timeQ - timeP);
    return 0;
}