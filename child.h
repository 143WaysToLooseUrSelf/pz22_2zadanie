#pragma once 
#include "ihuman.h"

class Child : virtual public IHuman{
public:
    Child();

    Child(std::string firstName, std::string lastName, int age, double weight, double height, int schoolClass);
    Child(std::string firstName, std::string lastName, int age, double weight, double height);
    Child(std::string firstName, std::string lastName, int age, double weight);
    Child(std::string firstName, std::string lastName, int age);
    Child(std::string firstName, std::string lastName);
    Child(std::string firstName);

    Child(int i);

    virtual ~Child();

    void setSchoolClass(int schoolClass);
    int getSchoolClass();

    void printInfo();
    void writeToFile();

    void readFromConsole();

    void calculateBMI();
    void calculateBirthYear();
private:
    int _schoolClass;


};