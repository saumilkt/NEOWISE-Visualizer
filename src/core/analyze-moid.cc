#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  neowisejson::NEObject neowisejson::Explorer::GetObjectWithMaxMoid(
          double max_moid) {
    NEObject highest_moid = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetMOID() > highest_moid.GetMOID() &&
          object.GetMOID() < max_moid) {
        highest_moid = object;
      }
    }
    return highest_moid;
  }

  double neowisejson::Explorer::GetAverageMoid() {
    size_t total_objects = 0;
    double total_moid = 0;
    // loop through objects and sum their moid_au
    for (NEObject object : objects_) {
      total_moid += object.GetMOID();
    }
    // return sum / total # of objects to get the avg
    return total_moid / (double)total_objects;
  }
} // namespace neowisejson