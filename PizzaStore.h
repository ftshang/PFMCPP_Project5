#pragma once

#include "LeakedObjectDetector.h"

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
    double billCustomer(const std::string pizzaType, const int toppings, float discountSale = .10f) const;
    // add toppings to pizza
    int addToppings(const std::string toppingName, const bool maxedOutToppings = false);
    // hire or fire employee
    bool hireOrFireEmployee(const std::string employeeName, const int totalStaffMembers);
    // getPizzaStore member function
    double getPizzaStore(const int threshold, const int startingValue) const;

    // Using -> for member functions
    void billCustomerCopy() const;
    void addToppingsCopy();
    void hireOrFireEmployeeCopy();
    void getPizzaStoreCopy() const;
    void displayMemberVariables() const;

    // Constructor
    PizzaStore();

    // Destructor
    ~PizzaStore();

    JUCE_LEAK_DETECTOR(PizzaStore)
};