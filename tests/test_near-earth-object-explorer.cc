//
// Created by Saumil Thakore on 11/17/20.
//

#include "catch2/catch.hpp"
#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
#include "include/core/json-deserialize.h"

TEST_CASE("GetObjects") {
  neowisejson::Explorer
  explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
  REQUIRE(explorer.GetObjects().size()==202);
  REQUIRE(explorer.GetObjects().at(0).GetDesignation()=="419880 (2011 AH37)");
}

