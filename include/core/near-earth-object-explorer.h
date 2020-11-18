//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H
#define INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H

#include "near-earth-object.h"

#include <vector>
namespace neowisejson {
  class Explorer {
  public:
    Explorer(std::vector<neowisejson::NEObject>);

  private:
    //list of objects
    std::vector<neowisejson::NEObject> objects;

    /* helper methods for da/ds */
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
  };
} // namespace neowisejson

#endif //INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H
