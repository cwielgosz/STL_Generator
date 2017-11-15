#include "Vec3d.h"
#include <iostream>
#include <cmath>
using namespace std;

Vec3d:: Vec3d(double x , double y , double z ):x(x),y(y),z(z){}             // CONSTRUCTOR

Vec3d :: Vec3d (const Vec3d& orig):x(orig.x), y(orig.y), z(orig.z){}                  // COPY CONSTRUCTOR

Vec3d& Vec3d::operator =(const Vec3d& orig){                                         // OPERATOR =
    Vec3d copy(orig);
    swap(copy.x,x);
    swap(copy.y,y);
    swap(copy.z,z);
}

double Vec3d::dot(const Vec3d& b) const{
    return x * b.x + y * b.y + z * b.z;}

double Vec3d::dist(const Vec3d& b)const{
    return sqrt(((*this)-b).dot((*this)-b));}


Vec3d operator*(const Vec3d& a, double s){
    return Vec3d (a.x*s, a.y*s, a.z*s);}

Vec3d operator*(double s, const Vec3d& a){
    return a*s;}

Vec3d operator +(const Vec3d& a, const Vec3d& b){
    return Vec3d (a.x + b.x, a.y + b.y, a.z + b.z);}

Vec3d operator -(const Vec3d& a, const Vec3d& b){
    return Vec3d (a.x-b.x, a.y-b.y, a.z-b.z);}

double dot(const Vec3d& a, const Vec3d& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;}

double dist(const Vec3d& a, const Vec3d& b){
    return sqrt(dot(a-b,a-b));}

ostream& operator << (ostream& s, const Vec3d& a){
    s << a.x << ',' << a.y << ',' << a.z << '\n';
    return s;}