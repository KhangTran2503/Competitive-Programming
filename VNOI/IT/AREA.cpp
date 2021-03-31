    /*    ####################  */
    /*   # I_LOVE_THUY_LINH #  */
    /*  ####################  */
    #include <bits/stdc++.h>
    #define ll long long
    #define db double
    #define ld long double
    #define ii pair<int,int>
    #define pb push_back
    #define eb emplace_back
    #define vi vector<int>
    #define vii vector<ii>
    #define matrix vector<vector<ll>>
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
    #define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
    #define gcd(a,b) __gcd(a,b)
    using namespace std;
    const int INF = int(1e9);
    const int Maxn = 3*int(1e4) + 5;
    int n;

    struct event{
        int u;
        int v1,v2, Time;
        event(){}
        event(int _u,int _v1,int _v2,int _Time): u(_u), v1(_v1), v2(_v2), Time(_Time){}
        bool operator < (const event& other) const{
            return make_tuple(u,Time,v1,v2) < make_tuple(other.u,other.Time,other.v1,other.v2);
        }
        ~event(){}
    };
    struct Node{
        int len, cnt; // do dai va so luong hcn chong nhau
        Node(){
            len = 0;
            cnt = 0;
        }
        Node(int _len,int _cnt): len(_len), cnt(_cnt){}
        ~Node(){}
    };
    vector<event> ev;
    vector<Node> seg(4*Maxn);


    void update(int id,int l,int r,int u,int v,int type){
        if (r < u || l > v || l > r || u > v) return;
        if (u <= l && r <= v){
            seg[id].cnt += type;
            if (seg[id].cnt > 0) seg[id].len = r - l + 1;
            else {
                if (l != r) seg[id].len = seg[2*id].len + seg[2*id + 1].len;
                else seg[id].len = 0;
            }
            return;
        }
        int mid = (l + r) >> 1;
        update(2*id,l,mid,u,v,type);
        update(2*id + 1,mid + 1,r,u,v,type);
        
        if (seg[id].cnt == 0) seg[id].len = seg[2*id].len + seg[2*id + 1].len;
    }


    void SweepLine(){
        sort(all(ev));
        ll ans = 0;
        for (int i = 0; i < sz(ev) -1 ; i++){
            int type = ev[i].Time;
            int v1 = ev[i].v1;
            int v2 = ev[i].v2;
            //cout << ev[i].u << ' ' << v1 << ' ' << v2 << '\n';
            update(1,1,Maxn,v1,v2,type);
            ans += (ll)seg[1].len*(ll)(ev[i + 1].u - ev[i].u);
            //cout << seg[1].len << '\n';
        }
        cout << ans;
    }

    int main(){
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cin >> n;
        for (int i = 0; i < n; i++){
            int u1, v1, u2, v2;
            cin >> u1 >> v1 >> u2 >> v2;
            ev.pb({u1,v1 + 1,v2,1}); // chuyen diem thanh o
            ev.pb({u2,v1 + 1,v2,-1});
        }

        SweepLine();
    
        return 0;
    }