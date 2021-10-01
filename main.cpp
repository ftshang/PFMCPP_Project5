/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

/*
 copied UDT 1:
 */

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

        // Constructor
        Member();

        // Destructor
        ~Member();
    };

    //bill member with monthly fee
    double billMonthlyFee(Member member, float discount = .10f);
    // turn on and off equipment (treadmills, workout machines)
    bool turnOnEquipment(std::string employeeName, bool equipmentState = false);
    // turn on and off electricity
    bool turnOffElectricity(bool switchSetting = true);
    // findGymLocation member function
    int findGymLocation(int threshold, int startingValue);

    // Constructor
    Gym();
    // Destructor
    ~Gym();
    // Instastiating Member object called gymMember
    Member gymMember;
};

// Member Function Implementations for Gym and Member structures.

Gym::Member::Member() : memberName(""), accountBalance(0.0), autoPayEnabled(false), birthYear(0), weight(0.0)
{
    std::cout << "Creating an object of the Member structure." << std::endl;
}

Gym::Member::~Member()
{
    std::cout << "Name of structure: Member" << std::endl;
}

Gym::Gym() : numTreadmills(0), numDumbells(0), numSquatRacks(0), numUsers(0), costOfMonthlyElectricity(0.0)
{
    std::cout << "Creating an object of the Gym structure." << std::endl;
}

Gym::~Gym()
{
    std::cout << "Name of structure: Gym" << std::endl;
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
    if (switchSetting == true)
        switchSetting = false;
    else
        switchSetting = true;
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

        // Constructor
        Teacher();

        // Destructor
        ~Teacher();
    };

    // hire or fire teacher
    bool hireOrFireTeacher(Teacher teacher);
    // add student to a class
    void addStudentToClass(Teacher teacher, std::string studentName);
    // add course to full course catalog
    void addCourse(std::string courseName, int gradeLevel = 9);
    // returnSchool member function
    double returnSchool(int threshold, int startingValue);

    // Constructor
    School();

    School(School &);

    // Destructor
    ~School();

    // Instantiating a Teacher object named mathTeacher
    Teacher mathTeacher; 
};

School::Teacher::Teacher() : teacherName("None"), numWorkingYears(0), department("None"), gradeLevel(9), teacherEmail("none@pausd.edu")
{
    std::cout << "Creating an object of the Teacher structure." << std::endl;
}

School::Teacher::~Teacher()
{
    std::cout << "Name of structure: Teacher" << std::endl;
}

School::School()
{
    std::cout << "Creating an object of the School structure." << std::endl;
}

School::~School()
{
    std::cout << "Name of structure: School" << std::endl;
}

void School::Teacher::teachClass(std::string day, int classDuration)
{
    while (classDuration > 0 && day != "Weekend")
        classDuration -= 1;
}

bool School::Teacher::askForPromotion(double payIncrease)
{
    bool getPromotion;
    if (payIncrease < 15000)
        getPromotion = true;
    else
        getPromotion = false;
    return getPromotion;
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
    bool hire;
    if (teacher.department == "Mathematics")
        hire = false;
    else
        hire = true;
    return hire;
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

    // Constructor
    PizzaStore();

    // Destructor
    ~PizzaStore();
};

PizzaStore::PizzaStore() : numEmployees(0), storeName("None"), totalMonthlySales(0.00), numOvens(5), numToppings(0)
{
    std::cout << "Creating an object of the PizzaStore structure." << std::endl;
}

