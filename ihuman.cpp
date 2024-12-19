#include <string>
#include "ihuman.h"
#include "enum.h"
#include <iostream>
using namespace data;

IHuman::IHuman(){
    this->_firstName = "undef";
    this->_lastName = "undef";
    this->_age = 0;
    this->_weight = 0;
    this->_height = 0;
}

IHuman::IHuman(std::string firstName, std::string lastName, int age, double weight, double height) : _firstName(correctAlpha(firstName)), _lastName(correctAlpha(lastName)),
                                                                                                     _age(correctCount(age)), _weight(correctCount(weight)), _height(correctCount(height)){}

IHuman::IHuman(std::string firstName, std::string lastName, int age, double weight): IHuman(firstName, lastName, age, weight, 0){}

IHuman::IHuman(std::string firstName, std::string lastName, int age): IHuman(firstName, lastName, age, 0, 0){}

IHuman::IHuman(std::string firstName, std::string lastName): IHuman(firstName, lastName, 0, 0, 0){}

IHuman::IHuman(std::string firstName): IHuman(firstName, "undef", 0, 0, 0){}


IHuman::~IHuman()
{

}


void IHuman::setFirstName(std::string  firstName)
{
    this->_firstName = correctAlpha(firstName);
}

std::string  IHuman::getFirstName()
{
    return _firstName;
}


void IHuman::setLastName(std::string  lastName)
{
    this->_lastName = correctAlpha(lastName);
}

std::string  IHuman::getLastName()
{
    return _lastName;
}


void IHuman::setAge(int age)
{
    if (age > 0) this->_age = correctCount(age);
    else std::cout << "Некорректный ввод данных" << std::endl;
}

int IHuman::getAge()
{
    return _age;
}


void IHuman::setWeight(double weight)
{
    if (weight > 0) this->_weight = correctCount(weight);
    else std::cout << "Некорректный ввод данных" << std::endl;
}

double IHuman::getWeight()
{
    return _weight;
}


void IHuman::setHeight(double height)
{
    if (height > 0) this->_height = correctCount(height);
    else std::cout << "Некорректный ввод данных" << std::endl;
}

double IHuman::getHeight()
{
    return _height;
}

void IHuman::printInfo(){
    std::cout << "Имя: " << _firstName << " " << _lastName << "\n"
              << "Возраст: " << _age << "\n"
              << "Вес: " << _weight << " kg\n"
              << "Рост: " << _height << " cm\n";
}

void IHuman::readFromConsole()
{
    std::cout << "Введите имя: "; std::cin >> _firstName;
    std::cout << "Введите фамилию: "; std::cin >> _lastName;
    std::cout << "Введите возраст: "; std::cin >> _age;
    std::cout << "Введите рост: "; std::cin >> _height;
    std::cout << "Введите вес: "; std::cin >> _weight;
}

void IHuman::writeToFile() {}
