//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_JSON_DESERLIZE_H
#define INCLUDE_JSON_DESERLIZE_H

#include "jsoncpp/json.h"
#include "near-earth-object.h"
#include <vector>
#include <string>
#include <tuple>

namespace neowisejson {
  using Json::Value;

  // deserializes the neowise dataset
  std::vector<neowisejson::NEObject> DeserializeDataset(std::string filename);
}

#endif //INCLUDE_JSON_DESERLIZE_H
