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

  // returns a list of all potentially hazardous objects
  std::vector<neowisejson::NEObject> FilterByPotentiallyHazardousObjects();

  // returns the average moid of the dataste
  double GetAverageMoid();

  // returns the designation of the neo with the largest perihelion, below the
  // max value inputted by the user
  std::string GetObjectWithMaxPerihelion(double max_perihelion);

  // Returns a tuple of the designations of the objects with the lowest, and
  // highest apparent magnitudes
  std::tuple<std::string,std::string> GetMaxAndMinMagnitudes();
}

#endif //INCLUDE_JSON_DESERLIZE_H
