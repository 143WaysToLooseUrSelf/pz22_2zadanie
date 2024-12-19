#include "adult.h"
#include "enum.h"
#include <iostream>
using namespace data;

Adult::Adult(){
    setFirstName("undef");
    setLastName("undef");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_workPriority = 0;
}

Adult::~Adult()
{

}

Adult::Adult(std::string firstName, std::string lastName, int age, double weight, double height, int workPriority) :
        IHuman(firstName, lastName, age, weight, height), _workPriority(correctCount(workPriority)){}

Adult::Adult(std::string firstName, std::string lastName, int age, double weight, double height): IHuman(firstName, lastName, age, weight, height),_workPriority(0) {}

Adult::Adult(std::string firstName, std::string lastName, int age, double weight): IHuman(firstName, lastName, age, weight, 0),_workPriority(0) {}

Adult::Adult(std::string firstName, std::string lastName, int age): IHuman(firstName, lastName, age, 0, 0),_workPriority(0){}

Adult::Adult(std::string firstName, std::string lastName): IHuman(firstName, lastName, 0, 0, 0),_workPriority(0){}

Adult::Adult(std::string firstName): IHuman(firstName, "undef", 0, 0, 0),_workPriority(0){}


void Adult::setWorkPriority(int workPriority)
{
    this->_workPriority = correctCount(workPriority);
}

int Adult::getWorkPriority()
{
    return _workPriority;
}

void Adult::printInfo()
{
    IHuman::printInfo();
    std::cout << "Приоритет получения работы: " << _workPriority << std::endl;
}


void Adult::readFromConsole()
{
    IHuman::readFromConsole();
    std::cout << "Введите приоритет работы: "; std::cin >> _workPriority;
}

void Adult::writeToFile()
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
            << "Приоритет работы: " << _workPriority << std::endl
            << "_____________________________________________" << std::endl;
    }
    out.close();
}

Adult::Adult(int i) {

}

void Adult::calculateBMI(){
    std::cout << "Индекс массы тела для "<< getFirstName()<< " - " << (getWeight() / 2.205) / ((getHeight() / 39.37) * (getHeight() / 39.37)) << "\n";
}

void Adult::calculateBirthYear(){
    std::cout << "Год рождения " << getFirstName() << " - " << 2024 - getAge();
}