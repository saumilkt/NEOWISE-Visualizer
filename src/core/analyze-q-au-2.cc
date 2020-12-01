#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::string neowisejson::Explorer::GetObjectWithMaxApohelion(
          double max_apohelion) {
    NEObject highest_qau2 = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetQAU2() > highest_qau2.GetQAU2() &&
          object.GetQAU2() < max_apohelion) {
        highest_qau2 = object;
      }
    }
    return highest_qau2.GetDesignation();
  }

  double neowisejson::Explorer::GetAvgQAU2(){
    double total_qau2 = 0;
    for (NEObject object : objects_) {
      total_qau2 += object.GetQAU2();
    }
    return total_qau2 / objects_.size();
  }
} // namespace neowisejson