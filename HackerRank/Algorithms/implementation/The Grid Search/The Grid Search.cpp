///HashR[i][j] la dong i tao Hash cot j
///HashC[i][j] la cot j tao Hash dong i
///
#include <iostream>
#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long ll;
const ll Mod=ll(1e9)+11;
ll HashR[N][N],HashC[N][N],P[1000005];
ll b[1005],HashM;
char a[N][N];
int R,C,r,c,t;

void init(){
    P[0]=1;
    for(int i=1; i<=1000000; i++) P[i]=(P[i-1]*311)%Mod;

}
void Clear(){
    memset(HashC,0,sizeof(HashC));
    memset(HashR,0,sizeof(HashR));
    //memset(P,0,sizeof(P));
}

ll getHashR(int pos,int u,int v){
    return (HashR[pos][v]-HashR[pos][u-1]*P[v-u+1]+Mod*Mod)%Mod;
}

ll getHashC(int pos,int u,int v){
    return (HashC[v][pos]-HashC[u-1][pos]*P[(v-u+1)*c]+Mod*Mod)%Mod;
}

void up(){
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++) HashR[i][j]=(HashR[i][j-1]*311+(ll)(a[i][j]-'0'))%Mod;

    for(int j=1; j<=C-c+1; j++)
       for(int i=1; i<=R; i++) HashC[i][j]=(HashC[i-1][j]*P[c]+getHashR(i,j,j+c-1))%Mod;


}

bool check(){
    for (int i=1; i<=R-r+1; i++)
        for(int j=1; j<=C-c+1; j++)
            if (getHashC(j,i,i+r-1)==HashM) return true;
    return false;
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>t;
    init();
    while (t--){
        cin>>R>>C;
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++) cin>>a[i][j];
        cin>>r>>c;
        for(int i=1; i<=r; i++){
            ll tmp=0;
            for(int j=1; j<=c; j++){
                char x;
                cin>>x;
                tmp=(tmp*311+(ll)(x-'0'))%Mod;
            }
            b[i]=tmp;
        }

        HashM=0;
        for(int i=1; i<=r; i++) HashM=(HashM*P[c]+b[i])%Mod;

        up();
        if (check()) cout<<"YES\n";
        else cout<<"NO\n";
        Clear();


    }
    return 0;
}
