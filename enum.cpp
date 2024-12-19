#include "enum.h"
#include <iostream>
#include <string>
using namespace data;

std::string data::correctAlpha(std::string str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (!isalpha(str.at(i)) && !ispunct(str.at(i)))
        {
            std::cout << "Некорректный ввод данных в поле" << std::endl
            << "_________________\n";
            return "undefined";
        }
    if (!(str == "undefined")) return str;
    }
    return 0;
}

int data::correctCount(int count)
{
    if (count >= 0) return count;
    else
    {
    std::cout << "Некорректный ввод данныX в поле" << std::endl<< "_________________\n";
    return 0;
    }
}
