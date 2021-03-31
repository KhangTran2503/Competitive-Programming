/*********************
 * @author: I_Love_Thuy_Linh
 *
 *********************/

#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int H, W, M;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W >> M;
    //vector<vector<int>> grid(H,vector<int> (W,0));
    vector<int> row(H);
    vector<int> col(W);
    map<pair<int,int>,int> grid;
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        grid.insert(pair<pair<int,int>,int>({x,y},1));
        row[x]++;
        col[y]++;
    }
    
    int max_row = *max_element(all(row));
    int max_col = *max_element(all(col));

    vector<int> row_idx;
    vector<int> col_idx;

    for (int i = 0; i < H; i++) 
        if (row[i] == max_row) row_idx.emplace_back(i);

    for (int i = 0; i < W; i++)
        if (col[i] == max_col) col_idx.emplace_back(i);


    for (int r: row_idx)
        for (int c: col_idx)
            if (grid.find(pair<int,int>(r,c)) == grid.end()){
                cout << max_row + max_col;
                return 0;
            }
   cout << max_row + max_col - 1;
    return 0;
}
