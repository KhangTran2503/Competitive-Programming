#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Sx, Sy, Gx, Gy;
	cin >> Sx >> Sy >> Gx >> Gy;
	double tana = (double)(Gy + Sy)/(double)(Gx - Sx);
	cout << fixed << setprecision(10) << (double)Sx + Sy/tana;
	//else cout << fixed << setprecision(6) << (double)Sx - Sy/tana;
	
	return 0;
}
