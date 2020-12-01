//
// Created by Saumil Thakore on 11/17/20.
//

#ifndef INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H
#define INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H

#include "near-earth-object.h"

#include <vector>
namespace neowisejson {
  class Explorer {
  public:
    Explorer(std::vector<neowisejson::NEObject> objects);

    // getter
    std::vector<neowisejson::NEObject> GetObjects();

    /* helper methods for da/ds */

    /**
     *  Helper methods for Designation
     */
     // Returns the object with the given designation
    neowisejson::NEObject GetObjectWithDesignation(string designation);


    /**
     *  Helper methods for Discovery-date
     */
     // Gets the object with the given discovery date
     neowisejson::NEObject GetObjectWithGivenDiscoveryDate(string date);


    /**
     *  Helper methods for h_mag_
     */

    // Returns object with highest h_mag lower than inputted value
    neowisejson::NEObject GetObjectWithMaxHMag(double h_mag);

    // returns the average h_mag of the dataset
    double GetAverageHMag();

    // Returns a tuple of the designations of the objects with the lowest, and
    // highest apparent magnitudes
    std::tuple<string,string> GetMaxAndMinMagnitudes();


    /**
     *  Helper methods for moid_au
     */
    // returns object with max moid_au lower than inputted value
    neowisejson::NEObject GetObjectWithMaxMoid(double max_moid);

    // returns the average moid of the dataset
    double GetAverageMoid();


    /**
     *  Helper methods for q_au_1
     */
    // returns the designation of the neo with the largest perihelion, below the
    // max value inputted by the user
    std::string GetObjectWithMaxPerihelion(double max_perihelion);

    //returns the average q_au_1 of the dataset
    double GetAvgQAU1();


    /**
     *  Helper methods for q_au_2
     */
    // returns the designation of the neo with the largest apohelion, below the
    // max value inputted by the user
    std::string GetObjectWithMaxApohelion(double max_apohelion);

    //returns the average q_au_2 of the dataset
    double GetAvgQAU2();

    /**
     *  Helper methods for period_yr
     */
    // returns the designation of the neo with the largest period, below the
    // max value inputted by the user
    std::string GetObjectWithMaxPeriod(double max_period);

    //returns the average period of the dataset
    double GetAvgPeriod();

    /**
     *  Helper methods for i_deg
     */
    // returns the designation of the neo with the largest inclination, below the
    // max value inputted by the user
    std::string GetObjectWithMaxIDeg(double max_inclination);

    //returns the average i_deg of the dataset
    double GetAvgIDeg();

    /**
     *  Helper methods for pha
     */
    // returns a list of all potentially hazardous objects
    std::vector<neowisejson::NEObject> FilterByPotentiallyHazardousObjects();

    // returns the count of potentially hazardous objects
    size_t GetPHACount();

    /**
     *  Helper methods for orbit_class
     */
    // returns a list of all objects in the inputted orbit class
    std::vector<neowisejson::NEObject> FilterByOrbitClass(string orbit_class);

    // returns the count of objects of a given orbit class
    size_t GetOrbitClassCount(string orbit_class);

  private:
    //list of objects
    std::vector<neowisejson::NEObject> objects_;


  };
} // namespace neowisejson

#endif //INCLUDE_NEAR_EARTH_OBJECT_EXPLORER_H
