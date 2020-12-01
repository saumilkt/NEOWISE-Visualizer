#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  neowisejson::NEObject neowisejson::Explorer::GetObjectWithGivenDiscoveryDate(
          string date) {
    for (NEObject object : objects_) {
      if (object.GetDiscoverDate() == date) {
        return object;
      }
    }
    // signals failure
    return NEObject();
  }
} // namespace neowisejson

