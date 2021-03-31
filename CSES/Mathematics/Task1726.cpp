#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};
int k;
ld neg_P[8][8][101];
ld P[8][8];


void init_P(){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) P[i][j] = 1.0;
}
void init_negP(){
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int step = 0; step <= k; step++) neg_P[i][j][step] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k;
    //cout << k << '\n';
    init_P();
    ld EV = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            init_negP();
            neg_P[i][j][0] = 1.0;
            for (int step = 0; step < k; step++){
                
                for (int u = 0; u < 8; u++)
                    for (int v = 0; v < 8; v++){
                        //ld sumdir = 0;
                        int can_move = 0;
                        for (int dir = 0; dir < 4; dir++){
                            int uu = u + dx[dir];
                            int vv = v + dy[dir];
                            if (uu >= 0 && uu < 8 && vv >= 0 && vv < 8){
                                can_move++;
                                //sumdir += neg_P[uu][vv][step - 1];
                            }
                        }

                        for (int dir = 0; dir < 4; dir++){
                            int uu = u + dx[dir];
                            int vv = v + dy[dir];
                            if (uu >= 0 && uu < 8 && vv >= 0 && vv < 8){
                                neg_P[uu][vv][step + 1] += (neg_P[u][v][step]/(double)can_move);
                            }
                        }

                    }
            }

            
            for (int u = 0; u < 8; u++)
                for (int v = 0; v < 8; v++)
                    P[u][v] *= (1 - neg_P[u][v][k]);
        }
    

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) 
            EV += P[i][j];
    cout << fixed << setprecision(6) << EV;
    return 0;
}
