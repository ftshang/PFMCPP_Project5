#include "District.h"

District::District()
{
    std::cout << "Creating District object. " << std::endl;
    for (int i = 9; i < 13; i++)
    {
        publicSchool.addCourse("Mathematics", i);
        privateSchool.addCourse("C++", i);
        bothSchools.addCourse("Mathematics and C++", i);
    }
}

District::~District()
{
    std::cout << "District object is being destroyed." << std::endl;
}

int District::increaseSchoolCourses(const int threshold, int startingValue)
{
    while (startingValue < threshold)
    {
        privateSchool.numCourses++;
        publicSchool.numCourses += 2;
        bothSchools.numCourses += privateSchool.numCourses + publicSchool.numCourses;
        startingValue++;
    }
    return bothSchools.numCourses;
}

void District::teachCourses(const int startingValue, const int endingValue) const
{
    for (int i = startingValue; i > endingValue; i--)
    {
        publicSchool.mathTeacher.teachClass("Monday", i);
        privateSchool.mathTeacher.teachClass("Monday", i);
        bothSchools.mathTeacher.teachClass("Monday", i);
    }
    std::cout << "Finished teaching classes for the day." << std::endl;
}

void District::increaseSchoolCoursesCopy()
{
    std::cout << "Calling int District::increaseSchoolCourses(int, int)" << std::endl;
    auto returnedValue = this->increaseSchoolCourses(50, 0);
    std::cout << "Return Value of int District::increaseSchoolCourses(int, int): " << returnedValue << std::endl;
}

void District::teachCoursesCopy() const
{
    std::cout << "Calling void District::teachCourses(int, int)" << std::endl;
    this->teachCourses(100, 0);
}