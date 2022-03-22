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
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */





/*
 copied UDT 1:
 */
#include "LeakedObjectDetector.h"
#include <iostream>
struct Gym
{
    // number of treadmills
    int numTreadmills = 100;
    // number of dumbbells
    int numDumbells = 50;
    // number of squat racks
    int numSquatRacks = 10;
    // number of users who have a gym membership
    int numUsers = 2500;
    // cost of monthly electricity bill
    double costOfMonthlyElectricity = 1025.35;

    struct Member
    {
        std::string memberName;
        double accountBalance;
        bool autoPayEnabled;
        int birthYear;
        double weight;

        double getMemberAccountBalance(int accountNumber);
        double weighCurrentSelf(double startingWeight, bool finishedWorkout = true);
        void exercise(std::string machineType, int minutes = 60);
        int findMemberYears(int threshold, int startingValue);

        // using this-> member function
        void findMemberYearsCopy();

        // Constructor
        Member();

        // Destructor
        ~Member();

        JUCE_LEAK_DETECTOR(Member)
    };

    //bill member with monthly fee
    double billMonthlyFee(Member member, float discount = .10f);
    // turn on and off equipment (treadmills, workout machines)
    bool turnOnEquipment(std::string employeeName, bool equipmentState = false);
    // turn on and off electricity
    bool turnOffElectricity(bool switchSetting = true);
    // findGymLocation member function
    int findGymLocation(int threshold, int startingValue);

    // using this-> member functions
    void billMonthlyFeeCopy();
    void turnOnEquipmentCopy();
    void turnOffElectricityCopy();
    void findGymLocationCopy();
    void displayMemberVariables();

    // Constructor
    Gym();
    // Destructor
    ~Gym();
    // Instastiating Member object called gymMember
    Member gymMember;

    JUCE_LEAK_DETECTOR(Gym)
};

// Member Function Implementations for Gym and Member structures.

Gym::Member::Member() : memberName(""), accountBalance(0.0), autoPayEnabled(false), birthYear(0), weight(0.0)
{
    std::cout << "Creating an object of the Member structure." << std::endl;
}

Gym::Member::~Member()
{
    std::cout << "Member object being destroyed." << std::endl;
}

Gym::Gym() : numTreadmills(0), numDumbells(0), numSquatRacks(0), numUsers(0), costOfMonthlyElectricity(0.0)
{
    std::cout << "Creating an object of the Gym structure." << std::endl;
}

Gym::~Gym()
{
    std::cout << "Gym object being destroyed." << std::endl;
}

double Gym::Member::getMemberAccountBalance(int accountNumber)
{
    if (accountNumber < 0)
        accountBalance = 0;
    return accountBalance;
}

double Gym::Member::weighCurrentSelf(double startingWeight, bool finishedWorkout)
{
    if (finishedWorkout == true)
        startingWeight -= 1.5;
    else
        startingWeight += .5;
    return startingWeight;
}

void Gym::Member::exercise(std::string machineType, int minutes)
{
    if (minutes == 60 && machineType == "Treadmill")
        weight -= 5.5;
    else if (minutes == 30 && machineType == "Dumbbells")
        weight += 2.5;
    else
        weight += .5;
}

double Gym::billMonthlyFee(Member member, float discount)
{
    std::cout << "Initialized Value of accountBalance: " << member.accountBalance << std::endl;
    std::cout << "double Gym::billMonthlyFee(Member, float) " << member.accountBalance << std::endl;
    member.accountBalance -= static_cast<double>(discount * 35.5f);
    return member.accountBalance;
}

bool Gym::turnOnEquipment(std::string employeeName, bool equipmentState)
{
    std::cout << "Initialized Value of autoPayEnabled: " << gymMember.autoPayEnabled << std::endl;
    std::cout << "bool Gym::turnOnEquipment(std::string, bool) " << equipmentState << std::endl;
    if (equipmentState == false && employeeName != "None")
        equipmentState = true;
    else
        equipmentState = false;
    return equipmentState;
}

bool Gym::turnOffElectricity(bool switchSetting)
{
    std::cout << "Initalized Value of weight: " << gymMember.weight << std::endl;
    std::cout << "bool Gym::turnOffElectricity(bool) " << switchSetting << std::endl;
    switchSetting = !switchSetting;
    return switchSetting;
}

