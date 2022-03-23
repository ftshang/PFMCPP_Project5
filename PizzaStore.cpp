#include "PizzaStore.h"

PizzaStore::PizzaStore() : numEmployees(0), storeName("None"), totalMonthlySales(0.00), numOvens(5), numToppings(0)
{
    std::cout << "Creating an object of the PizzaStore structure." << std::endl;
}

PizzaStore::~PizzaStore()
{
    std::cout << "PizzaStore object being destroyed." << std::endl;
}

double PizzaStore::billCustomer(const std::string pizzaType, const int toppings, float discountSale) const
{
    std::cout << "Initialized Value of storeName: " << storeName << std::endl;
    std::cout << "double PizzaStore::billCustomer(std::string, int, float) " << pizzaType << std::endl;
    double bill;
    if (pizzaType == "regular")
        discountSale = .20f;
    bill = (20 + (.5 * toppings)) * static_cast<double>(discountSale); 
    return bill;
}

int PizzaStore::addToppings(const std::string toppingName, const bool maxedOutToppings)
{
    std::cout << "Initialized Value of numOvens: " << numOvens << std::endl;
    std::cout << "int PizzaStore::addToppings(std::string, bool) " << toppingName << std:: endl;
    if (maxedOutToppings == false && toppingName != "Pineapple")
        ++numToppings;
    return numToppings;
}

bool PizzaStore::hireOrFireEmployee(const std::string employeeName, const int totalStaffMembers)
{
    std::cout << "Initialized Value of totalMonthlySales: " << totalMonthlySales << std::endl;
    std::cout << "bool PizzaStore::hireOrFireEmployee(std::string, int) " << employeeName << std::endl;
    bool hire;
    if (employeeName != "None" || totalStaffMembers < 25)
    {
        ++numEmployees;
        hire = true;
    }
    else
    {
        --numEmployees;
        hire = false;
    }
    return hire;
}

double PizzaStore::getPizzaStore(const int threshold, const int startingValue) const
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

void PizzaStore::billCustomerCopy() const
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

void PizzaStore::getPizzaStoreCopy() const
{
    std::cout<< "Calling double PizzaStore::getPizzaStore(int, int)" << std::endl;
    auto returnedValue = this->getPizzaStore(50, 3);
    std::cout << "Return Value of double PizzaStore::getPizzaStore(int, int): " << returnedValue << std::endl;
}

void PizzaStore::displayMemberVariables() const
{
    std::cout << "Value of member variable numEmployees: " << this->numEmployees << std::endl;
    std::cout << "Value of member variable storeName: " << this->storeName << std::endl;
    std::cout << "Value of member variable totalMonthlySales: " << this->totalMonthlySales << std::endl;
    std::cout << "Value of member variable numOvens: " << this->numOvens << std::endl;
    std::cout << "Value of member variables numToppings: " << this->numToppings << std::endl;
}
