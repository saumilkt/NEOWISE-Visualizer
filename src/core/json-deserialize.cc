//
// Created by Saumil Thakore on 11/17/20.
//

#include "include/core/json-deserialize.h"
#include <fstream>
#include <iostream>

namespace neowisejson {
using json = nlohmann::json;

  neowisejson::Explorer DeserializeDataset(const char *filename) {
    std::vector<neowisejson::NEObject> objects;
    std::ifstream ss("../../data/main/neowise.json");
    json neowise_data = json::parse(ss);
    return neowisejson::Explorer(objects);
  }


}