int Gym::findGymLocation(int threshold, int startingValue)
{
    Gym gym;
    while(startingValue < threshold)
    {
        gym.numTreadmills += 1;
        gym.numUsers += 1;
        startingValue += 1;
    }
    return gym.numUsers;
}

int Gym::Member::findMemberYears(int threshold, int startingValue)
{
    Member member;
    for (int i = startingValue; startingValue < threshold; i++)
    {
        member.birthYear += 5;
        if (member.birthYear >= threshold)
            break;
    }
    return member.birthYear;    
}

void Gym::Member::findMemberYearsCopy()
{
    std::cout << "Calling findMemberYears(int, int)" << std::endl;
    auto returnValue = this->findMemberYears(10, 0);
    std::cout << "findMemberYears(int, int) returns: " << returnValue << std::endl;
}

void Gym::billMonthlyFeeCopy()
{
    std::cout << "Calling double Gym::billMonthlyFee(Member, float): " << std::endl; 
    auto returnValue = this->billMonthlyFee(this->gymMember, .1f);
    std::cout << "Return Value of double Gym::billMonthlyFee(Member, float): " << returnValue << std::endl;
}

void Gym::turnOnEquipmentCopy()
{
    std::cout << "Calling bool Gym::turnOnEquipment(string, bool) " << std::endl;
    auto returnValue = this->turnOnEquipment("", false);
    std::cout << "Return Value of bool Gym::turnOnEquipment(string, bool): " << returnValue << std::endl;
}

void Gym::turnOffElectricityCopy()
{
    std::cout << "Caling bool Gym::turnOffElectricity(bool)" << std::endl;
    auto returnValue = this->turnOffElectricity(false);
    std::cout << "Return Value of bool Gym::turnOffElectricity(bool): " << returnValue << std::endl;
}

void Gym::findGymLocationCopy()
{
    std::cout << "Calling int Gym::findGymLocation(int, int)" << std::endl;
    auto returnValue = this->findGymLocation(10, 1);
    std::cout << "Return Value of int Gym::findGymLocation(int, int): " << returnValue << std::endl;
}

void Gym::displayMemberVariables()
{
    std::cout << "Value of member variable numTreadmills: " << this->numTreadmills << std::endl;
    std::cout << "Value of member variable numDumbells: " << this->numDumbells << std::endl;
    std::cout << "Value of member variable numSquatRacks: " << this->numSquatRacks << std::endl;
    std::cout << "Value of member variable numUsers: " << this->numUsers << std::endl;
    std::cout << "Value of member variable costofMonthlyElectricity: " << this->costOfMonthlyElectricity << std::endl;
}

/*
 copied UDT 2:
 */

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

        void teachClass(std::string day, int classDuration = 60);
        bool askForPromotion(double payIncrease);
        void dismissClass(int minRemaining = 0, bool finishedLecture = true);
        // new member function
        int returnTeacher(int threshold, int startingValue);
        // using this-> for member function
        void returnTeacherCopy();

        // Constructor
        Teacher();

        // Destructor
        ~Teacher();

        JUCE_LEAK_DETECTOR(Teacher)
    };

    // hire or fire teacher
    bool hireOrFireTeacher(Teacher teacher);
    // add student to a class
    void addStudentToClass(Teacher teacher, std::string studentName);
    // add course to full course catalog
    void addCourse(std::string courseName, int gradeLevel = 9);
    // returnSchool member function
    double returnSchool(int threshold, int startingValue);

    // using this-> for member functions
    void hireOrFireTeacherCopy();
    void addStudentToClassCopy();
    void addCourseCopy();
    void returnSchoolCopy();
    void displayMemberVariables();

    // Constructor
    School();

    // Destructor
    ~School();

    // Instantiating a Teacher object named mathTeacher
    Teacher mathTeacher; 

    JUCE_LEAK_DETECTOR(School)
};

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

void School::Teacher::teachClass(std::string day, int classDuration)
{
    while (classDuration > 0 && day != "Weekend")
        classDuration -= 1;
}

bool School::Teacher::askForPromotion(double payIncrease)
{
    return payIncrease < 15000;
}

