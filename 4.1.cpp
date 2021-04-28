#include <bits/stdc++.h>

using namespace std;

class Circle
{
private:
    double radius = 1.0;
    string color = "red";

public:
    Circle() {}
    Circle(double _radius) { radius = _radius; }
    Circle(double _radius, string _color)
    {
        radius = _radius;
        color = _color;
    }

    double getRadius()
    {
        return radius;
    }
    string getColor()
    {
        return color;
    }

    void setRadius(double _radius) { radius = _radius; }
    void setColor(string _color)
    {

        color = _color;
    }
    double getArea()
    {
        return M_PI * pow(radius, 2);
    }

    string toString()
    {
        // string = "cir"
        return "Circle(" + to_string(radius) + ")";
    }
};

class Cylinder : public Circle
{
private:
    double height = 1.0;

public:
    Cylinder()
    {
    }
    Cylinder(double _height)
    {
        height = _height;
    }

    Cylinder(double _height, double radius) : Circle(radius)
    {
        height = _height;
    }

    double getVolumne(){
        return getArea()*height;
    }

    double getHeight(){
        return height;
    }
};

int main()
{
    Cylinder test(3,2);
    test.setRadius(5);
    cout << test.getHeight();
}