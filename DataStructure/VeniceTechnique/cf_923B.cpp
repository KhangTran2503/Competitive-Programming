/*	2021-06-24	 */
#include <bits/stdc++.h>
//#include "VeniceSet.h"
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int N;

template<class Type>
class VeniceSet{
	private:
		std::multiset<Type> S;
		Type water_level = static_cast<Type>(0);
	public:
		VeniceSet(){};
		~VeniceSet(){};
		void add(Type val){
			S.insert(val + water_level);
		}
		
		void remove(Type val){
			S.erase(S.find(val + water_level));
		}
		
		void updateAll(Type val){
			water_level += val;
		}
		
		Type getmin(){
			return (*S.begin()) - water_level;
		}
		
		int size(){
			return (int)S.size();
		}
};



int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	vector<ll> V(N + 1);
	vector<ll> T(N + 1);
	
	for (int i = 1; i <= N; i++) cin >> V[i];
	for (int i = 1; i <= N; i++) cin >> T[i];
	
	VeniceSet<ll> vset;
	for (int i = 1; i <= N; i++){
		vset.add(V[i]);
		vset.updateAll(T[i]);
		
		ll ansi = T[i]*(ll)vset.size();
		
		
		
		while (vset.size() > 0){
			ll delta = vset.getmin();
			if (delta >= 0) break;
			ansi -= llabs(delta);
			vset.remove(delta);
		}
		cout << ansi << ' ';
	}
	return 0;
}