void School::Teacher::dismissClass(int minRemaining, bool finishedLecture)
{
    if (finishedLecture == true && minRemaining == 0)
        numWorkingYears += 1;
}

bool School::hireOrFireTeacher(Teacher teacher)
{
    std::cout << "Initialized Value of numTeachers: " << numTeachers << std::endl;
    std::cout << "School::hireOrFireTeacher(Teacher) " << teacher.numWorkingYears << std::endl;
    return teacher.department == "Mathematics";
}

void School::addStudentToClass(Teacher teacher, std::string studentName)
{
    std::cout << "Initialized Value of gradeLevel: " << mathTeacher.gradeLevel << std::endl;
    std::cout << "School::addStudentToClass(Teacher, std::string) " << numStudents << std::endl;
    if (teacher.numWorkingYears > 10 && studentName != "None")
        numStudents += 1;
    else
        numStudents -= 1;
}

void School::addCourse(std::string courseName, int gradeLevel)
{
    std::cout << "Initialized Value of teacherEmail: " << mathTeacher.teacherEmail << std::endl;
    std::cout << "School::addCourse(std::string, int) " << courseName << std::endl;
    if (gradeLevel >= 9 && courseName != "None")
        numCourses += 1;
    else
        numCourses -= 1;
}

int School::Teacher::returnTeacher(int threshold, int startingValue)
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

double School::returnSchool(int threshold, int startingValue)
{
    School s1;
    for (int i = startingValue; i < threshold; startingValue+=2)
    {
        s1.numTeachers += 1;
        s1.educationFund += 3.5;
        if (startingValue <= s1.numStudents)
            break;
    }
    return s1.educationFund;
}

void School::Teacher::returnTeacherCopy()
{
    std::cout << "Calling int School::Teacher::returnTeacher(int, int)" << std::endl;
    auto returnValue = this->returnTeacher(30, 1);
    std::cout << "Return value of mathTeacher.returnTeacher(int, int): " << returnValue << std::endl;
}

void School::hireOrFireTeacherCopy()
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

void School::returnSchoolCopy()
{
    std::cout << "Calling double School::returnSchool(int, int)" << std::endl;
    auto returnValue = this->returnSchool(20, 0);
    std::cout << "Return Value of returnSchool(int, int): " << returnValue << std::endl;
}

void School::displayMemberVariables()
{
    std::cout << "Value of member variable numTeachers: " << this->numTeachers << std::endl;
    std::cout << "Value of member variable schoolName: " << this->schoolName << std::endl;
    std::cout << "Value of member variable numStudents: " << this->numStudents << std::endl;
    std::cout << "Value of member variable numCourses: " << this->numCourses << std::endl;
    std::cout << "Value of member variable educationFund: " << this->educationFund << std::endl;
}

/*
 copied UDT 3:
 */

struct PizzaStore
{
    // number of all employees
    int numEmployees = 15;
    // store's name
    std::string storeName = "Jeff's Pizza Parlor";
    // number of total sales per month
    double totalMonthlySales = 2625.55;
    // number of pizza ovens
    int numOvens = 5;
    // number of pizza toppings 
    int numToppings = 14;

    // bill customer for pizza
    double billCustomer(std::string pizzaType, int toppings, float discountSale = .10f);
    // add toppings to pizza
    int addToppings(std::string toppingName, bool maxedOutToppings = false);
    // hire or fire employee
    bool hireOrFireEmployee(std::string employeeName, int totalStaffMembers);
    // getPizzaStore member function
    double getPizzaStore(int threshold, int startingValue);

    // Using -> for member functions
    void billCustomerCopy();
    void addToppingsCopy();
    void hireOrFireEmployeeCopy();
    void getPizzaStoreCopy();
    void displayMemberVariables();

    // Constructor
    PizzaStore();

    // Destructor
    ~PizzaStore();

    JUCE_LEAK_DETECTOR(PizzaStore)
};

PizzaStore::PizzaStore() : numEmployees(0), storeName("None"), totalMonthlySales(0.00), numOvens(5), numToppings(0)
{
    std::cout << "Creating an object of the PizzaStore structure." << std::endl;
}

PizzaStore::~PizzaStore()
{
    std::cout << "PizzaStore object being destroyed." << std::endl;
}

