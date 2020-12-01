#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::vector<NEObject>
          neowisejson::Explorer::FilterByPotentiallyHazardousObjects() {
    std::vector<NEObject> p_h_objects;
    for (NEObject object : objects_) {
      if (object.GetPHA() == "Y"){
        p_h_objects.push_back(object);
      }
    }
    return p_h_objects;
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