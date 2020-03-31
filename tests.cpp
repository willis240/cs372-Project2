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

	SECTION("Polygon getHeight")
	{
		INFO("3 sides, length 2");
		REQUIRE(poly.getHeight() == 
			2 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("5 sides, length 2.4");
		REQUIRE(poly2.getHeight() ==
			2.4 * (1 + cos(M_PI / 5)) / (2 * sin(M_PI / 5)));
	}

	SECTION("Polygon getWidth")
	{
		INFO("3 sides, length 2");
		REQUIRE(poly.getWidth() == 
			(2 * sin(M_PI * (3 - 1) / 2 * 3)) / sin(M_PI / 3));
	}
}