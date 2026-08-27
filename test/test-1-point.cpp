#include "../point.hpp"
#include "catch/catch.hpp"

TEST_CASE("Point Default Constructor") {
  Point p;  // default point - at origin (0,0)
  CHECK(0 == p.getX());
  CHECK(0 == p.getY());
}

TEST_CASE("Point Parameterized Constructor") {
  Point p(3, 2);
  CHECK(3 == p.getX());
  CHECK(2 == p.getY());
}

TEST_CASE("Test equality operator overloading") {
  Point p1(4, 12);
  Point p2(12, 4);
  Point p3(4, 12);

  // You must implement the equality operator overloading in Point class
  CHECK(p1 == p3);
  CHECK(!(p1 == p2));
}
