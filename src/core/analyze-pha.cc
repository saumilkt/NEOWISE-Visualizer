#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
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

  size_t neowisejson::Explorer::GetPHACount() {
    size_t pha_count = 0;
    for (NEObject object : objects_) {
      if (object.GetPHA()=="Y"){
        pha_count++;
      }
    }
    return pha_count;
  }
} // namespace neowisejson