double PizzaStore::billCustomer(std::string pizzaType, int toppings, float discountSale)
{
    std::cout << "Initialized Value of storeName: " << storeName << std::endl;
    std::cout << "double PizzaStore::billCustomer(std::string, int, float) " << pizzaType << std::endl;
    double bill;
    if (pizzaType == "regular")
        discountSale = .20f;
    bill = (20 + (.5 * toppings)) * static_cast<double>(discountSale); 
    return bill;
}

int PizzaStore::addToppings(std::string toppingName, bool maxedOutToppings)
{
    std::cout << "Initialized Value of numOvens: " << numOvens << std::endl;
    std::cout << "int PizzaStore::addToppings(std::string, bool) " << toppingName << std:: endl;
    if (maxedOutToppings == false && toppingName != "Pineapple")
        numToppings += 1;
    return numToppings;
}

bool PizzaStore::hireOrFireEmployee(std::string employeeName, int totalStaffMembers)
{
    std::cout << "Initialized Value of totalMonthlySales: " << totalMonthlySales << std::endl;
    std::cout << "bool PizzaStore::hireOrFireEmployee(std::string, int) " << employeeName << std::endl;
    bool hire;
    if (employeeName != "None" || totalStaffMembers < 25)
    {
        numEmployees += 1;
        hire = true;
    }
    else
    {
        numEmployees -= 1;
        hire = false;
    }
    return hire;
}

double PizzaStore::getPizzaStore(int threshold, int startingValue)
{
    PizzaStore ps1;
    while (startingValue <= threshold)
    {
        ps1.numToppings += (startingValue + 4);
        ps1.totalMonthlySales += 100.25;
        if (ps1.numToppings > threshold)
            break;
    }
    return ps1.totalMonthlySales;
}

void PizzaStore::billCustomerCopy()
{
    std::cout << "Calling double PizzaStore::billCustomer(std::string, int, float)" << std::endl;
    auto returnedValue = this->billCustomer("Pepperoni", 10, .05f);
    std::cout << "Return Value of double PizzaStore::billCustomer(std::string, int, float): " << returnedValue << std::endl;
}

void PizzaStore::addToppingsCopy()
{
    std::cout << "Calling int PizzaStore::addToppings(std::string, bool)" << std::endl;
    auto returnedValue = this->addToppings("Pepperoni", false);
    std::cout << "Return Value of int PizzaStore::addToppings(std::string, bool): " << returnedValue << std::endl;
}

void PizzaStore::hireOrFireEmployeeCopy()
{
    std::cout << "Calling bool PizzaStore::hireOrFireEmployee(std::string, int)" << std::endl;
    auto returnedValue = this->hireOrFireEmployee("Bob", 5);
    std::cout << "Return Value of bool PizzaStore::hireOrFireEmployee(std::string, int): " << returnedValue << std::endl;
}

void PizzaStore::getPizzaStoreCopy()
{
    std::cout<< "Calling double PizzaStore::getPizzaStore(int, int)" << std::endl;
    auto returnedValue = this->getPizzaStore(50, 3);
    std::cout << "Return Value of double PizzaStore::getPizzaStore(int, int): " << returnedValue << std::endl;
}

void PizzaStore::displayMemberVariables()
{
    std::cout << "Value of member variable numEmployees: " << this->numEmployees << std::endl;
    std::cout << "Value of member variable storeName: " << this->storeName << std::endl;
    std::cout << "Value of member variable totalMonthlySales: " << this->totalMonthlySales << std::endl;
    std::cout << "Value of member variable numOvens: " << this->numOvens << std::endl;
    std::cout << "Value of member variables numToppings: " << this->numToppings << std::endl;
}

/*
 new UDT 4:
 with 2 member functions
 */

struct Divisions
{
    // member variables
    Gym gym_north;
    Gym gym_south;
    Gym gym_east;
    Gym gym_west;

    // member functions
    int multiplyTotalNumberUsers(int multipler);
    double saveCostOfElectricity();

    // member functions using this->
    void multiplyTotalNumberUsersCopy();
    void saveCostOfElectricityCopy();

    // Constructor
    Divisions();

    // Destructor
    ~Divisions();

    JUCE_LEAK_DETECTOR(Divisions)
};

