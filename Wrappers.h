#pragma once

// Forward Declaration
struct Gym;
struct School;
struct PizzaStore;
struct Divisions;
struct District;

struct GymWrapper
{
    // Constructor
    GymWrapper(Gym*);

    // Destructor
    ~GymWrapper();

    // Member variable
    Gym* pointerToGym = nullptr;
};

struct SchoolWrapper
{
    // Constructor
    SchoolWrapper(School*);

    // Destructor
    ~SchoolWrapper();

    // Member variable
    School* pointerToSchool = nullptr;
};

struct PizzaStoreWrapper
{
    // Constructor
    PizzaStoreWrapper(PizzaStore*);

    // Destructor
    ~PizzaStoreWrapper();

    // Member variable
    PizzaStore* pointerToPizzaStore = nullptr;
};

struct DivisionsWrapper
{
    // Constructor
    DivisionsWrapper(Divisions*);

    // Destructor
    ~DivisionsWrapper();

    // Member variable
    Divisions* pointerToDivisions = nullptr;
};

struct DistrictWrapper
{
    // Constructor
    DistrictWrapper(District*);

    // Destructor
    ~DistrictWrapper();

    // Member variable
    District* pointerToDistrict = nullptr;
};