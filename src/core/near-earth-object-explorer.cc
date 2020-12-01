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

  std::vector<neowisejson::NEObject>
          neowisejson::Explorer::FilterByPotentiallyHazardousObjects() {
    std::vector<NEObject> hazardous_objects;
    // loop through objects_ & check if each NEObject is potentially hazardous,
    // if so add to hazardous_objects, which is return after loop finishes
    for (NEObject object : objects_) {
      if (object.GetPHA() == "Y") {
        hazardous_objects.push_back(object);
      }
    }
    return hazardous_objects;
  }



  std::string neowisejson::Explorer::GetObjectWithMaxPerihelion(
          double max_perihelion) {
    // create a holder neobject to represent the desired neobject and set it as
    // the first object in the list
    NEObject max_perihelion_object;
    max_perihelion_object = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetQAU1() > max_perihelion_object.GetQAU1() &&
          object.GetQAU1() < max_perihelion) {
        max_perihelion_object = object;
      }
    }
    return max_perihelion_object.GetDesignation();
  }



}