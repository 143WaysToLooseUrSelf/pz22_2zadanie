#pragma once 
#include "ihuman.h"

class Adult : virtual public IHuman{
public:
    Adult();

    Adult(std::string firstName, std::string lastName, int age, double weight, double height, int workPriority);
    Adult(std::string firstName, std::string lastName, int age, double weight, double height);
    Adult(std::string firstName, std::string lastName, int age, double weight);
    Adult(std::string firstName, std::string lastName, int age);
    Adult(std::string firstName, std::string lastName);
    Adult(std::string firstName);

    Adult(int i);

    virtual ~Adult();

    void setWorkPriority(int workPriority);
    int getWorkPriority();

    void printInfo();

    void readFromConsole();
    void writeToFile();

    void calculateBMI();
    void calculateBirthYear();
private:
    int _workPriority;


};