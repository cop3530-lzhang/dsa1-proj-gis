#include "../polygon.hpp"
#include "catch/catch.hpp"

TEST_CASE("Advanced polygon tests") {
  // prepare list of points to create square
  Polygon empty;
  Polygon square("MySquare 0 0 0 2 2 2 2 0");

  SECTION("Contains check on empty polygon") {
    CHECK(!empty.contains(Point(1, 1)));
  }

  SECTION("Check for point inside polygon") {
    CHECK(square.contains(Point(1, 1)));
  }

  SECTION("Check for point outside polygon") {
    CHECK(!square.contains(Point(-1, -1)));
  }

  SECTION("Check for point on the edge of polygon") {
    // at a vertex of the square
    CHECK(square.contains(Point(0, 2)));
    // on an edge of the square
    CHECK(square.contains(Point(0, 1)));
  }
}
