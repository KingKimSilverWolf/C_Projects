/*
 * Kim Magidhi
 * date.h - Header file for the Date class.
 *
 * This file defines the Date class, which represents 
 * dates using the number of days since a fixed base date. 
 * It includes methods for date manipulation, formatting, 
 * and utility functions.
 *
 * Date: 10/31/2023
*/

#ifndef DATE_H
#define DATE_H

#include <QString>

class Date {
public:
    // Constructors
    Date();  // Default constructor
    Date(int y, int m, int d);  // Constructor with year month and day parameters
    void set(int y, int m, int d);  

    // Date Formatting
    QString toString(bool brief = false) const;  // Convert the date to a formatted string
    void setToToday();  // Set the date to the current system date

    // Date Information
    QString getWeekDay() const;  // Get the day of the week for the date
    bool lessThan(const Date& d) const;  // Compare dates to check if the current date is less than another date
    bool equals(const Date& d) const;  // Compare dates to check if they are equal
    int daysBetween(const Date& d) const;  // Calculate the number of days between two dates
    Date addDays(int days) const;  // Add a specified number of days to the date

    static bool leapYear(int year);  // Check if a given year is a leap year
    static QString monthName(int month);  // Get the name of the month
    static int yearDays(int year);  // Calculate the number of days in a year
    static int monthDays(int month, int year);  // Calculate the number of days in a month

private:
    int m_DaysSinceBaseDate;  // Number of days since the base date
    static int baseYear;  // Base year used for date calculations

    // Private Helper Functions
    int ymd2dsbd(int y, int m, int d) const;  // Calculate the number of days since the base date
    void getYMD(int& y, int& m, int& d) const;  // Get the year, month, and day from the date

    // Function to check if a date is valid
    bool isValidDate(int y, int m, int d) const;  // Check if the date is valid
};

#endif

