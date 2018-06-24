// Unit Tests for the Vector3 class

#include "catch.hpp"
#include "../Core/Vector3.h"

	TEST_CASE( "Vector3 ctors set values", "[Vector3]" ) {
		SECTION( "Default ctor should set them to zero" ) {
			smashing::Vector3 v;
			REQUIRE( v.x == 0 );
			REQUIRE( v.y == 0 );
			REQUIRE( v.z == 0 );
		}
		SECTION( "Ctor should set values to ones passed in" ) {
			smashing::Vector3 v(5,6,7);
			REQUIRE( v.x == 5 );
			REQUIRE( v.y == 6 );
			REQUIRE( v.z == 7 );
		}
		SECTION( "Ctor should set values to ones passed in" ) {
			smashing::Vector3 v(-5,-6,-7);
			REQUIRE( v.x == -5 );
			REQUIRE( v.y == -6 );
			REQUIRE( v.z == -7 );
		}
		SECTION( "Copy Ctor should set values to ones from passed vector" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(v1);
			REQUIRE( v2.x == 1 );
			REQUIRE( v2.y == 2 );
			REQUIRE( v2.z == 3 );
			
		}
		SECTION( "assignment operator should set values to ones equalted" ) {
			smashing::Vector3 vfirst(10,20,30);
			smashing::Vector3 vsecond = vfirst;
			REQUIRE( vsecond.x == 10 );
			REQUIRE( vsecond.y == 20 );
			REQUIRE( vsecond.z == 30 );
		}
	}
	TEST_CASE( "Invert should flip the values to either postive or negative", "[Vector3]" ) {
		SECTION( "Postive values should become negative" ) {
			smashing::Vector3 v(1,2,3);
			v.invert();
			REQUIRE( v.x == -1 );
			REQUIRE( v.y == -2 );
			REQUIRE( v.z == -3 );
		}
		SECTION( "Negative values should become postive" ) {
			smashing::Vector3 v(-4,-5,-6);
			v.invert();
			REQUIRE( v.x == 4 );
			REQUIRE( v.y == 5 );
			REQUIRE( v.z == 6 );
		}
		SECTION( "Zero values should stay zero" ) {
			smashing::Vector3 v;
			v.invert();
			REQUIRE( v.x == 0 );
			REQUIRE( v.y == 0 );
			REQUIRE( v.z == 0 );
		}
	}
	TEST_CASE( "Mangtiude should give the correct values", "[Vector3]" ) {
		SECTION( "Mangitude with positive values should be correct" ) {
			smashing::Vector3 v(1,2,3);
			REQUIRE( v.magnitude()== Approx(3.74166));
		}
		SECTION( "Mangitude with negative values should be correct" ) {
			smashing::Vector3 v(-4,-5,-6);
			REQUIRE( v.magnitude()== Approx(8.77496));
		}
	}
	TEST_CASE( "Mangtiude squared should give the correct values", "[Vector3]" ) {
		SECTION( "Mangitude squared with positive values should be correct" ) {
			smashing::Vector3 v(1,2,3);
			REQUIRE( v.squaredMagnitude()== 14);
		}
		SECTION( "Mangitude with negative values should be correct" ) {
			smashing::Vector3 v(-4,-5,-6);
			REQUIRE( v.squaredMagnitude()== 77);
		}
	}
	TEST_CASE( "Normalize should set the magtiude to 1 for the vector", "[Vector3]" ) {
		SECTION( "normalizing with positive values should be correct" ) {
			smashing::Vector3 v(1,2,3);
			v.normalize();
			REQUIRE( v.x == Approx(0.26726));
			REQUIRE( v.y == Approx(0.53452));
			REQUIRE( v.z == Approx(0.80178));
		}
		SECTION( "normalizing with negative values should be correct" ) {
			smashing::Vector3 v(-4,-5,-6);
			v.normalize();
			REQUIRE( v.x == Approx(-0.45584));
			REQUIRE( v.y == Approx(-0.56980));
			REQUIRE( v.z == Approx(-0.68376));
		}
	}
	TEST_CASE( "Add scaled vector should work", "[Vector3]" ) {
		SECTION( "Adding scaled vector from origin should work correctly" ) {
			smashing::Vector3 v(1,2,3);
			smashing::real scale = 5;
			smashing::Vector3 v2;
			v2.addScaledVector(v,scale);
			REQUIRE( v2.x == 5);
			REQUIRE( v2.y == 10);
			REQUIRE( v2.z == 15);
		}
		SECTION( "Adding scaled vector away from origin should work correctly" ) {
			smashing::Vector3 v(1,2,3);
			smashing::real scale = 5;
			smashing::Vector3 v2(-3,-5,-8);
			v2.addScaledVector(v,scale);
			REQUIRE( v2.x == 2);
			REQUIRE( v2.y == 5);
			REQUIRE( v2.z == 7);
		}
	}
	TEST_CASE( "Test that component product works correctly", "[Vector3]" ) {
		SECTION( "Component product works correctly by returning a vector" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::Vector3 v3 = v1.componentProduct(v2);
			REQUIRE( v3.x == 4);
			REQUIRE( v3.y == 10);
			REQUIRE( v3.z == 18);
		}
		SECTION( "Component product works on self" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			v1.componentProductSelf(v2);
			REQUIRE( v1.x == 4);
			REQUIRE( v1.y == 10);
			REQUIRE( v1.z == 18);
		}
	}
	TEST_CASE( "Test that dot product works correctly", "[Vector3]" ) {
		SECTION( "dot product works correctly by returning a real value" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::real result = v1.dotProduct(v2);
			REQUIRE( result == 32);
		}
	}
	TEST_CASE( "Test that cross product works correctly", "[Vector3]" ) {
		SECTION( "cross product works correctly by returning a vector" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::Vector3 v3 = v1.crossProduct(v2);
			REQUIRE( v3.x == -3);
			REQUIRE( v3.y == 6);
			REQUIRE( v3.z == -3);
		}
	}
	TEST_CASE( "Test that all the operators for vector3 work correctly", "[Vector3]" ) {
		SECTION( "multiply opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::real scale = 5;
			smashing::Vector3 v3 = v1*5;
			REQUIRE( v3.x == 5);
			REQUIRE( v3.y == 10);
			REQUIRE( v3.z == 15);
		}
		SECTION( "multiply equal opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::real scale = 5;
			v1 *= 5;
			REQUIRE( v1.x == 5);
			REQUIRE( v1.y == 10);
			REQUIRE( v1.z == 15);
		}
		SECTION( "Dot product opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::real result = v1*v2;
			REQUIRE( result == 32);
		}
		SECTION( "divide opertaor works" ) {
			smashing::Vector3 v1(10,20,30);
			smashing::real scale = 5;
			smashing::Vector3 v3 = v1/5;
			REQUIRE( v3.x == 2);
			REQUIRE( v3.y == 4);
			REQUIRE( v3.z == 6);
		}
		SECTION( "divie equal opertaor works" ) {
			smashing::Vector3 v1(10,20,30);
			smashing::real scale = 5;
			v1 /= 5;
			REQUIRE( v1.x == 2);
			REQUIRE( v1.y == 4);
			REQUIRE( v1.z == 6);
		}
		SECTION( "cross opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::Vector3 v3 = v1%v2;
			REQUIRE( v3.x == -3);
			REQUIRE( v3.y == 6);
			REQUIRE( v3.z == -3);
		}
		SECTION( "cross equal opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			v1 %= v2;
			REQUIRE( v1.x == -3);
			REQUIRE( v1.y == 6);
			REQUIRE( v1.z == -3);
		}
		SECTION( "addition opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::Vector3 v3 = v1+v2;
			REQUIRE( v3.x == 5);
			REQUIRE( v3.y == 7);
			REQUIRE( v3.z == 9);
		}
		SECTION( "addition equal opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			v1 += v2;
			REQUIRE( v1.x == 5);
			REQUIRE( v1.y == 7);
			REQUIRE( v1.z == 9);
		}
		SECTION( "subtraction opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			smashing::Vector3 v3 = v1-v2;
			REQUIRE( v3.x == -3);
			REQUIRE( v3.y == -3);
			REQUIRE( v3.z == -3);
		}
		SECTION( "subtraction equal opertaor works" ) {
			smashing::Vector3 v1(1,2,3);
			smashing::Vector3 v2(4,5,6);
			v1 -= v2;
			REQUIRE( v1.x == -3);
			REQUIRE( v1.y == -3);
			REQUIRE( v1.z == -3);
		}
	}

