//
// Created by Saumil Thakore on 12/9/20.
//

#include "catch2/catch.hpp"
#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
#include "include/core/json-deserialize.h"

// Test designation
TEST_CASE("GetObjectWithDesignation"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetObjectWithDesignation("419880 (2011 AH37)").GetIDeg()==9.65);
}

// Test discovery_date
TEST_CASE("GetObjectWithGivenDiscoveryDate"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetObjectWithGivenDiscoveryDate("2011-01-07T00:00:00.000").GetIDeg()==9.65);
}

// Test h_mag
TEST_CASE("GetObjectWithMaxHMag"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetObjectWithMaxHMag(24.3).GetHMag()==24.1);
}

TEST_CASE("GetAverageHMag"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetAverageHMag()==22.3);
}

TEST_CASE("GetMaxAndMinMagnitudes") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  std::tuple<std::string,std::string> test = explorer.GetMaxAndMinMagnitudes();
  REQUIRE(std::get<0>(test) == "(2014 JH57)");
  REQUIRE(std::get<1>(test) == "(2010 LJ68)");
}

// Test moid_au
TEST_CASE("GetObjectWithMaxMoid"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

TEST_CASE("GetAvgMoid") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetAverageMoid()==13.123);
}

// Test q_au_1
TEST_CASE("GetObjectWithMaxPerihelion") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetObjectWithMaxPerihelion(13.123)=="C/2014 N3 (NEOWISE)");
}

TEST_CASE("GetAvgQAU1"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

// Test q_au_2
TEST_CASE("GetObjectWithMaxApohelion"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

TEST_CASE("GetAvgQAU2"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

// Test period_yr
TEST_CASE("GetObjectWithMaxPeriod"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

TEST_CASE("GetAvgPeriod"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
}

// Test i_deg
TEST_CASE("GetObjectWithMaxIDeg"){

}

TEST_CASE("GetAvgIDeg"){

}

// Test pha
TEST_CASE("FilterByPotentiallyHazardousObjects") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.FilterByPotentiallyHazardousObjects().size()==30);
  REQUIRE(explorer.FilterByPotentiallyHazardousObjects().at(0).GetDesignation()
          == "419880 (2011 AH37)");
}

TEST_CASE("GetPHACount"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetPHACount()==30);
}

// Test orbit_class
TEST_CASE("FilterByOrbitClass"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.FilterByOrbitClass("Jupiter-family Comet").size()==7);
  REQUIRE(explorer.FilterByOrbitClass("Jupiter-family Comet").front().GetIDeg()==5.18);
}

TEST_CASE("orbit_class"){
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetOrbitClassCount("Jupiter-family Comet")==7);
}
