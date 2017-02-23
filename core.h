//
// Created by Steven Yan on 10/02/2017.
//

#ifndef DAYSBETWEENDATES_CORE_H
#define DAYSBETWEENDATES_CORE_H

#endif //DAYSBETWEENDATES_CORE_H

#include<iostream>

int addition(int a[], int l)                    //This function adds the first l terms in the array a[]
{                                               //It can be used to add the days in first several months
    int n = 0;                                  //e.g. If the input month is 4 in a non-leap year,
    int s = 0;                                  //the output would be 31 + 28 + 31 + 30
    while ((n < l) && (n < 12))
    {
        s = s + a[n];
        n++;
    }
    return s;
}

int leapYearClearer(int n)                      //This function clears out the mistake caused by some special
{                                               //non-leap years such as 1900
    int i = 0;                                  //This would be used to subtract the non-existing days in those years
    int s = 0;
    while(i <= n)
    {
        if ((i % 100 == 0) && (i % 400 != 0))
            s++;
        i++;
    }
    return s;
}

bool leapYearChecker(int n)                     //This function simply checks if a year is a leap year
{
    if((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 0)))
        return true;
    else
        return false;
}

bool datesSignChecker(int a, int b, int c, int d, int e, int f)         //This checks the validity of the signs of the input
{                                                                       //Apparently, they all must be positive!
    int list[] = {a, b, c, d, e, f};
    int i = 0;
    while (i < 6)
    {
        if (list[i] <= 0)
            return false;
        i++;
    }
    return true;
}

bool datesUpperLimitChecker(int year, int month, int day)                   //This checks the validity of the input in case they are too large
{                                                                           //e.g. There is not a 13th month in a year nor a 32nd day in a month
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYearChecker(year))
        daysInMonths[1] = daysInMonths[1] + 1;
    if (month > 12)
        return false;
    if (day > daysInMonths[month - 1])
        return false;
    return true;
}

long int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2)                 //Haha, here goes the main one!
{                                                                                                           //This function calculates the days1 between 01/01/0001 and date1(year1, month1, day1)
    if (!datesSignChecker(year1, month1, day1, year2, month2, day2))                                        //also the days2 between 01/01/0001 and date2
    {                                                                                                       //To get the difference, simply find days2 - days1
        std::cout << "Error: The value of year/month/day must be positive!\n";
        return -1;
    }
    if (!datesUpperLimitChecker(year1, month1, day1) || !datesUpperLimitChecker(year2, month2, day2))
    {
        std::cout << "Error: The value of month/day is out of valid range!\n";
        return -1;
    }
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int daysInYear1 = ((year1 - 1) / 4) * 1461 + ((year1 - 1) % 4) * 365 - leapYearClearer(year1 - 1);
    long int daysInYear2 = ((year2 - 1) / 4) * 1461 + ((year2 - 1) % 4) * 365 - leapYearClearer(year2 - 1);
    int daysInMonth1 = addition(daysInMonths, month1 - 1);
    int daysInMonth2 = addition(daysInMonths, month2 - 1);
    if (leapYearChecker(year1) && month1 > 2)
        daysInMonth1++;
    if (leapYearChecker(year2) && month2 > 2)
        daysInMonth2++;
    long int days1 = daysInYear1 + daysInMonth1 + day1;
    long int days2 = daysInYear2 + daysInMonth2 + day2;
    long int result = days2 - days1;
    std::cout << "The number of days between the two dates is:" << result << std::endl;
    return result;
}
