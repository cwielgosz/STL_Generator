#pragma once
#include <iostream>
#include <cmath>


class Vec3d {
private:
    double x,y,z;
public:
    Vec3d(double x = 0, double y = 0, double z = 0);            // CONSTRUCTOR
    Vec3d (const Vec3d& orig);                                  // COPY CONSTRUCTOR
    Vec3d& operator=(const Vec3d& orig);                         // OPERATOR EQUAL

    double dot(const Vec3d& b) const;
    double dist(const Vec3d& b)const;

    friend Vec3d operator*(const Vec3d& a, double s);
    friend Vec3d operator*(double s, const Vec3d& a);
    friend Vec3d operator +(const Vec3d& a, const Vec3d& b);
    friend Vec3d operator -(const Vec3d& a, const Vec3d& b);
    friend double dot(const Vec3d& a, const Vec3d& b);
    friend double dist(const Vec3d& a, const Vec3d& b);
    friend std::ostream& operator << (std::ostream& s, const Vec3d& a);
};
