#include "Wrappers.h"
#include "Gym.h"
#include "School.h"
#include "PizzaStore.h"
#include "Divisions.h"
#include "District.h"

GymWrapper::GymWrapper(Gym* gymPtr) : pointerToGym(gymPtr)
{}

GymWrapper::~GymWrapper()
{
    delete pointerToGym;
}

SchoolWrapper::SchoolWrapper(School* schoolPtr) : pointerToSchool(schoolPtr)
{}

SchoolWrapper::~SchoolWrapper()
{
    delete pointerToSchool;
}

PizzaStoreWrapper::PizzaStoreWrapper(PizzaStore* pizzaPtr): pointerToPizzaStore(pizzaPtr)
{}

PizzaStoreWrapper::~PizzaStoreWrapper()
{
    delete pointerToPizzaStore;
}

DivisionsWrapper::DivisionsWrapper(Divisions* divPtr) : pointerToDivisions(divPtr) 
{}

DivisionsWrapper::~DivisionsWrapper()
{
    delete pointerToDivisions;
}

DistrictWrapper::DistrictWrapper(District* districtPtr) : pointerToDistrict(districtPtr)
{}

DistrictWrapper::~DistrictWrapper()
{
    delete pointerToDistrict;
}
