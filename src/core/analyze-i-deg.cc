#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  neowisejson::NEObject neowisejson::Explorer::GetObjectWithMaxHMag(
          double h_mag) {
    NEObject max_hmag = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetHMag() > max_hmag.GetHMag() &&
          object.GetHMag() < h_mag) {
        max_hmag = object;
      }
    }
    return max_hmag;
  }

  double neowisejson::Explorer::GetAverageHMag() {
    double h_mag_total = 0;
    for (NEObject object : objects_) {
      h_mag_total += object.GetHMag();
    }
    return h_mag_total / objects_.size();
  }

  std::tuple<string,string> neowisejson::Explorer::GetMaxAndMinMagnitudes() {
    NEObject max_magnitude_object, min_magnitude_object = objects_.at(0);
    for (NEObject object : objects_) {
      if (object.GetHMag() > max_magnitude_object.GetHMag()) {
        max_magnitude_object = object;
      } else if (object.GetHMag() < min_magnitude_object.GetHMag()) {
        min_magnitude_object = object;
      }
    }
    return std::make_tuple(min_magnitude_object.GetDesignation(),
                           max_magnitude_object.GetDesignation());

  }
} // namespace neowisejson