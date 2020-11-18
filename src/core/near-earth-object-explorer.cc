//
// Created by Saumil Thakore on 11/17/20.
//

#include "include/core/near-earth-object-explorer.h"
#include "include/core/near-earth-object.h"

namespace neowisejson {
  neowisejson::Explorer::Explorer(std::vector<neowisejson::NEObject> objects) {
    for (NEObject object : objects) {
      objects_.push_back(object);
    }
  }

  std::vector<neowisejson::NEObject> neowisejson::Explorer::GetObjects() {
    return objects_;
  }


}