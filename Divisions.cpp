#include "Divisions.h"

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

int Divisions::multiplyTotalNumberUsers(const int multipler) const
{
    std::cout << "Multiplying all divisions by " << multipler << std::endl; 

    return multipler * (gym_north.numUsers + gym_south.numUsers + gym_east.numUsers + gym_west.numUsers);
}

double Divisions::saveCostOfElectricity() const
{
    double tempCost = gym_north.costOfMonthlyElectricity + gym_south.costOfMonthlyElectricity + gym_east.costOfMonthlyElectricity + gym_west.costOfMonthlyElectricity;

    std::cout << "Total cost of electricity: $" << tempCost << std::endl;

    return tempCost;
}

void Divisions::multiplyTotalNumberUsersCopy() const
{
    std::cout << "Calling int Divisions::multiplyTotalNumberUsers(int)" << std::endl;
    auto returnedValue = this->multiplyTotalNumberUsers(5);
    std::cout << "Return Value of int Divisions::multiplyTotalNumberUsers(int): " << returnedValue << std::endl;
}

void Divisions::saveCostOfElectricityCopy() const
{
    std::cout << "Calling double saveCostOfElectricity()" << std::endl;
    auto returnedValue = this->saveCostOfElectricity();
    std::cout << "Return Value of double Divisions::saveCostofElectricity(): " << returnedValue << std::endl;
}
