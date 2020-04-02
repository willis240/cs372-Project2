//Shape.cpp
//Blake Caldwell, William Fisher, Kaleeb Palmieri
//March 27, 2020
//class and function definitions for shape.hpp

#include "Shape.hpp"

using std::make_shared;
using std::cos;
using std::sin;
using std::initializer_list;
using std::vector;
using std::shared_ptr;

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

std::shared_ptr<Shape> makeCustom(double radius)
{
    return make_shared<Custom>(radius);
}


std::shared_ptr<Shape> makeRotatedShape(std::shared_ptr<Shape> s, Angle a)
{
	return make_shared<RotatedShape>(s,a);
}

std::shared_ptr<Shape> makeScaledShape(std::shared_ptr<Shape> s, double sx, double sy)
{
	return make_shared<ScaledShape>(s, sx, sy);
}

std::shared_ptr<Shape> makeLayeredShape(std::initializer_list<std::shared_ptr<Shape>> i)
{
	return make_shared<LayeredShape>(i);
}

std::shared_ptr<Shape> makeVerticalShape(std::initializer_list<std::shared_ptr<Shape>> i)
{
	return make_shared<VerticalShape>(i);
}

std::shared_ptr<Shape> makeHorizontalShape(std::initializer_list<std::shared_ptr<Shape>> i)
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
	if (_numSides % 2 == 0)
		return (_length * (cos(M_PI / _numSides)) / sin(M_PI / _numSides));
	
	return 0.0;
}

double Polygon::getWidth() const
{
	if (_numSides % 2 == 1)
		return ((_length * sin(M_PI * (_numSides - 1.0) / (2.0 * _numSides))) / sin(M_PI / _numSides));
	if (_numSides % 4 == 0)
		return ((_length * cos(M_PI / _numSides)) / sin(M_PI / _numSides));
	if (_numSides % 2 == 0)
		return (_length / sin(M_PI / _numSides));

	return 0.0;
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

Custom::Custom(double radius): _radius(radius){}

double Custom::getHeight() const
{
    return (2 * _radius);
}

double Custom::getWidth() const
{
    return (2 * _radius);
}

void Custom::generatePostScript(std::ostream& os) const
{
    os<<"/rad " << _radius << " def\n"
        "/-rad rad -1 mul def\n"
        "/val_1 0.86602540378 rad mul def\n"
        "/val_2 0.5 rad mul def\n"
        "/-val_1 val_1 -1 mul def\n"
        "/-val_2 val_2 -1 mul def"
        "rad rad rad 0 360 arc                 %starting complete circle\n"
        "stroke\n"
        "rad rad rad add rad 210 330 arc\n"
        "stroke\n"
        "rad rad -rad add rad 30 150 arc\n"
        "stroke\n"
        "rad val_1 add rad val_2 add rad 150 270 arc\n"
        "stroke\n"
        "rad -val_1 add rad val_2 add rad 270 30 arc\n"
        "stroke\n"
        "rad val_1 add rad -val_2 add rad 90 210 arc\n"
        "stroke\n"
        "rad -val_1 add rad -val_2 add rad 330 90 arc\n"
        "stroke";
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
	if (_a == 90 || _a == 270)
		return _s->getWidth();
	if (_a == 180)
		return _s->getHeight();
}

double RotatedShape::getWidth() const
{
	if (_a == 90 || _a == 270)
		return _s->getHeight();
	if (_a == 180)
		return _s->getWidth();
}

void RotatedShape::generatePostScript(std::ostream& os) const
{
}

ScaledShape::ScaledShape(std::shared_ptr<Shape> s, double sx, double sy): _s(s), _sx(sx), _sy(sy){}

double ScaledShape::getHeight() const
{
	return (_s->getHeight() * _sy);
}

double ScaledShape::getWidth() const
{
	return (_s->getWidth() * _sx);
}

void ScaledShape::generatePostScript(std::ostream& os) const
{
}

LayeredShape::LayeredShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
}

double LayeredShape::getHeight() const
{
	double maxHeight = 0;
	for (auto i : _shapes)
	{
		if (i->getHeight() > maxHeight)
			maxHeight = i->getHeight();
	}
	return maxHeight;
}

double LayeredShape::getWidth() const
{
	double maxWidth = 0;
	for (auto i : _shapes)
	{
		if (i->getWidth() > maxWidth)
			maxWidth = i->getWidth();
	}
	return maxWidth;
}

void LayeredShape::generatePostScript(std::ostream& os) const
{
}

VerticalShape::VerticalShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
}

double VerticalShape::getHeight() const
{
	double totalHeight = 0;
	for (auto i : _shapes)
	{
		totalHeight += i->getHeight();
	}
	return totalHeight;
}

double VerticalShape::getWidth() const
{
	double maxWidth = 0;
	for (auto i : _shapes)
	{
		if (i->getWidth() > maxWidth)
			maxWidth = i->getWidth();
	}
	return maxWidth;
}

void VerticalShape::generatePostScript(std::ostream& os) const
{
}

HorizontalShape::HorizontalShape(initializer_list<shared_ptr<Shape>> i)
{
	vector<shared_ptr<Shape>> temp(i.begin(), i.end());
	_shapes = temp;
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


