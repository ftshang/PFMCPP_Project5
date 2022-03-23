/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'

#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif

 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */


#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "PizzaStore.h"
#include "Divisions.h"
#include "District.h"
#include <iostream>


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    GymWrapper gymWrapper(new Gym());
    double returnedDouble;
    bool returnedBool;
    // Calling each of gym1's member functions and displaying return values
    auto num = gymWrapper.pointerToGym->findGymLocation(10, 1);
    std::cout << "return value of findGymLocation(int, int): " << num << std::endl;
    // num = gym1.gymMember.findMemberYears(10, 0);
    num = gymWrapper.pointerToGym->gymMember.findMemberYears(10,0);
    std::cout << "findMemberYears(int, int) returns: " << num << std::endl;
    returnedDouble = gymWrapper.pointerToGym->billMonthlyFee(gymWrapper.pointerToGym->gymMember, .1f);
    std::cout << "Return Value of billMonthlyFee(Member, float): " << returnedDouble << std::endl;
    returnedBool = gymWrapper.pointerToGym->turnOnEquipment("", false);
    std::cout << "Return Value of turnOnEquipment(string, bool): " << returnedBool << std::endl;
    returnedBool = gymWrapper.pointerToGym->turnOffElectricity(false);
    std::cout << "Return Value of turnOffElectricity(bool): " << returnedBool << std::endl;
    // // Displaying gym1's member vairiable values
    std::cout << "Value of member variable numTreadmills: " << gymWrapper.pointerToGym->numTreadmills << std::endl;
    std::cout << "Value of member variable numDumbells: " << gymWrapper.pointerToGym->numDumbells << std::endl;
    std::cout << "Value of member variable numSquatRacks: " << gymWrapper.pointerToGym->numSquatRacks << std::endl;
    std::cout << "Value of member variable numUsers: " << gymWrapper.pointerToGym->numUsers << std::endl;
    std::cout << "Value of member variable costOfMonthlyElectricity: " << gymWrapper.pointerToGym->costOfMonthlyElectricity << std::endl;
    // // Calling member functions using this->
    gymWrapper.pointerToGym->findGymLocationCopy();
    gymWrapper.pointerToGym->gymMember.findMemberYearsCopy();
    gymWrapper.pointerToGym->billMonthlyFeeCopy();
    gymWrapper.pointerToGym->turnOnEquipmentCopy();
    gymWrapper.pointerToGym->turnOffElectricityCopy();
    gymWrapper.pointerToGym->displayMemberVariables();
    std::cout << std::endl;

    // // Instansiating School object
    SchoolWrapper schoolWrapper(new School());
    // // Calling each of school1's member functions
    returnedDouble = schoolWrapper.pointerToSchool->returnSchool(20, 0);
    std::cout << "Return Value of returnSchool(int, int): " << returnedDouble << std::endl;
    num = schoolWrapper.pointerToSchool->mathTeacher.returnTeacher(30, 1);
    std::cout << "Return Value of mathTeacher.returnTeacher(int, int): " << num << std::endl;
    returnedBool = schoolWrapper.pointerToSchool->hireOrFireTeacher(schoolWrapper.pointerToSchool->mathTeacher);
    std::cout << "Return Value of hireOrFireTeacher(Teacher): " << returnedBool << std::endl;
    schoolWrapper.pointerToSchool->addStudentToClass(schoolWrapper.pointerToSchool->mathTeacher, "Bill");
    schoolWrapper.pointerToSchool->addCourse("Biology", 11);
    // // Displaying school1's member variables
    std::cout << "Value of member variable numTeachers: " << schoolWrapper.pointerToSchool->numTeachers << std::endl;
    std::cout << "Value of member variable schoolName: " << schoolWrapper.pointerToSchool->schoolName << std::endl;
    std::cout << "Value of member variable numStudents: " << schoolWrapper.pointerToSchool->numStudents << std::endl;
    std::cout << "Value of member variable numCourses: " << schoolWrapper.pointerToSchool->numCourses << std::endl;
    std::cout << "Value of member variable educationFund: " << schoolWrapper.pointerToSchool->educationFund << std::endl;
    // // Calling member functions using this->
    schoolWrapper.pointerToSchool->returnSchoolCopy();
    schoolWrapper.pointerToSchool->mathTeacher.returnTeacherCopy();
    schoolWrapper.pointerToSchool->hireOrFireTeacherCopy();
    schoolWrapper.pointerToSchool->addStudentToClassCopy();
    schoolWrapper.pointerToSchool->addCourseCopy();
    schoolWrapper.pointerToSchool->displayMemberVariables();
    std::cout << std::endl;

    // // Instanstiating PizzaStore object
    PizzaStoreWrapper pizzaStoreWrapper(new PizzaStore());

    // // Calling each of pizza1's member functions
    returnedDouble = pizzaStoreWrapper.pointerToPizzaStore->getPizzaStore(50, 3);
    std::cout << "Return Value of getPizzaStore(int, int): " << returnedDouble << std::endl;
    returnedDouble = pizzaStoreWrapper.pointerToPizzaStore->billCustomer("Pepperoni", 10, .05f);
    std::cout << "Return Value of billCustomer(std::string, int, float): " << returnedDouble << std::endl;
    int returnedInt = pizzaStoreWrapper.pointerToPizzaStore->addToppings("Pepperoni", false);
    std::cout << "Return Value of addToppings(std::string, bool): " << returnedInt << std::endl;
    returnedBool = pizzaStoreWrapper.pointerToPizzaStore->hireOrFireEmployee("Bob", 5);
    std::cout << "Return Value of hireOrFireEmployee(std::string, int): " << returnedBool << std::endl;
    // // Displaying pizza1's member variables
    std::cout << "Value of member variable numEmployees: " << pizzaStoreWrapper.pointerToPizzaStore->numEmployees << std::endl;
    std::cout << "Value of member variable storeName: " << pizzaStoreWrapper.pointerToPizzaStore->storeName << std::endl;
    std::cout << "Value of member variable totalMonthlySales: " << pizzaStoreWrapper.pointerToPizzaStore->totalMonthlySales << std::endl;
    std::cout << "Value of member variable numOvens: " << pizzaStoreWrapper.pointerToPizzaStore->numOvens << std::endl;
    std::cout << "Value of member variable numToppings: " << pizzaStoreWrapper.pointerToPizzaStore->numToppings << std::endl;
    // // Calling member functions using this->
    pizzaStoreWrapper.pointerToPizzaStore->getPizzaStoreCopy();
    pizzaStoreWrapper.pointerToPizzaStore->billCustomerCopy();
    pizzaStoreWrapper.pointerToPizzaStore->addToppingsCopy();
    pizzaStoreWrapper.pointerToPizzaStore->hireOrFireEmployeeCopy();
    pizzaStoreWrapper.pointerToPizzaStore->displayMemberVariables();
    std::cout << std::endl;

    // // Instantiating Divisions object
    DivisionsWrapper divisionsWrapper(new Divisions());
    returnedInt = divisionsWrapper.pointerToDivisions->multiplyTotalNumberUsers(5);
    std::cout << "Return Value of multiplyTotalNumberUsers: " << returnedInt << std::endl;
    returnedDouble = divisionsWrapper.pointerToDivisions->saveCostOfElectricity();
    std::cout << "Return Value of saveCostOfElectricity(): " << returnedDouble << std::endl;
    // // Calling member functions using this->
    divisionsWrapper.pointerToDivisions->multiplyTotalNumberUsersCopy();
    divisionsWrapper.pointerToDivisions->saveCostOfElectricityCopy();

    // // Instantiating District object
    DistrictWrapper districtWrapper(new District());
    returnedInt = districtWrapper.pointerToDistrict->increaseSchoolCourses(50, 0);
    std::cout << "Return value of increaseSchoolCourses(int, int): " << returnedInt << std::endl;
    std::cout << "Calling teachCourses(int, int)" << std::endl;
    districtWrapper.pointerToDistrict->teachCourses(100, 0);
    // // Calling member functions using this->
    districtWrapper.pointerToDistrict->increaseSchoolCoursesCopy();
    districtWrapper.pointerToDistrict->teachCoursesCopy();

    std::cout << "good to go!" << std::endl;
}
