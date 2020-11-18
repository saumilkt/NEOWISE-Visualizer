//
// Created by Saumil Thakore on 11/17/20.
//

#include "include/core/json-deserialize.h"
#include <fstream>

namespace neowisejson {
  neowisejson::Explorer DeserializeDataset(string filename) {
    std::vector<neowisejson::NEObject> objects;
    std::ifstream data_file(filename, std::ifstream::binary);
    Json::Value neowise_data;
    data_file >> neowise_data;
    for(auto& object : neowise_data) {
      objects.emplace_back(NEObject(object["designation"].asString(),
               object["discover_date"].asString(),object["h_mag"].asDouble(),
               object["moid_au"].asDouble(), object["q_au_1"].asDouble(),
               object["q_au_2"].asDouble(),object["period_yr"].asDouble(),
               object["i_deg"].asDouble(), object["pha"].asString(),
               object["orbit_class"].asString()));
    }
    return neowisejson::Explorer(objects);
  }


}