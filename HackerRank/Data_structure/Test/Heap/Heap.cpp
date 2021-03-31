/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);

class Heap{
    private :
        int Key[100005] = {0};
        int size = 0;
        int Par(int i){return (i - 1) >> 1;}
        int Left(int i){return 2*i + 1;}
        int Right(int i){return 2*i + 2;}
        void UpHeap(int pos){
            while (pos && Key[pos] > Key[Par(pos)]){
                swap(Key[pos],Key[Par(pos)]);
                pos = Par(pos);
            };
        }
        void DownHeap(int pos){
            while (1){
                int L = Left(pos);
                int R = Right(pos);
                int Maxpos = pos;
                if (L < size && Key[Maxpos] < Key[L]) Maxpos = L;
                if (R < size && Key[Maxpos] < Key[R]) Maxpos = R;
                if (Maxpos == pos) break;
                swap(Key[pos],Key[Maxpos]);
                pos  = Maxpos;
            }
        }



    public:
        bool Empty(){
            return (size == 0);
        }
        void Pop(){
            Key[0] = Key[size - 1];
            size --;
            DownHeap(0);
        }
        void Push(int x){
            Key[size ++] = x;
            UpHeap(size - 1);
        }
        int Top(){
            return Key[0];
        }
        int Size(){
            return size;
        }


};

int main() {
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int x;
    Heap pq;
    while (cin >> x){
        if (x == -2){
            cout << pq.Size() << '\n';
            while (!pq.Empty()){
                cout << pq.Top() << '\n';
                pq.Pop();
            }
            return 0;
        }
        if (x == -1){
            if (!pq.Empty()){
                int tmp = pq.Top();
                while (!pq.Empty() && pq.Top() == tmp) pq.Pop();
            }
        }
        if (x > 0){
            if (pq.Size() < 100000) pq.Push(x);
        }
    }

    return 0;
}
