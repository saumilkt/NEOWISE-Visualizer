//
// Created by Saumil Thakore on 11/17/20.
//

#include "catch2/catch.hpp"
#include "include/core/near-earth-object.h"
TEST_CASE("Default Constructor") {
  neowisejson::NEObject object;
  REQUIRE(object.GetDesignation()=="");
  REQUIRE(object.GetDiscoverDate()=="");
  REQUIRE(object.GetHMag() == 0);
  REQUIRE(object.GetQAU1() == 0);
  REQUIRE(object.GetQAU2() == 0);
  REQUIRE(object.GetMOID() == 0);
  REQUIRE(object.GetIDeg() == 0);
  REQUIRE(object.GetPeriodYr() == 0);
  REQUIRE(object.GetPHA() == "");
  REQUIRE(object.GetOrbitClass() == "");
}
