//
// Created by Saumil Thakore on 11/17/20.
//

#include "include/core/json-deserlize.h"
#include <fstream>

namespace neowisejson {
  std::vector<neowisejson::NEObject> DeserializeDataste(string filename) {
    std::vector<neowisejson::NEObject> objects;
    std::ifstream data_file(filename, std::ifstream::binary);
    Json::Value neowise_data;
    data_file >> neowise_data;
    for(Json::Value::iterator data_iter = neowise_data.begin();
        data_iter!=neowise_data.end(); data_iter++) {
      objects.push_back(NEObject());
    }
    return objects;
  }


}