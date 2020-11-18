//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_JSON_DESERLIZE_H
#define INCLUDE_JSON_DESERLIZE_H

#include "json/json.h"

#include <vector>
#include <string>
#include <tuple>

namespace neowisejson {
  using Json::Value;
  using neowisejson::NEObject;

  // deserializes the neowise dataset
  Value DeserializeDataset(string filename);

  // returns a list of all potentially hazardous objects
  std::vector<NEObject> FilterByPotentiallyHazardousObjects() const;

  // returns the average moid of the dataste
  double GetAverageMoid() const;

  // returns the designation of the neo with the largest perihelion, below the
  // max value inputted by the user
  string GetObjectWithMaxPerihelion(double max_perihelion) const;

  // Returns a tuple of the designations of the objects with the lowest, and
  // highest apparent magnitudes
  std::tuple<string,string> GetMaxAndMinMagnitudes() const;
}

#endif //INCLUDE_JSON_DESERLIZE_H
