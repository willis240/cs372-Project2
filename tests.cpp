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
			REQUIRE(makeCircle(4)->getHeight() == 8);

		INFO("Radius 6 -> Height 12")
			REQUIRE(makeCircle(6)->getHeight() == 12);

		INFO("Radius 37 -> Height 74")
			REQUIRE(makeCircle(37)->getHeight() == 74);
	}

	SECTION("Circle getWidth")
	{
		INFO("Radius 20 -> Width 40");
		REQUIRE(makeCircle(20)->getWidth() == 40);

		INFO("Radius 16 -> Width 32");
		REQUIRE(makeCircle(16)->getWidth() == 32);

		INFO("Radius 103 -> Width 206");
		REQUIRE(makeCircle(103)->getWidth() == 206);
	}
}

TEST_CASE("Polygon getHeight and getWidth")
{
	SECTION("Polygon getHeight: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(makePolygon(3, 2)->getHeight() ==
			2 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("5 sides, length 2.4");
		REQUIRE(makePolygon(5, 2.4)->getHeight() ==
			2.4 * (1 + cos(M_PI / 5)) / (2 * sin(M_PI / 5)));
	}

	SECTION("Polygon getWidth: _numSides is odd")
	{
		INFO("3 sides, length 2");
		REQUIRE(makePolygon(3, 2)->getWidth() == 2);

		INFO("5 sides, length 2.4");
		REQUIRE(makePolygon(5, 2.4)->getWidth() ==
			(2.4 * sin(M_PI * (5 - 1) / (2 * 5))) / sin(M_PI / 5));
	}

	SECTION("Polygon getHeight: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(makePolygon(4, 5)->getHeight() == (5 * (cos(M_PI / 4))) / sin(M_PI / 4));

		INFO("16 sides, length 20");
		REQUIRE(makePolygon(16, 20)->getHeight() == (20 * (cos(M_PI / 16))) / sin(M_PI / 16));
	}

	SECTION("Polygon getWidth: _numSides divisible by 4")
	{
		INFO("4 sides, length 5");
		REQUIRE(makePolygon(4, 5)->getWidth() == ((5 * cos(M_PI / 4)) / sin(M_PI / 4)));

		INFO("16 sides, length 20");
		REQUIRE(makePolygon(16, 20)->getWidth() == ((20 * cos(M_PI / 16)) / sin(M_PI / 16)));
	}

	SECTION("Polygon getHeight: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(makePolygon(6, 7)->getHeight() == (7 * cos(M_PI / 6) / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(makePolygon(10, 15)->getHeight() == (15 * cos(M_PI / 10) / sin(M_PI / 10)));
	}

	SECTION("Polygon getWidth: _numSides divisible by 2, but not 4")
	{
		INFO("6 sides, length 7");
		REQUIRE(makePolygon(6, 7)->getWidth() == (7 / sin(M_PI / 6)));

		INFO("10 sides, length 15");
		REQUIRE(makePolygon(10, 15)->getWidth() == (15 / sin(M_PI / 10)));
	}
}

TEST_CASE("Rectangle getHeight and getWidth")
{
	SECTION("Rectangle getHeight")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeRectangle(8, 4)->getHeight() == 4);

		INFO("Width 17, Height 32");
		REQUIRE(makeRectangle(17, 32)->getHeight() == 32);
	}

	SECTION("Rectangle getWidth")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeRectangle(8, 4)->getWidth() == 8);

		INFO("Width 17, Height 32");
		REQUIRE(makeRectangle(17, 32)->getWidth() == 17);
	}
}

TEST_CASE("Spacer getHeight and getWidth")
{
	SECTION("Spacer getHeight")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeSpacer(8, 4)->getHeight() == 4);

		INFO("Width 17, Height 32");
		REQUIRE(makeSpacer(17, 32)->getHeight() == 32);
	}

	SECTION("Spacer getWidth")
	{
		INFO("Width 8, Height 4");
		REQUIRE(makeSpacer(8, 4)->getWidth() == 8);

		INFO("Width 17, Height 32");
		REQUIRE(makeSpacer(17, 32)->getWidth() == 17);
	}
}

