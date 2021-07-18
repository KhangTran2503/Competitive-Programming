/*	2021-07-18	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

bool colinear(const ii& A,const ii& B,const ii& C){
	ii AB(B.first - A.first,B.second - A.second);
	ii BC(C.first - B.first,C.second - B.second);
	return (BC.first*AB.second == BC.second*AB.first);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<ii> p(n);
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++) 
				if (colinear(p[i],p[j],p[k])){
					cout << "Yes";
					goto End;
				}
		
	cout << "No";		
End:
	return 0;
}
