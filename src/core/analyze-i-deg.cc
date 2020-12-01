#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::string neowisejson::Explorer::GetObjectWithMaxIDeg(
          double max_inclination) {
    NEObject highest_inclination = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetIDeg() > highest_inclination.GetIDeg() &&
          object.GetIDeg() < max_inclination) {
        highest_inclination = object;
      }
    }
    return highest_inclination.GetDesignation();
  }

  double neowisejson::Explorer::GetAvgIDeg() {
    double total_i_deg = 0;
    for (NEObject object : objects_) {
      total_i_deg += object.GetIDeg();
    }
    return total_i_deg / objects_.size();
  }
} // namespace neowisejson