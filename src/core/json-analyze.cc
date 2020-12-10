#include "include/core/near-earth-object.h"
#include "include/core/near-earth-object-explorer.h"
namespace neowisejson {
  // analyze designation
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

  // analyze discovery_date
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

  //analyze i_deg
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

  // analyze h_mag
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

  // analyze moid_au
  neowisejson::NEObject neowisejson::Explorer::GetObjectWithMaxMoid(
          double max_moid) {
    NEObject highest_moid = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetMOID() > highest_moid.GetMOID() &&
          object.GetMOID() < max_moid) {
        highest_moid = object;
      }
    }
    return highest_moid;
  }

  double neowisejson::Explorer::GetAverageMoid() {
    size_t total_objects = 0;
    double total_moid = 0;
    // loop through objects and sum their moid_au
    for (NEObject object : objects_) {
      total_moid += object.GetMOID();
    }
    // return sum / total # of objects to get the avg
    return total_moid / (double)total_objects;
  }

  // analyze orbit_class
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

  // analyze period_yr
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

  // analyze pha
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

  // analyze q_au_1
  std::string neowisejson::Explorer::GetObjectWithMaxPerihelion(
          double max_perihelion) {
    // create a holder neobject to represent the desired neobject and set it as
    // the first object in the list
    NEObject max_perihelion_object;
    max_perihelion_object = objects_.at(0);
    // check if object's q_au_1 value is greater than the current max's but
    // still less than user-specified max
    for (NEObject object : objects_) {
      if (object.GetQAU1() > max_perihelion_object.GetQAU1() &&
          object.GetQAU1() < max_perihelion) {
        max_perihelion_object = object;
      }
    }
    return max_perihelion_object.GetDesignation();
  }

  double neowisejson::Explorer::GetAvgQAU1() {
    double total_qau1 = 0;
    for (NEObject object : objects_) {
      total_qau1 += object.GetQAU1();
    }
    return total_qau1 / objects_.size();
  }
  // analyze q_au_2
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