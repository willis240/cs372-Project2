//Shape.hpp
//Blake Caldwell, William Fisher, Kaleeb _________
//March 27, 2020
//Header for the virtual class Shape and derived classes


#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getHeight() const = 0;
    virtual double getWidth() const = 0;
    virtual void generatePostScript(std::ostream& os) const = 0;
};

std::shared_ptr<Shape> makeCircle(double radius);
std::shared_ptr<Shape> makePolygon(int numSides, double length);
std::shared_ptr<Shape> makeRectangle(double width, double height);
std::shared_ptr<Shape> makeSpacer(double width, double height); 
std::shared_ptr<Shape> makeSquare(double length); //is really a rectangle
std::shared_ptr<Shape> makeTriangle(double length);
std::shared_ptr<Shape> makeCustom(double radius);       // Acts like circle
enum class Angle { R90, R180, R270 };
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a);
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy);
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i);
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i);
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i);

class Circle : public Shape {
public:
    Circle(double radius);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _radius;
};

class Polygon : public Shape {
public:
    Polygon(int numSides, double length);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    int _numSides;
    double _length;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _width;
    double _height;
};

class Spacer : public Shape {
public:
    Spacer(double width, double height);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _width;
    double _height;
};

class Triangle : public Shape {
public:
    Triangle(double length);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _length;
};

class Custom : public Shape {
public:
    Custom(double radius);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    double _radius;
};

class RotatedShape : public Shape {
public:
    RotatedShape(std::shared_ptr<Shape> s, Angle a);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::shared_ptr<Shape> _s;
    int _a;
};

class ScaledShape : public Shape {
public:
    ScaledShape(std::shared_ptr<Shape> s, double sx, double sy);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::shared_ptr<Shape> _s;
    double _sx;
    double _sy;
};

class LayeredShape : public Shape {
public:
    LayeredShape(std::initializer_list<std::shared_ptr<Shape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

class VerticalShape : public Shape {
public:
    VerticalShape(std::initializer_list<std::shared_ptr<Shape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

class HorizontalShape : public Shape {
public:
    HorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i);
    double getHeight() const override;
    double getWidth() const override;
    void generatePostScript(std::ostream& os) const override;
private:
    std::vector<std::shared_ptr<Shape>> _shapes;
};

#endif
