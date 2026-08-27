#include "../gis.hpp"
#include "catch/catch.hpp"

TEST_CASE("Testing GIS operations") {
  GIS map;
  SECTION("Check file availability") {
    CHECK(!map.readFile("zzzzz.zzzz"));
    CHECK(map.readFile("simple-polygons.txt"));
  }

  SECTION("Check point that isn't inside any of the polygons") {
    map.readFile("simple-polygons.txt");
    CHECK("Not Found" == map.findParcelName(Point(-1, -1)));
  }

  SECTION("Check for point inside polygon") {
    map.readFile("simple-polygons.txt");
    CHECK("squareParcel" == map.findParcelName(Point(1, 1)));
    CHECK("wideRectangleParcel" == map.findParcelName(Point(5, 4)));
  }

  SECTION("Check for point on the edge of the polygon") {
    map.readFile("simple-polygons.txt");
    CHECK("squareParcel" == map.findParcelName(Point(0, 0)));
    CHECK("wideRectangleParcel" == map.findParcelName(Point(6, 4)));
  }
}
