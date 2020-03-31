//tests.cpp
//Blake Caldwell, William Fisher, Kaleeb _________
//March 29, 2020

#include "catch.hpp"
#include "Shape.hpp"

#define CATCH_CONFIG_FAST_COMPILE

TEST_CASE("getHeight and getWidth functions")
{
	SECTION("Circle getHeight")
	{
		INFO("Radius 4 -> Height 8")
		REQUIRE(Circle(4).getHeight() == 8);

		INFO("Radius 6 -> Height 12")
		REQUIRE(Circle(6).getHeight() == 12);

		INFO("Radius 37 -> Height 74")
		REQUIRE(Circle(37).getHeight() == 74);
	}

	SECTION("Circle getWidth")
	{
		INFO("Radius 20 -> Width 40");
		REQUIRE(Circle(20).getWidth() == 40);

		INFO("Radius 16 -> Width 32");
		REQUIRE(Circle(16).getWidth() == 32);

		INFO("Radius 103 -> Width 206");
		REQUIRE(Circle(103).getWidth() == 206);
	}

	Polygon poly(3, 2);
	Polygon poly2(5, 2.4);

	SECTION("Polygon getHeight: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(poly.getHeight() == 
			2 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("5 sides, length 2.4");
		REQUIRE(poly2.getHeight() ==
			2.4 * (1 + cos(M_PI / 5)) / (2 * sin(M_PI / 5)));
	}

	SECTION("Polygon getWidth: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(poly.getWidth() == 2);

		INFO("5 sides, length 2.4");
		REQUIRE(poly2.getWidth() ==
			(2.4 * sin(M_PI * (5 - 1) / (2 * 5))) / sin(M_PI / 5));
	}

	Polygon poly3(4, 5);
	Polygon poly4(16, 20);

	SECTION("Polygon getHeight: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(poly3.getHeight() == (5 * (cos(M_PI / 4))) / sin(M_PI / 4));

		INFO("16 sides, length 20");
		REQUIRE(poly4.getHeight() == (20 * (cos(M_PI / 16))) / sin(M_PI / 16));
	}

	SECTION("Polygon getWidth: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(poly3.getWidth() == ((5 * cos(M_PI / 4)) / sin(M_PI / 4)));

		INFO("16 sides, length 20");
		REQUIRE(poly4.getWidth() == ((20 * cos(M_PI / 16)) / sin(M_PI / 16)));
	}

	Polygon poly5(6, 7);
	Polygon poly6(10, 15);

	SECTION("Polygon getHeight: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(poly5.getHeight() == (7 * cos(M_PI / 6) / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(poly6.getHeight() == (15 * cos(M_PI / 10) / sin(M_PI / 10)));
	}

	SECTION("Polygon getWidth: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(poly5.getWidth() == (7 / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(poly6.getWidth() == (15 / sin(M_PI / 10)));
	}
}