//Shape.cpp
//Blake Caldwell, William Fisher, Kaleeb _________
//March 27, 2020
//class and function definitions for shape.hpp

#include "Shape.hpp"

using std::make_shared;
using std::cos;
using std::sin;

std::shared_ptr<Shape> makeCircle(double radius)
{
	return make_shared<Circle>(radius);
}

std::shared_ptr<Shape> makePolygon(int numSides, double length)
{
	return make_shared<Polygon>(numSides, length);
}

std::shared_ptr<Shape> makeRectangle(double width, double height)
{
	return make_shared<Rectangle>(width,height);
}

std::shared_ptr<Shape> makeSpacer(double width, double height)
{
	return make_shared<Spacer>(width, height);
}

std::shared_ptr<Shape> makeSquare(double length)
{
	return make_shared<Rectangle>(length,length);
}

std::shared_ptr<Shape> makeTriangle(double length)
{
	return make_shared<Triangle>(length);
}

std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a)
{
	return make_shared<RotatedShape>(s,a);
}

std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy)
{
	return make_shared<ScaledShape>(s, sx, sy);
}

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<Shape> i)
{
	return make_shared<LayeredShape>(i);
}

std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<Shape> i)
{
	return make_shared<VerticalShape>(i);
}

std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<Shape> i)
{
	return make_shared<HorizontalShape>(i);
}

Circle::Circle(double radius): _radius(radius){}

double Circle::getHeight() const
{
	return (2 * _radius);
}

double Circle::getWidth() const
{
	return (2 * _radius);
}

void Circle::generatePostScript(std::ostream& os) const 
{
}

Polygon::Polygon(int numSides, double length): _numSides(numSides), _length(length){}

double Polygon::getHeight() const
{
	if (_numSides % 2 == 1)
		return (_length * (1 + cos(M_PI / _numSides))/(2 * sin(M_PI / _numSides)));
	if (_numSides % 4 == 0)
		return (_length * (cos(M_PI / _numSides)) / sin(M_PI / _numSides));
	else if (_numSides % 2 == 0)
		return (_length * (cos(M_PI / _numSides)) / sin(M_PI / _numSides));
}

double Polygon::getWidth() const
{
	if (_numSides % 2 == 1)
		return ((_length * sin(M_PI * (_numSides - 1.0) / (2.0 * _numSides))) / sin(M_PI / _numSides));
	if (_numSides % 4 == 0)
		return ((_length * cos(M_PI / _numSides)) / sin(M_PI / _numSides));
	else if (_numSides % 2 == 0)
		return (_length / sin(M_PI / _numSides));
}

void Polygon::generatePostScript(std::ostream& os) const
{
}

Rectangle::Rectangle(double width, double height): _width(width), _height(height){}

double Rectangle::getHeight() const
{
	return _height;
}

double Rectangle::getWidth() const
{
	return _width;
}

void Rectangle::generatePostScript(std::ostream& os) const
{
}

Spacer::Spacer(double width, double height): _width(width), _height(height){}

double Spacer::getHeight() const
{
	return _height;
}

double Spacer::getWidth() const
{
	return _width;
}

void Spacer::generatePostScript(std::ostream& os) const
{
}

Triangle::Triangle(double length): _length(length){}

double Triangle::getHeight() const
{
	return Polygon(3, _length).getHeight();
}

double Triangle::getWidth() const
{
	return Polygon(3, _length).getWidth();
}

void Triangle::generatePostScript(std::ostream& os) const
{
}

RotatedShape::RotatedShape(std::shared_ptr<Shape> s, Angle a)
{
	_s = s;
	switch (a) {
	case Angle::R90:
		_a = 90;
		break;
	case Angle::R180:
		_a = 180;
		break;
	case Angle::R270:
		_a = 270;
		break;
	}
}

double RotatedShape::getHeight() const
{
	return 0.0;
}

double RotatedShape::getWidth() const
{
	return 0.0;
}

void RotatedShape::generatePostScript(std::ostream& os) const
{
}

ScaledShape::ScaledShape(std::shared_ptr<Shape> s, double sx, double sy)//TODO ********************************************************
{
}

double ScaledShape::getHeight() const
{
	return 0.0;
}

double ScaledShape::getWidth() const
{
	return 0.0;
}

void ScaledShape::generatePostScript(std::ostream& os) const
{
}

LayeredShape::LayeredShape(std::initializer_list<Shape> i)//TODO ********************************************************
{
}

double LayeredShape::getHeight() const
{
	return 0.0;
}

double LayeredShape::getWidth() const
{
	return 0.0;
}

void LayeredShape::generatePostScript(std::ostream& os) const
{
}

VerticalShape::VerticalShape(std::initializer_list<Shape> i)//TODO ********************************************************
{
}

double VerticalShape::getHeight() const
{
	return 0.0;
}

double VerticalShape::getWidth() const
{
	return 0.0;
}

void VerticalShape::generatePostScript(std::ostream& os) const
{
}

HorizontalShape::HorizontalShape(std::initializer_list<Shape> i)//TODO ********************************************************
{
}

double HorizontalShape::getHeight() const
{
	return 0.0;
}

double HorizontalShape::getWidth() const
{
	return 0.0;
}

void HorizontalShape::generatePostScript(std::ostream& os) const
{
}