Divisions::Divisions()
{
    std::cout << "Creating an object of the Divisions structure." << std::endl;
    gym_north.numUsers = gym_north.findGymLocation(50, 0);
    gym_south.numUsers = gym_south.findGymLocation(75, 0);
    gym_east.numUsers = gym_east.findGymLocation(100, 0);
    gym_west.numUsers = gym_west.findGymLocation(125, 0);
}

Divisions::~Divisions()
{
    std::cout << "Division object is getting destroyed. " << std::endl;
}

int Divisions::multiplyTotalNumberUsers(int multipler)
{
    std::cout << "Multiplying all divisions by " << multipler << std::endl; 

    return multipler * (gym_north.numUsers + gym_south.numUsers + gym_east.numUsers + gym_west.numUsers);
}

double Divisions::saveCostOfElectricity()
{
    double tempCost = gym_north.costOfMonthlyElectricity + gym_south.costOfMonthlyElectricity + gym_east.costOfMonthlyElectricity + gym_west.costOfMonthlyElectricity;

    std::cout << "Total cost of electricity: $" << tempCost << std::endl;

    return tempCost;
}

void Divisions::multiplyTotalNumberUsersCopy()
{
    std::cout << "Calling int Divisions::multiplyTotalNumberUsers(int)" << std::endl;
    auto returnedValue = this->multiplyTotalNumberUsers(5);
    std::cout << "Return Value of int Divisions::multiplyTotalNumberUsers(int): " << returnedValue << std::endl;
}

void Divisions::saveCostOfElectricityCopy()
{
    std::cout << "Calling double saveCostOfElectricity()" << std::endl;
    auto returnedValue = this->saveCostOfElectricity();
    std::cout << "Return Value of double Divisions::saveCostofElectricity(): " << returnedValue << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct District
{
    // member variables
    School publicSchool;
    School privateSchool;
    School bothSchools;

    // member function #1
    int increaseSchoolCourses(int threshold, int startingValue);
    // member function #2
    void teachCourses(int threshold, int startingValue);

    // member functions using this->
    void increaseSchoolCoursesCopy();
    void teachCoursesCopy();

    // Constructor
    District();

    // Destructor 
    ~District();

    JUCE_LEAK_DETECTOR(District)
};

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

int District::increaseSchoolCourses(int threshold, int startingValue)
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

void District::teachCourses(int startingValue, int endingValue)
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

void District::teachCoursesCopy()
{
    std::cout << "Calling void District::teachCourses(int, int)" << std::endl;
    this->teachCourses(100, 0);
}

struct GymWrapper
{
    // Constructor
    GymWrapper( Gym* gymPtr ) : pointerToGym( gymPtr )
    {}

    // Destructor
    ~GymWrapper()
    {
        delete pointerToGym;
    }

    // Member variable
    Gym* pointerToGym = nullptr;
};

struct SchoolWrapper
{
    // Constructor
    SchoolWrapper( School* schoolPtr ) : pointerToSchool( schoolPtr )
    {}

    // Destructor
    ~SchoolWrapper()
    {
        delete pointerToSchool;
    }

    // Member variable
    School* pointerToSchool = nullptr;
};

struct PizzaStoreWrapper
{
    // Constructor
    PizzaStoreWrapper( PizzaStore* pizzaPtr ) : pointerToPizzaStore(pizzaPtr)
    {}

    // Destructor
    ~PizzaStoreWrapper()
    {
        delete pointerToPizzaStore;
    }

    // Member variable
    PizzaStore* pointerToPizzaStore = nullptr;
};

struct DivisionsWrapper
{
    // Constructor
    DivisionsWrapper( Divisions* divPtr ) : pointerToDivisions( divPtr )
    {}

    // Destructor
    ~DivisionsWrapper()
    {
        delete pointerToDivisions;
    }
    // Member variable
    Divisions* pointerToDivisions = nullptr;
};

struct DistrictWrapper
{
    // Constructor
    DistrictWrapper( District* districtPtr ) : pointerToDistrict( districtPtr )
    {}

    // Destructor
    ~DistrictWrapper()
    {
        delete pointerToDistrict;
    }

    // Member variable
    District* pointerToDistrict = nullptr;
};

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