TEST_CASE("Triangle getHeight and getWidth")
{
	SECTION("Triangle getHeight")
	{
		INFO("Length 4");
		REQUIRE(makeTriangle(4)->getHeight() == 4 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));

		INFO("Triangle(4) == Polygon(3, 4)");
		REQUIRE(makeTriangle(4)->getHeight() == Polygon(3, 4).getHeight());

		INFO("Length 17");
		REQUIRE(makeTriangle(17)->getHeight() == 17 * (1 + cos(M_PI / 3)) / (2 * sin(M_PI / 3)));
	}

	SECTION("Triangle getWidth")
	{
		INFO("Length 4");
		REQUIRE(makeTriangle(4)->getWidth() == (4 * sin(M_PI * (3 - 1.0) / (2.0 * 3))) / sin(M_PI / 3));

		INFO("Triangle(4) == Polygon(3, 4)");
		REQUIRE(makeTriangle(4)->getWidth() == Polygon(3, 4).getWidth());

		INFO("Length 17");
		REQUIRE(makeTriangle(17)->getWidth() == (17 * sin(M_PI * (3 - 1.0) / (2.0 * 3))) / sin(M_PI / 3));
	}
}
TEST_CASE("Custom getHeight and getWidth functions")
{

    SECTION("Custom getHeight"){

        INFO("Radius 4 -> Height 8")
            REQUIRE(makeCustom(4)->getHeight() == 8);

        INFO("Radius 6 -> Height 12")
            REQUIRE(makeCustom(6)->getHeight() == 12);

        INFO("Radius 37 -> Height 74")
            REQUIRE(makeCustom(37)->getHeight() == 74);
    }

    SECTION("Custom getWidth"){

        INFO("Radius 20 -> Width 40");
            REQUIRE(makeCustom(20)->getWidth() == 40);

        INFO("Radius 16 -> Width 32");
            REQUIRE(makeCustom(16)->getWidth() == 32);

        INFO("Radius 103 -> Width 206");
            REQUIRE(makeCustom(103)->getWidth() == 206);
    }
}


