#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
namespace neowisejson {
  neowisejson::NEObject neowisejson::Explorer::GetObjectWithDesignation(
          string designation) {
    for (NEObject object : objects_) {
      if (object.GetDesignation() == designation) {
        return object;
      }
    }
    // signals failure
    return NEObject();
  }
} // namespace neowisejson