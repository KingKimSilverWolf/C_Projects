/*
 * Kim Magidhi
 * date-test.cpp - Client code for testing the Date class.
 *
 * This file contains the main function and the code for testing the 
 * functionality of the Date class. It creates Date objects, calls 
 * the class methods, and shows the use of the Date class.
 *
 * Date: 10/31/2023
 *
 * Did not use "using namespace std" as it is considerd bad 
 * practise by many sources including: https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/#
*/

#include <iostream>
#include "date.h"

int main() {
    // Create Date objects and test their functionality
    Date date1; // Default constructor (base date)
    Date date2(2020, 10, 31);// Valid date
    Date date3(2022, 2, 29); // Invalid date (leap year)
    Date date4(1900, 2, 29); // Invalid date (not a leap year)

    // Set date to today
    date1.setToToday();

    // Test toString function
    std::cout << "Date 1: " << date1.toString().toStdString() << std::endl;
    std::cout << "Date 2: " << date2.toString().toStdString() << std::endl;
    std::cout << "Date 3: " << date3.toString().toStdString() << std::endl;
    std::cout << "Date 4: " << date4.toString().toStdString() << '\n' << std::endl;

    // Test getWeekDay function
    std::cout << "Date 1 (Day of the week): " << date1.getWeekDay().toStdString() << std::endl;
    std::cout << "Date 2 (Day of the week): " << date2.getWeekDay().toStdString() << '\n' << std::endl;

    // Test date comparisons
    std::cout << "Date 1 less than Date 2: " << (date1.lessThan(date2) ? "Yes" : "No") << std::endl;
    std::cout << "Date 2 equals Date 2: " << (date2.equals(date2) ? "Yes" : "No") << '\n' << std::endl;

    // Test daysBetween function
    int daysDiff = date2.daysBetween(date1);
    std::cout << "Days between Date 1 and Date 2: " << daysDiff << '\n' << std::endl;

    // Test addDays function
    Date futureDate = date1.addDays(18);
    std::cout << "Date 1 + 18 days: " << futureDate.toString().toStdString() << '\n' << std::endl;

    // Test static utility functions
    int year = 2024;
    std::cout << year << " is a leap year: " << (Date::leapYear(year) ? "Yes" : "No") << std::endl;
    int month = 9;
    std::cout << "Month " << month << " is " << Date::monthName(month).toStdString() << std::endl;

    return 0;
}

