#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::string neowisejson::Explorer::GetObjectWithMaxPerihelion(
          double max_perihelion) {
    NEObject highest_qau1 = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetQAU1() > highest_qau1.GetQAU1() &&
          object.GetQAU1() < max_perihelion) {
        highest_qau1 = object;
      }
    }
    return highest_qau1.GetDesignation();
  }

  double neowisejson::Explorer::GetAvgQAU1() {
    double total_qau1 = 0;
    for (NEObject object : objects_) {
      total_qau1 += object.GetQAU1();
    }
    return total_qau1 / objects_.size();
  }
} // namespace neowisejson