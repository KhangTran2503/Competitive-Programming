/* Use Rodrigues' rotation formula
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef double ftype;

struct point3d {
    ftype x;
    ftype y;
    ftype z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    
    bool operator == (const point3d &t){
		return tie(this->x,this->y,this->z) == tie(t.x,t.y,t.z);
	}
    
    ftype norm() const {
		return sqrt((this->x)*(this->x) + (this->y)*(this->y) + (this->z)*(this->z));
	}
    
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
    
    point3d& normalize(){
		ftype len = this->norm();
		*this = point3d(*this)/len;
		return *this;
	}
};

point3d operator*(ftype a, point3d b) {
    return b * a;
}


ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

ftype angle(point3d a,point3d b){
	return acos(dot(a,b)/a.norm()/b.norm());
}

void print_point(const point3d &u){
	cout << fixed << setprecision(10) << u.x << ' ' << u.y << ' ' << u.z << '\n';
}

point3d A, B, C;
int signA, signB, signC;

void solve(){
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	cin >> signA >> signB >> signC;
	
	A.z = sqrt(1 - A.x*A.x - A.y*A.y);
	if (signA == 0) A.z = -A.z;
	
	B.z = sqrt(1 - B.x*B.x - B.y*B.y);
	if (signB == 0) B.z = -B.z;
	
	C.z = sqrt(1 - C.x*C.x - C.y*C.y);
	if (signC == 0) C.z = -C.z;
	
	if (B == C){
		print_point(A);
		return;
	}
	// OP perpendicular to OB and OC
	point3d P = cross(B,C);
	P.normalize();
	
	// vector A = vector A_proj + vector A_reject
	point3d A_proj = dot(A,P)*P;
	//print_point(A_proj);
	
	point3d A_reject = A - A_proj;
	
	// w perpendicular v and OP
	point3d w = cross(P,A);
	
	// angle between OB, OC
	ftype cos_phi = dot(B,C)/B.norm()/C.norm();
	ftype sin_phi = cross(B,C).norm()/B.norm()/C.norm();
	
	// A'_reject  = rotate(A_reject,phi)
	point3d pA_reject = cos_phi*A_reject + sin_phi*w;
	
	// OA' = rotate(OA,phi) = A'_reject + A_proj
	point3d pA = pA_reject + A_proj;
	
	print_point(pA);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
