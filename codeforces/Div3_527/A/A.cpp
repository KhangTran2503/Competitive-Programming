#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        int d = n/k;
        int r = n%k;
        for (int i = 1; i<= k; i++){
            for(int j=1; j<=d; j++) cout<<char(i+int('a')-1);
        }

        for(int i = 1; i<=r; i++) cout<<char(i+int('a')-1);
        cout<<'\n';

    }
    return 0;
}
