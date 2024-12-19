#include "ihuman.cpp"
#include "child.cpp"
#include "adult.cpp"
#include <iostream>
#include "enum.cpp"
#include <string>
#include <Windows.h>
#include <fstream>
using namespace data;


int main() {
    SetConsoleOutputCP(65001);

    Adult* ad1 = new Adult("denis", "same", age::denis, 180, 110,100);
    Adult* ad2 = new Adult("diana", "rovert", 32, 100, 170, 100);
    Child* ch1 = new Child("axe", "miksher", age::axe, 10, 150, 7);
    Child* ch2 = new Child("max", "sarbyz",  24, 160, 25, 8);

    IHuman** arr = new IHuman*[5]{ad1, ad2, ch1, ch2};
    bool start = true;
    do
    {

        std::cout << "Какое действие хотите выполнить. 1: Перезапись. 2: Вывод информации. 3: Выйти из программы"<< "\n";
        char var;
        std::cin >> var;
        std::cin.ignore();
        switch (var)
        {
            case '1':
                std::cout
                        << "Перезаполнить информацию для: 1: denis, 2: diana, 3: axe, 4: max, 0: выйти из программы, 6 - вернуться"
                        << std::endl;
                std::cout << "___________________________________________" << std::endl;

                char choice;
                std::cin >> choice;
                std::cin.ignore();
                switch (choice)
                {
                    case '1':
                        arr[0]->readFromConsole();
                        break;
                    case '2':
                        arr[1]->readFromConsole();
                        break;
                    case '3':
                        arr[2]->readFromConsole();
                        break;
                    case '4':
                        arr[3]->readFromConsole();
                        break;
                    case '0':
                        start = false;
                        break;
                    case '6':
                        break;
                    default:
                        break;
                }
            case '2':
                std::cout
                        << "Вывести информацию для: 1 = denis, 2 = diana, 3 = axe, 4 = max, 0 - всех, 6 - выйти из программы "
                        << std::endl;
                std::cout << "___________________________________________" << std::endl;

                std::cin >> choice;
                std::cin.ignore();
                switch (choice)
                {
                    case '1':
                        arr[0]->printInfo();
                        break;
                    case '2':
                        arr[1]->printInfo();
                        break;
                    case '3':
                        arr[2]->printInfo();
                        break;
                    case '4':
                        arr[3]->printInfo();
                        break;
                    case '5':
                        arr[4]->printInfo();
                        break;
                    case '0':
                        for (int i = 0; i < 5; ++i)
                        {
                            arr[i]->printInfo();
                            std::cout << "___________________________________________" << std::endl;
                        }
                        break;
                    case '9':
                        start = false;
                        break;
                    default:
                        break;
                }
            case '3':
                start = false;
                break;
            default:
                break;
        }


    } while (start);


    std::ofstream out("pz22.txt", std::ios::out | std::ios::trunc);
    out.close();

    for (int i = 0; i < 5; ++i)
    {
        arr[i]->writeToFile();
        std::cout << "Информация о \"" << arr[i]->getFirstName() << "\" успешно записана в файл." << std::endl;
    }

    ch1->calculateBMI();
    ad1->calculateBirthYear();

    delete[] arr;
    delete ad1;
    delete ad2;
    delete ch1;
    delete ch2;
    return 0;
}