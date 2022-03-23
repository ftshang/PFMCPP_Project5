#include "Gym.h"

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

double Gym::Member::getMemberAccountBalance(const int accountNumber)
{
    if (accountNumber < 0)
        accountBalance = 0;
    return accountBalance;
}

double Gym::Member::weighCurrentSelf(double startingWeight, const bool finishedWorkout) const
{
    if (finishedWorkout == true)
        startingWeight -= 1.5;
    else
        startingWeight += .5;
    return startingWeight;
}

void Gym::Member::exercise(const std::string machineType, const int minutes)
{
    if (minutes == 60 && machineType == "Treadmill")
        weight -= 5.5;
    else if (minutes == 30 && machineType == "Dumbbells")
        weight += 2.5;
    else
        weight += .5;
}

double Gym::billMonthlyFee(Member member, const float discount) const
{
    std::cout << "Initialized Value of accountBalance: " << member.accountBalance << std::endl;
    std::cout << "double Gym::billMonthlyFee(Member, float) " << member.accountBalance << std::endl;
    member.accountBalance -= static_cast<double>(discount * 35.5f);
    return member.accountBalance;
}

bool Gym::turnOnEquipment(const std::string employeeName, bool equipmentState) const
{
    std::cout << "Initialized Value of autoPayEnabled: " << gymMember.autoPayEnabled << std::endl;
    std::cout << "bool Gym::turnOnEquipment(std::string, bool) " << equipmentState << std::endl;
    if (equipmentState == false && employeeName != "None")
        equipmentState = true;
    else
        equipmentState = false;
    return equipmentState;
}

bool Gym::turnOffElectricity(bool switchSetting) const
{
    std::cout << "Initalized Value of weight: " << gymMember.weight << std::endl;
    std::cout << "bool Gym::turnOffElectricity(bool) " << switchSetting << std::endl;
    switchSetting = !switchSetting;
    return switchSetting;
}

int Gym::findGymLocation(const int threshold, int startingValue) const
{
    Gym gym;
    while(startingValue < threshold)
    {
        ++gym.numTreadmills;
        ++gym.numUsers;
        ++startingValue;
    }
    return gym.numUsers;
}

int Gym::Member::findMemberYears(const int threshold, const int startingValue) const
{
    Member member;
    for (int i = startingValue; i < threshold; ++i)
    {
        member.birthYear += 5;
        if (member.birthYear >= threshold)
            break;
    }
    return member.birthYear;    
}

void Gym::Member::findMemberYearsCopy() const
{
    std::cout << "Calling findMemberYears(int, int)" << std::endl;
    auto returnValue = this->findMemberYears(10, 0);
    std::cout << "findMemberYears(int, int) returns: " << returnValue << std::endl;
}

void Gym::billMonthlyFeeCopy() const
{
    std::cout << "Calling double Gym::billMonthlyFee(Member, float): " << std::endl; 
    auto returnValue = this->billMonthlyFee(this->gymMember, .1f);
    std::cout << "Return Value of double Gym::billMonthlyFee(Member, float): " << returnValue << std::endl;
}

void Gym::turnOnEquipmentCopy() const
{
    std::cout << "Calling bool Gym::turnOnEquipment(string, bool) " << std::endl;
    auto returnValue = this->turnOnEquipment("", false);
    std::cout << "Return Value of bool Gym::turnOnEquipment(string, bool): " << returnValue << std::endl;
}

void Gym::turnOffElectricityCopy() const
{
    std::cout << "Caling bool Gym::turnOffElectricity(bool)" << std::endl;
    auto returnValue = this->turnOffElectricity(false);
    std::cout << "Return Value of bool Gym::turnOffElectricity(bool): " << returnValue << std::endl;
}

void Gym::findGymLocationCopy() const
{
    std::cout << "Calling int Gym::findGymLocation(int, int)" << std::endl;
    auto returnValue = this->findGymLocation(10, 1);
    std::cout << "Return Value of int Gym::findGymLocation(int, int): " << returnValue << std::endl;
}

void Gym::displayMemberVariables() const
{
    std::cout << "Value of member variable numTreadmills: " << this->numTreadmills << std::endl;
    std::cout << "Value of member variable numDumbells: " << this->numDumbells << std::endl;
    std::cout << "Value of member variable numSquatRacks: " << this->numSquatRacks << std::endl;
    std::cout << "Value of member variable numUsers: " << this->numUsers << std::endl;
    std::cout << "Value of member variable costofMonthlyElectricity: " << this->costOfMonthlyElectricity << std::endl;
}
