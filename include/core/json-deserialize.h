//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_JSON_DESERLIZE_H
#define INCLUDE_JSON_DESERLIZE_H

#include "nlohman/json.hpp"
#include "near-earth-object.h"
#include "near-earth-object-explorer.h"

#include <vector>
#include <string>
#include <tuple>

namespace neowisejson {

  // deserializes the neowise dataset
  neowisejson::Explorer DeserializeDataset(std::string filename);
}

#endif //INCLUDE_JSON_DESERLIZE_H
