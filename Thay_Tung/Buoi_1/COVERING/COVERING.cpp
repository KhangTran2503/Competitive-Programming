///  Cho n doan thang, doan thu i co diem dau va diem cuoi la a,b
///  Hay xac dinh so luong it nhat cac diem can chon de moi doan thang da cho chua it nhat mot diem
///  trong so da chon
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,bool,int> tup;
int n;

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    vector<tibi> x(2*n);
    vector<int> flat(n,0);
    for(int i=0; i<=n; i++)
    {
        cin>>a>>b;
        x[2*i]=make_tuple(a,0,i);
        x[2*i+1]make_tuple(b,1,i);
    }
    sort(x.begin(),x.end());
    vector<int> v(n);
    int pv=0;
    for(int i=0; i<2*n; i++)
    {
       tie(a,c,m)=x[i];
       if (c==0) v[pv++]=m; ///neu la doan mo dau
       if (c && (flat[m]==0))/// la doan  dong va chua danh dau
       {
           for(int j=0; j<pv; j++) flat[v[j]]=true;///loai het nhung phan tu co mo doan vi da co dai dien
           flat[m]=1;
           ans++;
           pv=0;
       }
    }
    return 0;
}
