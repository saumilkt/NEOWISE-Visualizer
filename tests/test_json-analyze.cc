//
// Created by Saumil Thakore on 12/9/20.
//

#include "catch2/catch.hpp"
#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
#include "include/core/json-deserialize.h"

TEST_CASE("FilterByPotentiallyHazardousObjects") {
neowisejson::Explorer
        explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
REQUIRE(explorer.FilterByPotentiallyHazardousObjects().size()==30);
REQUIRE(explorer.FilterByPotentiallyHazardousObjects().at(0).GetDesignation()
== "419880 (2011 AH37)");
}

TEST_CASE("GetAvgMoid") {
neowisejson::Explorer
        explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
REQUIRE(explorer.GetAverageMoid()==13.123);
}

TEST_CASE("GetObjectWithMaxPerihelion") {
neowisejson::Explorer
        explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
REQUIRE(explorer.GetObjectWithMaxPerihelion(13.123)=="C/2014 N3 (NEOWISE)");
}

TEST_CASE("GetMaxAndMinMagnitudes") {
neowisejson::Explorer
        explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
std::tuple<std::string,std::string> test = explorer.GetMaxAndMinMagnitudes();
REQUIRE(std::get<0>(test) == "(2014 JH57)");
REQUIRE(std::get<1>(test) == "(2010 LJ68)");
}

