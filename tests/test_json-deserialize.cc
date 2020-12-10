//
// Created by Saumil Thakore on 11/17/20.
//

#include "catch2/catch.hpp"

#include "include/core/json-deserialize.h"
#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

TEST_CASE("DeserializeData") {
  neowisejson::Explorer objects =
          neowisejson::DeserializeDataset("data/json/neowise.json");
  REQUIRE(objects.GetObjects().size()==202);
  REQUIRE(objects.GetObjects().at(0).GetDesignation()=="419880 (2011 AH37)");
}