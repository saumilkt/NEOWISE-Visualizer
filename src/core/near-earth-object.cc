//
// Created by Saumil Thakore on 11/17/20.
//

#include "include/core/near-earth-object.h"

namespace neowisejson {
  neowisejson::NEObject::NEObject() {
    designation_ = "";
    discovery_date_ = "";
    h_mag_ = 0;
    moid_au_ = 0;
    q_au_1_ = 0;
    q_au_2_ = 0;
    period_yr_ = 0;
    i_deg_ = 0;
    pha_ = "";
    orbit_class_ = "";
  }

  neowisejson::NEObject::NEObject(string designation, string discovery_date,
                                  double h_mag, double moid_au, double q_au_1,
                                  double q_au_2, double period_yr, double i_deg,
                                  string pha, string orbit_class) {
    designation_ = designation;
    discovery_date_ = discovery_date;
    h_mag_ = h_mag;
    moid_au_ = moid_au;
    q_au_1_ = q_au_1;
    q_au_2_ = q_au_2;
    period_yr_ = period_yr;
    i_deg_ = i_deg;
    pha_ = pha;
    orbit_class_ = orbit_class;
  }

  string neowisejson::NEObject::GetDesignation() {
    return designation_;
  }

  string neowisejson::NEObject::GetDiscoverDate() {
    return discovery_date_;
  }

  double neowisejson::NEObject::GetHMag() {
    return h_mag_;
  }

  double neowisejson::NEObject::GetMOID() {
    return moid_au_;
  }

  double neowisejson::NEObject::GetQAU1() {
    return q_au_1_;
  }

  double neowisejson::NEObject::GetQAU2() {
    return q_au_2_;
  }

  double neowisejson::NEObject::GetPeriodYr() {
    return period_yr_;
  }

  double neowisejson::NEObject::GetIDeg() {
    return i_deg_;
  }

  string neowisejson::NEObject::GetPHA() {
    return pha_;
  }

  string neowisejson::NEObject::GetOrbitClass() {
    return orbit_class_;
  }
}