#include <bits/stdc++.h>
#define N 500005
using namespace std;
char gen[N];
int cnt[N][4] = {0};
int n;

int Find(int pos){
    int l =pos, r = n;
    int res = n + 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        int t1 = cnt[mid][0] - cnt[pos - 1][0];
        int t2 = cnt[mid][1] - cnt[pos - 1][1];
        int t3 = cnt[mid][2] - cnt[pos - 1][2];
        int t4 = cnt[mid][3] - cnt[pos - 1][3];
        if (t1 >= cnt[n][0] - n/4 && t2 >= cnt[n][1] - n/4 && t3 >= cnt[n][2] - n/4 &&t4 >= cnt[n][3] - n/4){
            res = t1 + t2 + t3 + t4;
            r = mid - 1;
        }
        else l = mid + 1;


    }
    return res;
}
/*
    cnt[i][k] la tong tien to luu so luong cac ATCG tu 1-> i moi loai
    so luong can them i -> j  = n - sigma(cnt[n][k]  - cnt[j][k] + cnt[i - 1][k])
    ma sigma cnt[n][k] = n => sigma cnt[j][k] - sigma cnt[i - 1][k]
    Voi dk: cnt[j][k] - cnt[i - 1][k] >= cnt[n][k] - n/4

    Ham tong tien to la ham tang => chat np tim j nho nhat sao cho thoa dk


*/


int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> gen[i];
    for (int i = 1; i <= n ; i++){
        for (int k = 0; k < 4; k++) cnt[i][k] += cnt[i - 1][k];
        if (gen[i] == 'C') cnt[i][0] ++;
        if (gen[i] == 'G') cnt[i][1] ++;
        if (gen[i] == 'A') cnt[i][2] ++;
        if (gen[i] == 'T') cnt[i][3] ++;
    };

    bool check = 1;
    for (int k = 0; k < 4; k++)
        check &= (cnt[n][k] == n/4);
    if (check){
        cout << 0;
        return 0;
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
        ans = min(ans ,Find(i));

    cout << ans;
    return 0;
}


/* Thuat O(n) two point
int ans = n;
int j = 1;
for (int i = 1; i <= n; i++){
    while (j < i && j <= n) j++;
    while (j <= n){
        if (check(i,j)){
          int t1 = cnt[j][0] - cnt[i - 1][0];
          int t2 = cnt[j][1] - cnt[i - 1][1];
          int t3 = cnt[j][2] - cnt[i - 1][2];
          int t4 = cnt[j][3] - cnt[i - 1][3];
          ans = min(ans, t1 + t2 + t3 + t4);
          break;
        }
        j ++;
    }
}
cout << ans;

*/
