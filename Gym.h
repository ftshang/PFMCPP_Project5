#pragma once

#include "LeakedObjectDetector.h"

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

        double getMemberAccountBalance(const int accountNumber);
        double weighCurrentSelf(double startingWeight, const bool finishedWorkout = true) const;
        void exercise(const std::string machineType, const int minutes = 60);
        int findMemberYears(const int threshold, const int startingValue) const;

        // using this-> member function
        void findMemberYearsCopy() const;

        // Constructor
        Member();

        // Destructor
        ~Member();

        JUCE_LEAK_DETECTOR(Member)
    };

    //bill member with monthly fee
    double billMonthlyFee(Member member, const float discount = .10f) const;
    // turn on and off equipment (treadmills, workout machines)
    bool turnOnEquipment(const std::string employeeName, bool equipmentState = false) const;
    // turn on and off electricity
    bool turnOffElectricity(bool switchSetting = true) const;
    // findGymLocation member function
    int findGymLocation(const int threshold, int startingValue) const;

    // using this-> member functions
    void billMonthlyFeeCopy() const;
    void turnOnEquipmentCopy() const;
    void turnOffElectricityCopy() const;
    void findGymLocationCopy() const;
    void displayMemberVariables() const;

    // Constructor
    Gym();
    // Destructor
    ~Gym();
    // Instastiating Member object called gymMember
    Member gymMember;

    JUCE_LEAK_DETECTOR(Gym)
};