TEST_CASE("RotatedShape getHeight and getWidth")
{
	SECTION("RotatedShape getHeight")
	{
		INFO("Rectangle(3, 4), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R90)->getHeight() == 3);

		INFO("Rectangle(3, 4), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R270)->getHeight() == 3);

		INFO("Rectangle(3, 4), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R180)->getHeight() == 4);

		INFO("Circle(17), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeCircle(17), Angle::R90)->getHeight() == 34);

		INFO("Triangle(17, 34), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeTriangle(17), Angle::R270)->getHeight() == 
			makeTriangle(17)->getWidth());

		INFO("Custom(15), rotated 90 degrees");
        REQUIRE(makeRotatedShape(makeCustom(15), Angle::R90)->getHeight() == 30);


        INFO("Rectangle(17, 34), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(17, 34), Angle::R180)->getHeight() == 34);
	}

	SECTION("RotatedShape getWidth")
	{
		INFO("Rectangle(3, 4), rotated 90 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R90)->getWidth() == 4);

		INFO("Rectangle(3, 4), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R270)->getWidth() == 4);

		INFO("Rectangle(3, 4), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(3, 4), Angle::R180)->getWidth() == 3);

		INFO("Circle(17), rotated 90 degrees")
			REQUIRE(makeRotatedShape(makeCircle(17), Angle::R90)->getWidth() == 34);

		INFO("Triangle(17, 34), rotated 270 degrees");
		REQUIRE(makeRotatedShape(makeTriangle(17), Angle::R270)->getWidth() == 
			makeTriangle(17)->getHeight());

        INFO("Custom(15), rotated 90 degrees");
        REQUIRE(makeRotatedShape(makeCustom(15), Angle::R90)->getWidth() == 30);

		INFO("Rectangle(17, 34), rotated 180 degrees");
		REQUIRE(makeRotatedShape(makeRectangle(17, 34), Angle::R180)->getWidth() == 17);
	}
}

TEST_CASE("ScaledShape getHeight and getWidth")
{
	SECTION("ScaledShape getHeight")
	{
		INFO("Rectangle(3, 4), scaled vertically by factor of 3");
		REQUIRE(makeScaledShape(makeRectangle(3, 4), 1, 3)->getHeight() == 12);

		INFO("Circle(5), scaled vertically by factor of 5");
		REQUIRE(makeScaledShape(makeCircle(5), 1, 5)->getHeight() == 50);
	}

	SECTION("ScaledShape getWidth")
	{
		INFO("Rectangle(3, 4), scaled horizontally by factor of 3");
		REQUIRE(makeScaledShape(makeRectangle(3, 4), 3, 1)->getWidth() == 9);

		INFO("Triangle(5), scaled vertically by factor of 5");
		REQUIRE(makeScaledShape(makeTriangle(5), 7, 1)->getWidth() == 35);
	}
}
	
TEST_CASE("LayeredShape getHeight and getWidth")
{
	SECTION("LayeredShape getHeight")
	{
		INFO("Rectangle height 4, circle height 10");
		REQUIRE(makeLayeredShape({ makeRectangle(3, 4), makeCircle(5) })->getHeight() == 10);

		INFO("Rectangle height 200, circle height 50");
		REQUIRE(makeLayeredShape({ makeRectangle(50, 200), makeCircle(25) })->getHeight() == 200);
	}

	SECTION("LayeredShape getWidth")
	{
		INFO("Rectangle width 3, circle width 10");
		REQUIRE(makeLayeredShape({ makeRectangle(3, 4), makeCircle(5) })->getWidth() == 10);

		INFO("Rectangle width 51, circle width 50");
		REQUIRE(makeLayeredShape({ makeRectangle(51, 200), makeCircle(25) })->getWidth() == 51);
	}
}

TEST_CASE("VerticalShape getHeight and getWidth")
{
	SECTION("VerticalShape getHeight")
	{
		INFO("Rectangle height 4, circle height 10, rectangle height 20");
		REQUIRE(makeVerticalShape({ makeRectangle(3, 4), makeCircle(5),
					makeRectangle(5, 20) })->getHeight() == 34);

		INFO("Circle height 20, circle height 73");
		REQUIRE(makeVerticalShape({ makeCircle(10), makeCircle(36.5) })->getHeight() == 93);
	}

	SECTION("VerticalShape getWidth")
	{
		INFO("Rectangle width 3, circle width 10");
		REQUIRE(makeVerticalShape({ makeRectangle(3, 4), makeCircle(5) })->getWidth() == 10);

		INFO("Rectangle width 51, circle width 50");
		REQUIRE(makeVerticalShape({ makeRectangle(51, 200), makeCircle(25) })->getWidth() == 51);
	}
}

TEST_CASE("HorizontalShape getHeight and getWidth")
{
	SECTION("HorizontalShape getHeight")
	{
		INFO("Rectangle height 4, circle height 10");
		REQUIRE(makeHorizontalShape({ makeRectangle(3, 4), makeCircle(5) })->getHeight() == 10);

		INFO("Rectangle height 200, circle height 50");
		REQUIRE(makeHorizontalShape({ makeRectangle(50, 200), makeCircle(25) })->getHeight() == 200);
	}

	SECTION("HorizontalShape getWidth")
	{
		INFO("Rectangle width 35, circle width 25");
		REQUIRE(makeHorizontalShape({ makeRectangle(35, 20), makeCircle(12.5) })->getWidth() == 60);

		INFO("Circle width 30, circle width 20");
		REQUIRE(makeHorizontalShape({ makeCircle(15), makeCircle(10) })->getWidth() == 50);
	}
}

TEST_CASE("Complex Shapes getHeight and getWidth")
{
	SECTION("Complex Shapes getHeight")
	{
		REQUIRE(makeVerticalShape({ makeHorizontalShape({ makeRectangle(3, 4),
					makeCircle(5) }), makeHorizontalShape({ makeRectangle(20, 40),
					makeRectangle(30, 50)}) })->getHeight() == 10 + 50);
	}

	SECTION("Complex Shapes getWidth")
	{
		REQUIRE(makeLayeredShape({ makeHorizontalShape({ makeRectangle(17, 27), makeCircle(15) }),
					makeVerticalShape({ makeCircle(25), makeCircle(15) }) })->getWidth() == 25 * 2);
	}
}