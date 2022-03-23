#include "School.h"

School::Teacher::Teacher() : teacherName("None"), numWorkingYears(0), department("None"), gradeLevel(9), teacherEmail("none@pausd.edu")
{
    std::cout << "Creating an object of the Teacher structure." << std::endl;
}

School::Teacher::~Teacher()
{
    std::cout << "Teacher object being destroyed." << std::endl;
}

School::School()
{
    std::cout << "Creating an object of the School structure." << std::endl;
}

School::~School()
{
    std::cout << "School object being destroyed." << std::endl;
}

void School::Teacher::teachClass(const std::string day, int classDuration) const
{
    while (classDuration > 0 && day != "Weekend")
        --classDuration;
}

bool School::Teacher::askForPromotion(const double payIncrease) const
{
    return payIncrease < 15000;
}

void School::Teacher::dismissClass(const int minRemaining, const bool finishedLecture)
{
    if (finishedLecture == true && minRemaining == 0)
        ++numWorkingYears;
}

bool School::hireOrFireTeacher(const Teacher teacher) const
{
    std::cout << "Initialized Value of numTeachers: " << numTeachers << std::endl;
    std::cout << "School::hireOrFireTeacher(Teacher) " << teacher.numWorkingYears << std::endl;
    return teacher.department == "Mathematics";
}

void School::addStudentToClass(const Teacher teacher, const std::string studentName)
{
    std::cout << "Initialized Value of gradeLevel: " << mathTeacher.gradeLevel << std::endl;
    std::cout << "School::addStudentToClass(Teacher, std::string) " << numStudents << std::endl;
    if (teacher.numWorkingYears > 10 && studentName != "None")
        ++numStudents;
    else
        --numStudents;
}

void School::addCourse(const std::string courseName, const int gradeLevel)
{
    std::cout << "Initialized Value of teacherEmail: " << mathTeacher.teacherEmail << std::endl;
    std::cout << "School::addCourse(std::string, int) " << courseName << std::endl;
    if (gradeLevel >= 9 && courseName != "None")
        ++numCourses;
    else
        --numCourses;
}

int School::Teacher::returnTeacher(const int threshold, const int startingValue) const
{
    Teacher t1;
    while (startingValue < threshold)
    {
        t1.numWorkingYears += 10;
        if (startingValue + threshold < t1.numWorkingYears)
            break;
    }
    return t1.numWorkingYears;
}

double School::returnSchool(const int threshold, int startingValue) const
{
    School s1;
    for (int i = startingValue; i < threshold; startingValue+=2)
    {
        ++s1.numTeachers;
        s1.educationFund += 3.5;
        if (startingValue <= s1.numStudents)
            break;
    }
    return s1.educationFund;
}

void School::Teacher::returnTeacherCopy() const
{
    std::cout << "Calling int School::Teacher::returnTeacher(int, int)" << std::endl;
    auto returnValue = this->returnTeacher(30, 1);
    std::cout << "Return value of mathTeacher.returnTeacher(int, int): " << returnValue << std::endl;
}

void School::hireOrFireTeacherCopy() const
{
    std::cout << "Calling bool School::hireOrFireTeacher(Teacher)" << std::endl;
    auto returnValue = this->hireOrFireTeacher(this->mathTeacher);
    std::cout << "Return Value of bool School::hireOrFireTeacher(Teacher): " << returnValue << std::endl;
}

void School::addStudentToClassCopy()
{
    std::cout << "Calling void School::addStudentToClass(Teacher, std::string)" << std::endl;
    this->addStudentToClass(this->mathTeacher, "Bill");
}

void School::addCourseCopy()
{
    std::cout << "Calling void School::addCourse(std::string, int)" << std::endl;
    this->addCourse("Biology", 11);
}

void School::returnSchoolCopy() const
{
    std::cout << "Calling double School::returnSchool(int, int)" << std::endl;
    auto returnValue = this->returnSchool(20, 0);
    std::cout << "Return Value of returnSchool(int, int): " << returnValue << std::endl;
}

void School::displayMemberVariables() const
{
    std::cout << "Value of member variable numTeachers: " << this->numTeachers << std::endl;
    std::cout << "Value of member variable schoolName: " << this->schoolName << std::endl;
    std::cout << "Value of member variable numStudents: " << this->numStudents << std::endl;
    std::cout << "Value of member variable numCourses: " << this->numCourses << std::endl;
    std::cout << "Value of member variable educationFund: " << this->educationFund << std::endl;
}
