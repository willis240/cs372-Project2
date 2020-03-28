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
std::shared_ptr<Shape> makeSquare(double length); //is really a a rectangle
std::shared_ptr<Shape> makeTriangle(double length);
enum class Angle { R90, R180, R270 };
std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a);
std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy);
std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<Shape> i);
std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<Shape> i);
std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<Shape> i);

class Circle : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    double radius;
};

class Polygon : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    int numsides;
    double length;
};

class Rectangle : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    double width;
    double height;
};

class Spacer : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    double width;
    double height;
};

class Triangle : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    double length;
};

class RotatedShape : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    std::shared_ptr<Shape> s;
    Angle a;
};

class ScaledShape : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    std::shared_ptr<Shape> s;
    double sx;
    double sy;
};

class LayeredShape : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

class HorizontalShape : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

class VerticalShape : public Shape {
public:
    double getHeight() const;
    double getWidth() const;
    void generatePostScript(std::ostream& os);
private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

#endif
