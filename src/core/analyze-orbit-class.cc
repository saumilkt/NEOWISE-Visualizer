#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"

namespace neowisejson {
  std::vector<NEObject> neowisejson::Explorer::FilterByOrbitClass(
          string orbit_class) {
    std::vector<NEObject> orbits;
    for (NEObject object : objects_) {
      if (object.GetOrbitClass() == orbit_class){
        orbits.push_back(object);
      }
    }
    return orbits;
  }

  size_t neowisejson::Explorer::GetOrbitClassCount(string orbit_class) {
    size_t orbit_count = 0;
    for (NEObject object : objects_) {
      if (object.GetOrbitClass() == orbit_class){
        orbit_count++;
      }
    }
    return orbit_count;
  }
} // namespace neowisejson