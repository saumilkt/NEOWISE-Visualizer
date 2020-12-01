#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::string neowisejson::Explorer::GetObjectWithMaxPeriod(
          double max_period) {
    NEObject highest_period = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetPeriodYr() > highest_period.GetPeriodYr() &&
          object.GetPeriodYr() < max_period) {
        highest_period = object;
      }
    }
    return highest_period.GetDesignation();
  }

  double neowisejson::Explorer::GetAvgPeriod()  {
    double total_period = 0;
    for (NEObject object : objects_) {
      total_period += object.GetPeriodYr();
    }
    return total_period / objects_.size();
  }
} // namespace neowisejson