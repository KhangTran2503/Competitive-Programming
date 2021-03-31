#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll maxn = 1e6+5;
const ll maxint = 1e9+7;

ll n, SQRT;

struct fenwick
{
    ll BIT[maxn];
    inline void Update (ll index, ll val)
    {
        if (!index) return;
        while (index<=n)
        {
            BIT[index] += val;
            index += index & -index;
        }
    }
    inline ll Query (ll index)
    {
        ll ret = 0;
        while (index>0)
        {
            ret += BIT[index];
            index -= index & -index;
        }
        return ret;
    }
} fenwick;

struct query
{
    ll low, high, id;
    bool operator < (const query &a) const
    {
        return low/SQRT<a.low/SQRT ||
        (low/SQRT==a.low/SQRT && high<a.high);
    }
    query () {}
    query (const ll &low, const ll &high, const ll &id)
    {
        this -> low = low;
        this -> high = high;
        this -> id = id;
    }
};

ll Q, ans[maxn], a[maxn];

vector <query> QR;

void Compress ()
{
    vector <ll> zip;
    for (ll i=1; i<=n; i++) zip.push_back(a[i]);
    sort(zip.begin(), zip.end()) ;
    zip.resize(distance(zip.begin(), unique(zip.begin(), zip.end())));
    for (ll i=1; i<=n; i++) a[i] = lower_bound(zip.begin(), zip.end(), a[i]) - zip.begin() + 1;
}

int main()
{
    //freopen("NGHICHTHE.INP", "r", stdin);
    //freopen("NGHICHTHE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>Q;
    for (ll i=1; i<=Q; i++)
    {
        ll low, high;
        cin>>low>>high;
        QR.push_back(query(low, high, i));
    }
    //********************
    Compress();
    SQRT = (ll)(sqrt(n)); sort(QR.begin(), QR.end());
    ll curLow = QR[0].low, curHigh = curLow - 1, curAns = 0;
    for (ll i=0; i<QR.size(); i++)
    {
        while (curLow<QR[i].low)
            curAns -= fenwick.Query(a[curLow]-1), fenwick.Update(a[curLow++], -1);
        while (curLow>QR[i].low)
            curAns += fenwick.Query(a[--curLow]-1), fenwick.Update(a[curLow], 1);
        while (curHigh>QR[i].high)
            curAns -= fenwick.Query(n) - fenwick.Query(a[curHigh]), fenwick.Update(a[curHigh--], -1);
        while (curHigh<QR[i].high)
            curAns += fenwick.Query(n) - fenwick.Query(a[++curHigh]), fenwick.Update(a[curHigh], 1);
        ans[QR[i].id] = curAns;
    }
    //********************
    for (ll i=1; i<=Q; i++)
        if (a[i]&1) cout<<"odd\n";
        else cout<<"even\n";
    return 0;
}