PizzaStore::~PizzaStore()
{
    std::cout << "Name of structure: PizzaStore" << std::endl;
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
    std::cout << "Initialized Value of numOvens: " << std::endl;
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

    // Constructor
    Divisions();

    // Destructor
    ~Divisions();

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
    double tempCost;
    
    tempCost = gym_north.costOfMonthlyElectricity + gym_south.costOfMonthlyElectricity + gym_east.costOfMonthlyElectricity + gym_west.costOfMonthlyElectricity;

    std::cout << "Total cost of electricity: $" << tempCost << std::endl;

    return tempCost;
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

    // Constructor
    District();

    // Destructor 
    ~District();
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
    Gym gym1;
    double returnedDouble;
    bool returnedBool;
    // Calling each of gym1's member functions and displaying return values
    auto num = gym1.findGymLocation(10, 1);
    std::cout << "return value of gym1.findGymLocation(int, int): " << num << std::endl;
    num = gym1.gymMember.findMemberYears(10, 0);
    std::cout << "gym1.gymMember.findMemberYears(int, int) returns: " << num << std::endl;
    returnedDouble = gym1.billMonthlyFee(gym1.gymMember, .1f);
    std::cout << "Return Value of double Gym::billMonthlyFee(Member, float): " << returnedDouble << std::endl;
    returnedBool = gym1.turnOnEquipment("", false);
    std::cout << "Return Value of bool Gym::turnOnEquipment(string, bool): " << returnedBool << std::endl;
    returnedBool = gym1.turnOffElectricity(false);
    std::cout << "Return Value of bool Gym::turnOffElectricity(bool): " << returnedBool << std::endl;
    // Displaying gym1's member vairiable values
    std::cout << "Value of gym1's member variable numTreadmills: " << gym1.numTreadmills << std::endl;
    std::cout << "Value of gym1's member variable numDumbells: " << gym1.numDumbells << std::endl;
    std::cout << "Value of gym1's member variable numSquatRacks: " << gym1.numSquatRacks << std::endl;
    std::cout << "Value of gym1's member variable numUsers: " << gym1.numUsers << std::endl;
    std::cout << "Value of gym1's member variable costOfMonthlyElectricity: " << gym1.costOfMonthlyElectricity << std::endl;
    std::cout << std::endl;

    // Instansiating School object
    School school1;
    // Calling each of school1's member functions
    returnedDouble = school1.returnSchool(20, 0);
    std::cout << "Return Value of school1.returnSchool(int, int): " << returnedDouble << std::endl;
    num = school1.mathTeacher.returnTeacher(30, 1);
    std::cout << "Return Value of school1.mathTeacher.returnTeacher(int, int): " << num << std::endl;
    returnedBool = school1.hireOrFireTeacher(school1.mathTeacher);
    std::cout << "Return Value of bool School::hireOrFireTeacher(Teacher): " << returnedBool << std::endl;
    school1.addStudentToClass(school1.mathTeacher, "Bill");
    school1.addCourse("Biology", 11);
    // Displaying school1's member variables
    std::cout << "Value of school1's member variable numTeachers: " << school1.numTeachers << std::endl;
    std::cout << "Value of school1's member variable schoolName: " << school1.schoolName << std::endl;  
    std::cout << "Value of school1's member variable numStudents: " << school1.numStudents << std::endl;
    std::cout << "Value of school1's member variable numCourses: " << school1.numCourses << std::endl;
    std::cout << "Value of school1's member variable educationFund: " << school1.educationFund << std::endl;
    std::cout << std::endl;

    // Instanstiating PizzaStore object
    PizzaStore pizza1;

    // Calling each of pizza1's member functions
    returnedDouble = pizza1.getPizzaStore(50, 3);
    std::cout << "Return Value of pizza1.getPizzaStore(int, int): " << returnedDouble << std::endl;
    returnedDouble = pizza1.billCustomer("Pepperoni", 10, .05f);
    std::cout << "Return Value of double PizzaStore::billCustomer(std::string, int, float): " << returnedDouble << std::endl;
    int returnedInt = pizza1.addToppings("Pepperoni", false);
    std::cout << "Return Value of int PizzaStore::addToppings(std::string, bool): " << returnedInt << std::endl;
    returnedBool = pizza1.hireOrFireEmployee("Bob", 5);
    std::cout << "Return Value of bool PizzaSTore:: addToppings(std::string, int): " << returnedBool << std::endl;
    // Displaying pizza1's member variables
    std::cout << "Value of pizza1's member variable numEmployees: " << pizza1.numEmployees << std::endl;
    std::cout << "Value of pizza1's member variable storeName: " << pizza1.storeName << std::endl;
    std::cout << "Value of pizza1's member variable totalMonthlySales: " << pizza1.totalMonthlySales << std::endl;
    std::cout << "Value of pizza1's member variable numOvens: " << pizza1.numOvens << std::endl;
    std::cout << "Value of pizza1's member variable numToppings " << pizza1.numToppings << std::endl;
    std::cout << std::endl;

    // Instantiating Divisions object
    Divisions d1;
    returnedInt = d1.multiplyTotalNumberUsers(5);
    std::cout << "Return Value of d1.multiplyTotalNumberUsers: " << returnedInt << std::endl;
    returnedDouble = d1.saveCostOfElectricity();
    std::cout << "Return Value of d1.saveCostOfElectricity(): " << returnedDouble << std::endl;

    // Instantiating District object
    District schoolDistrict;
    returnedInt = schoolDistrict.increaseSchoolCourses(50, 0);
    std::cout << "Return value of schoolDistrict.increaseSchoolCourses(int, int): " << returnedInt << std::endl;
    std::cout << "Calling schoolDistrict.teachCourses(int, int)" << std::endl;
    schoolDistrict.teachCourses(100, 0);

    std::cout << "good to go!" << std::endl;
}
