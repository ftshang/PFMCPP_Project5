#pragma once

#include "School.h"

struct District
{
    // member variables
    School publicSchool;
    School privateSchool;
    School bothSchools;

    // member function #1
    int increaseSchoolCourses(const int threshold, int startingValue);
    // member function #2
    void teachCourses(const int threshold, const int startingValue) const;

    // member functions using this->
    void increaseSchoolCoursesCopy();
    void teachCoursesCopy() const;

    // Constructor
    District();

    // Destructor 
    ~District();

    JUCE_LEAK_DETECTOR(District)
};
