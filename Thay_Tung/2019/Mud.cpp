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
#define sqr(x) (db)(x)*(db)(x)
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (db)(1e100)
#define delta (db)1e-16 + 5e-17
using namespace std;
const db Pi = acos(-1);

struct Point
{
    db x,y;
    Point(db _x,db _y) : x(_x), y(_y) {}
    Point operator+ (Point const& other) const{
        return Point(x + other.x, y + other.y);
    }
    Point operator- (Point const& other) const{
        return Point(x - other.x, y - other.y);
    }
    db len() const{
        return (db) x*x + (db)y*y;
    }
    bool operator< (Point const& other) const{
        return (x < other.x || (x == other.x && y < other.y));
    }
};
int n, a ,b;


db p_scalar(Point const& p1, Point const &p2){   // tich cheo
    return (db)p1.x*(db)p2.y - (db)p2.x *(db)p1.y;
}

db scalar(Point const& p1, Point const &p2){
    return (db)p1.x*(db)p2.x + (db)p1.y*(db)p2.y;
}

db get_dist(Point const& a,Point const& b, Point const& c){
    if (scalar(b - a,c - a) < 0 || scalar(a - b, c - b) < 0)
        return min((c-a).len(), (c - b).len());
    return (db)sqr((db)p_scalar(b - a, c- a)) / (db)(b - a).len()) + delta;
}

db calc_dist(vector<Point> const& poly_1, vector<Point> const& poly_2){
    int c1 = 0, c2 = 0;
    Point Cur = poly_1[0] + poly_2[0];
    db ans = oo;
    while (c1 < sz(poly_1) || c2 < sz(poly_2)){
        Point shift(0,0);
        int next_1 = c1 + 1;
        if (next_1 == sz(poly_1)) next_1 = 0;
        int next_2 = c2 + 1;
        if (next_2 == sz(poly_2)) next_2 = 0;

        if (c1 == sz(poly_1) || (c2 != sz(poly_2) && p_scalar(poly_1[next_1] - poly_1[c1],poly_2[next_2] - poly_2[c2]) < 0)){
            shift = poly_2[next_2] - poly_2[c2];
            c2 ++;
        }
        else {
            shift = poly_1[next_1] - poly_1[c1];
            c1 ++;
        }
        ans = min(ans, get_dist(Cur, Cur + shift, Point(0,0)));
        Cur = Cur + shift;
    }
    return (db)ans + delta;
}

void Dijkstra(vector<vector<db>> graph, vector<vector<Point>> _polys, vector<vector<Point>> _ipolys){
    vector<db> dist(n,oo);
    dist[a] = 0;
    vector<bool> used(n,0);
    for (int i = 0; i < n; i++){
        int mem = -1;
        for (int j = 0; j < n; j++)
            if (!used[j])
                if (mem == -1 || dist[mem] > dist[j]) mem = j;
        used[mem] = true;

        if (mem == b){
            cout << prec(15) << (db)sqrt(dist[b]) + delta;
            return;
        }

        for (int j = 0; j < n; j++){
            if (graph[mem][j] == 0)
                graph[mem][j] = graph[j][mem] = calc_dist(_polys[mem],_ipolys[j]);
            dist[j] = min(dist[j], dist[mem] + graph[mem][j]);
        }


    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> a >> b;
    a --, b --;
    vector<vector<Point>> polys;
    vector<vector<Point>> i_polys;
    vector<vector<db>> graph(n, vector<db> (n));

    for (int i = 0; i < n; i++){
        polys.pb({});
        i_polys.pb({});
        int k;
        cin >> k;
        int mem = 0, i_mem = 0;
        for (int j = 0; j < k; j++){
            db x,y;
            cin >> x >> y;
            polys.back().pb(Point(x,y));
            i_polys.back().pb(Point(-x,-y));
            if (polys[i][j] < polys[i][mem]) mem = j;
            if (i_polys[i][j] < i_polys[i][i_mem]) i_mem = j;
        }
        rotate(polys[i].begin(),polys[i].begin() + mem, polys[i].end());
        rotate(i_polys[i].begin(),i_polys[i].begin() + i_mem, i_polys[i].end());
    }

    Dijkstra(graph,polys,i_polys);

    return 0;
}
