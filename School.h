#pragma once

#include "LeakedObjectDetector.h"

struct School
{
    // number of teachers
    int numTeachers = 0;
    // name of school with mascot
    std::string schoolName {"None"};
    // number of students
    int numStudents = 0;
    // number of courses available
    int numCourses {0};
    // total amount of education fund
    double educationFund = {0.00};

    struct Teacher
    {
        std::string teacherName = "Jacqueline James";
        int numWorkingYears = 12;
        std::string department = "Mathematics";
        int gradeLevel = 10;
        std::string teacherEmail = "jjames@pausd.edu";

        void teachClass(const std::string day, int classDuration = 60) const;
        bool askForPromotion(const double payIncrease) const;
        void dismissClass(const int minRemaining = 0, const bool finishedLecture = true);
        // new member function
        int returnTeacher(const int threshold, const int startingValue) const;
        // using this-> for member function
        void returnTeacherCopy() const;

        // Constructor
        Teacher();

        // Destructor
        ~Teacher();

        JUCE_LEAK_DETECTOR(Teacher)
    };

    // hire or fire teacher
    bool hireOrFireTeacher(const Teacher teacher) const;
    // add student to a class
    void addStudentToClass(const Teacher teacher, const std::string studentName);
    // add course to full course catalog
    void addCourse(const std::string courseName, const int gradeLevel = 9);
    // returnSchool member function
    double returnSchool(const int threshold, int startingValue) const;

    // using this-> for member functions
    void hireOrFireTeacherCopy() const;
    void addStudentToClassCopy();
    void addCourseCopy();
    void returnSchoolCopy() const;
    void displayMemberVariables() const;

    // Constructor
    School();

    // Destructor
    ~School();

    // Instantiating a Teacher object named mathTeacher
    Teacher mathTeacher; 

    JUCE_LEAK_DETECTOR(School)
};
