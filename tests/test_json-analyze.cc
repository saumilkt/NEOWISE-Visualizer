//
// Created by Saumil Thakore on 12/9/20.
//

#include "catch2/catch.hpp"
#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
#include "include/core/json-deserialize.h"

// Test designation
TEST_CASE(""){

}

// Test discovery_date
TEST_CASE(""){

}

// Test h_mag
TEST_CASE(""){

}

TEST_CASE(""){

}

TEST_CASE("GetMaxAndMinMagnitudes") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  std::tuple<std::string,std::string> test = explorer.GetMaxAndMinMagnitudes();
  REQUIRE(std::get<0>(test) == "(2014 JH57)");
  REQUIRE(std::get<1>(test) == "(2010 LJ68)");
}

// Test moid_au
TEST_CASE(""){

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

TEST_CASE(""){

}

// Test q_au_2
TEST_CASE(""){

}

TEST_CASE(""){

}

// Test period_yr
TEST_CASE(""){

}

TEST_CASE(""){

}

// Test i_deg
TEST_CASE(""){

}

TEST_CASE(""){

}

// Test pha
TEST_CASE("FilterByPotentiallyHazardousObjects") {
  neowisejson::Explorer
          explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.FilterByPotentiallyHazardousObjects().size()==30);
  REQUIRE(explorer.FilterByPotentiallyHazardousObjects().at(0).GetDesignation()
          == "419880 (2011 AH37)");
}

TEST_CASE(""){

}

// Test orbit_class
TEST_CASE(""){

}

TEST_CASE(""){

}
