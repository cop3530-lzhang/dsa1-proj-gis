#include "../polygon.hpp"
#include "catch/catch.hpp"

TEST_CASE("Polygon tests") {
  // polygon with 0 vertices
  Polygon empty;

  // prepare list of points to create square
  Polygon square("MySquare 0 0 0 2 2 2 2 0");

  SECTION("Default Constructor") {
    CHECK(0 == empty.getVertexCount());
    CHECK("" == empty.getName());
  }

  SECTION("Parse with empty polygon") {
    empty.parse("MySquare 0 0 0 2 2 2 2 0");
    CHECK(4 == empty.getVertexCount());
    CHECK("MySquare" == empty.getName());
    CHECK(Point(0, 0) == empty.getVertex(0));
    CHECK(Point(0, 2) == empty.getVertex(1));
    CHECK(Point(2, 2) == empty.getVertex(2));
    CHECK(Point(2, 0) == empty.getVertex(3));
  }

  SECTION("Parse with existing data") {
    CHECK(4 == square.getVertexCount());
    CHECK("MySquare" == square.getName());
    CHECK(Point(0, 2) == square.getVertex(1));
    square.parse("NewName 0 0 0 1 1 1 1 0");
    CHECK(4 == square.getVertexCount());
    CHECK("NewName" == square.getName());
    CHECK(Point(0, 1) == square.getVertex(1));
  }

  SECTION("Parameterized Constructor") {
    CHECK(4 == square.getVertexCount());
    CHECK("MySquare" == square.getName());
    CHECK(Point(0, 0) == square.getVertex(0));
    CHECK(Point(0, 2) == square.getVertex(1));
    CHECK(Point(2, 2) == square.getVertex(2));
    CHECK(Point(2, 0) == square.getVertex(3));
  }

  SECTION("Copy Constructor and Copy Assignment Operator") {
    // copy constructor
    Polygon otherPolygon = square;
    CHECK(4 == otherPolygon.getVertexCount());
    CHECK("MySquare" == otherPolygon.getName());
    CHECK(Point(0, 2) == otherPolygon.getVertex(1));

    // copy assignment operator
    Polygon anotherPolygon;
    CHECK(0 == anotherPolygon.getVertexCount());
    anotherPolygon = square;
    CHECK(4 == anotherPolygon.getVertexCount());
    CHECK("MySquare" == anotherPolygon.getName());
    CHECK(Point(0, 2) == anotherPolygon.getVertex(1));
  }
}
