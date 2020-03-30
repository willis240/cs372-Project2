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
}