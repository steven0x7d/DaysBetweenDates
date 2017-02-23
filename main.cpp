#include <iostream>
#include "core.h"
//Never forget the CORE!!! xD

int main() {
    int year1, month1, day1, year2, month2, day2;
    proc:
    std::cout << "This is a calculator to calculate the number of days between two dates given.";           //Just some questions for the user
    std::cout << std::endl << "Please enter the year of the first date:";
    std::cin >> year1;
    std::cout << std::endl << "Please enter the month of the first date:";
    std::cin >> month1;
    std::cout << std::endl << "Please enter the day of the first date:";
    std::cin >> day1;
    std::cout << std::endl << "Please enter the year of the second date:";
    std::cin >> year2;
    std::cout << std::endl << "Please enter the month of the second date:";
    std::cin >> month2;
    std::cout << std::endl << "Please enter the day of the second date:";
    std::cin >> day2;

    daysBetweenDates(year1, month1, day1, year2, month2, day2);                                             //Call the core function that does the whole task

    char r;
    std::cout << std::endl << "To repeat, press 'r' and then press enter\nTo exit, press any key and then press enter\nUser Input:";    //Some UI functions xD
    std::cin >> r;
    if (r == 'r' || r == 'R')
        goto proc;
    return 0;
}