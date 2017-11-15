#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
const static double PI = 3.141592657;
//#include "Vec3d.h"
using namespace std;
class Shape {
private:
    double x, y, z;
public:
    Shape(double x, double y, double z) : x(x), y(y), z(z) {};
    virtual ofstream& write(ofstream& myfile) = 0;
    double getX() {return x;}
    double getY() {return y;}
    double getZ() {return z;}
    ofstream& drawTriangle(ofstream& ofile, vector<double> a , vector<double> b , vector<double> c) {
        ofile << "facet normal 0 0 0 \n" << "outer loop\n" ;
        ofile << "vertex " << a[0] << ' ' << a[1] <<' ' << a[2] << '\n';
        ofile << "vertex " << b[0] << ' ' << b[1] <<' ' << b[2] << '\n';
        ofile << "vertex " << c[0] << ' ' << c[1] <<' ' << c[2] << '\n';
        ofile << "endloop" << '\n' << "endfacet" << '\n' ;
    }
};

class Cube: public Shape {
private:
    double size;
public:
    Cube(double x, double y, double z, double size) : Shape(x, y, z), size(size) {};
    ofstream& write(ofstream& myfile) {
        vector<vector<double>> points;
       /* for (int i = 0; i < 5; i++) {
            points.push_back(
                    {getX() + size * sqrt(2) / 2 * cos(2 * PI / 4 * i), getY() + size * sqrt(2) / 2 * sin(2 * PI / 4 * i),  // points upper face
                     getZ() + size/2});
            points.push_back(
                    {getX() + size * sqrt(2) / 2 * cos(2 * PI / 4 * i), getY() + size * sqrt(2) / 2 * sin(2 * PI / 4 * i),  // points lowe face
                     getZ() - size/2});
            }*/
        for (int i = 0; i < 5; i++) {
            points.push_back(
                    {getX() + size * cos(2 * PI / 4 * i), getY() + size * sin(2 * PI / 4 * i),  // points upper face
                     getZ() + size*sqrt(2)});
            points.push_back(
                    {getX() + size * cos(2 * PI / 4 * i), getY() + size * sin(2 * PI / 4 * i),  // points lowe face
                     getZ()});
        }
        myfile << "solid cube\n";
        for (int i = 0; i < 2 * 4; i += 2) {
            drawTriangle(myfile, {getX() + size / 2, getY() + size / 2, getZ() + size*sqrt(2)}, points[i], points[i + 2]);
            drawTriangle(myfile, {getX() + size / 2, getY() + size / 2, getZ() }, points[i + 1], points[i + 3]);
        }

        for (int i = 0; i < 2*4 ; i++) {
            drawTriangle(myfile, points[i], points[i + 1], points[i + 2]);
        }
        myfile << "endsolid cube\n";
        return myfile;
    }


};


class Cylinder : public Shape{
private:
    double r, h;
    int facets;
public:
    Cylinder(double x, double y, double z, double r, double h, int facets): Shape(x, y, z), r(r), h(h), facets(facets) {} ;
    ofstream& write(ofstream& myfile) {
        vector<vector<double>> points;
        for(int i = 0; i <= facets; i++) {
            points.push_back({getX() + r*cos(2*PI/facets*i), getY() + r*sin(2*PI/facets*i), getZ() + h/2});
            points.push_back({getX() + r*cos(2*PI/facets*i), getY() + r*sin(2*PI/facets*i), getZ() - h/2});
        }
        myfile << "solid cylinder\n";
        for(int i = 0; i < 2*facets; i+=2){
            drawTriangle(myfile, {getX(), getY(), getZ() + h/2}, points[i], points[i+2]);
            drawTriangle(myfile, {getX(), getY(), getZ() - h/2}, points[i+1], points[i+3]);
        }

        for(int i = 0; i < 2*facets; i++){
            drawTriangle(myfile, points[i], points[i+1], points[i+2]);
        }
        myfile << "endsolid cylinder\n";
        return myfile;
    }


};



class CAD {
private:
    vector<Shape*> shapes;
public:
void add(Shape* s){
    shapes.push_back(s);
    }


    void write(string filename){
        ofstream myfile;
        myfile.open(filename);
        for(int i = 0; i < shapes.size(); i++)
            shapes[i]-> write(myfile);
        myfile.close();

    }
};

//https://www.stratasysdirect.com/resources/how-to-prepare-stl-files/
//https://www.viewstl.com/

int main(){
    CAD c;
    c.add(new Cube(0,0,0,   5));
    c.add(new Cylinder(100,0,0,    3, 10, 10));
    c.write("test.stl");

    return 0;
}