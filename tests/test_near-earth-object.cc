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

TEST_CASE("Getters") {
  neowisejson::NEObject object("designation","ddate",3,4,5,6,7,8,"pha","oclass");
  SECTION("GetDesignation") {
    REQUIRE(object.GetDesignation()=="designation");
  }

  SECTION("GetDiscoveryDate") {
    REQUIRE(object.GetDiscoverDate()=="ddate");
  }

  SECTION("GetHMag") {
    REQUIRE(object.GetHMag()==3);
  }

  SECTION("GetMOID") {
    REQUIRE(object.GetMOID()==4);
  }

  SECTION("GetQAU1") {
    REQUIRE(object.GetQAU1()==5);
  }

  SECTION("GetQAU2") {
    REQUIRE(object.GetQAU2()==6);
  }

  SECTION("GetPeriodYr") {
    REQUIRE(object.GetPeriodYr()==7);
  }

  SECTION("GetIDeg") {
    REQUIRE(object.GetIDeg()==8);
  }

  SECTION("GetPHA") {
    REQUIRE(object.GetPHA()=="pha");
  }

  SECTION("GetOrbitClass") {
    REQUIRE(object.GetOrbitClass()=="oclass");
  }
}


