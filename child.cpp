#include "child.h"
#include "enum.h"
#include <iostream>
#include <fstream>
using namespace data;

Child::Child(){
    setFirstName("undef");
    setLastName("undef");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_schoolClass = 0;
}

Child::~Child()
{

}


Child::Child(std::string firstName, std::string lastName, int age, double weight, double height, int schoolClass) :
        IHuman(firstName, lastName, age, weight, height), _schoolClass(correctCount(schoolClass)){}

Child::Child(std::string firstName, std::string lastName, int age, double weight, double height): IHuman(firstName, lastName, age, weight, height),_schoolClass(0) {}

Child::Child(std::string firstName, std::string lastName, int age, double weight): IHuman(firstName, lastName, age, weight, 0),_schoolClass(0) {}

Child::Child(std::string firstName, std::string lastName, int age): IHuman(firstName, lastName, age, 0, 0),_schoolClass(0){}

Child::Child(std::string firstName, std::string lastName): IHuman(firstName, lastName, 0, 0, 0),_schoolClass(0){}

Child::Child(std::string firstName): IHuman(firstName, "undef", 0, 0, 0),_schoolClass(0){}


void Child::setSchoolClass(int schoolClass)
{
    this->_schoolClass = correctCount(_schoolClass);
}

int Child::getSchoolClass()
{
    return _schoolClass;
}

void Child::printInfo()
{
    IHuman::printInfo();
    std::cout << "Класс обучения: " << _schoolClass << std::endl;
}



void Child::readFromConsole()
{
    IHuman::readFromConsole();
    std::cout << "Введите класс обучения: "; std::cin >> _schoolClass;
}

void Child::writeToFile()
{
    std::ofstream out;
    out.open("info.txt", std::ios::app);
    if (out.is_open())
    {
        out << "Имя: " << getFirstName() << std::endl
            << "Фамилия: " << getLastName() << std::endl
            << "Возраст: " << getAge() << std::endl
            << "Вес: " << getWeight() << std::endl
            << "Рост: " << getHeight() << std::endl
            << "Класс обучения: " << _schoolClass << std::endl
            << "_____________________________________________" << std::endl;
    }
    out.close();
}

Child::Child(int i) {

}

void Child::calculateBMI(){
    std::cout << "Индекс массы тела для "<< getFirstName()<< " - " << (getWeight() / 2.205) / ((getHeight() / 39.37) * (getHeight() / 39.37)) << "\n";
}
void Child::calculateBirthYear(){
    std::cout << "Год рождения " << getFirstName() << " - " << 2024 - getAge();
}