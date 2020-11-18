//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_JSON_DESERIALIZE_H
#define INCLUDE_JSON_DESERIALIZE_H

#include <string>

namespace neowisejson {
using std::string;

 class NEObject {
 public:
  // constructor from Json File
  NEObject(string designation, string discovery_date, double h_mag,
           double moid_au, double q_au_1, double q_au_2,
           double period_yr, double i_deg, string pha, string orbit_class);

  // constructor to handle any missing values
  NEObject();

  // getter methods
  string GetDesignation();
  string GetDiscoverDate();
  double GetHMag();
  double GetMOID();
  double GetQAU1();
  double GetQAU2();
  double GetPeriodYr();
  double GetIDeg();
  string GetPHA();
  string GetOrbitClass();


private:
  string designation_;
  string discovery_date_;
  double h_mag_;
  double moid_au_;
  double q_au_1_;
  double q_au_2_;
  double period_yr_;
  double i_deg_;
  string pha_;
  string orbit_class_;

  };
}
#endif //INCLUDE_JSON_DESERIALIZE_H
