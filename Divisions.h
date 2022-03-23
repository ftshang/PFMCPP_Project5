#pragma once

#include "Gym.h"

struct Divisions
{
    // member variables
    Gym gym_north;
    Gym gym_south;
    Gym gym_east;
    Gym gym_west;

    // member functions
    int multiplyTotalNumberUsers(const int multipler) const;
    double saveCostOfElectricity() const;

    // member functions using this->
    void multiplyTotalNumberUsersCopy() const;
    void saveCostOfElectricityCopy() const;

    // Constructor
    Divisions();

    // Destructor
    ~Divisions();

    JUCE_LEAK_DETECTOR(Divisions)
};
