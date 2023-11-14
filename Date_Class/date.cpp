/*
 * Kim Magidhi
 * date.cpp - Implementation file for the Date class.
 *
 * This file has the implementations of the methods 
 * defined in the Date class. It handles date calculations, 
 * formatting, and basic utility functions for working with dates.
 *
 * Date: 10/31/2023
*/

#include "date.h"
#include <QDate>

int Date::baseYear = 1900;// Initialize the base year to 1900

//Constructors
// Default constructor: Initialize the date to the base date
Date::Date() : m_DaysSinceBaseDate(0) {}
// Constructor with year, month, and day parameters
Date::Date(int y, int m, int d) {
    if (isValidDate(y, m, d)) {
        m_DaysSinceBaseDate = ymd2dsbd(y, m, d);
    } else {
        // Handle invalid date 
        m_DaysSinceBaseDate = ymd2dsbd(baseYear, 1, 1);
    }
}

// Set the date using year, month, and day
void Date::set(int y, int m, int d) {
    if (isValidDate(y, m, d)) {
        m_DaysSinceBaseDate = ymd2dsbd(y, m, d);
    } else {
        m_DaysSinceBaseDate = ymd2dsbd(baseYear, 1, 1);
    }
}

// Check if a date is valid
bool Date::isValidDate(int y, int m, int d) const {
    // Check if the year is greater than or equal to the base year and month/day are within valid ranges.
    return (y >= baseYear && m >= 1 && m <= 12 && d >= 1 && d <= QDate(y, m, 1).daysInMonth());
}

// Convert the date to a formatted string
QString Date::toString(bool brief) const {
    int y, m, d;
    getYMD(y, m, d);
    if (brief) {
        return QString("%1/%2/%3").arg(y).arg(m).arg(d);
    } else {
        return QString("%1-%2-%3").arg(y).arg(m).arg(d);
    }
}

// Set the date to the current system date
void Date::setToToday() {
    QDate currentDate = QDate::currentDate();
    set(currentDate.year(), currentDate.month(), currentDate.day());
}

// Get the day of the week for the date
QString Date::getWeekDay() const {
    QDate baseDate(1900, 1, 1);
    int daysSinceBase = m_DaysSinceBaseDate - baseDate.toJulianDay();
    QDate current = baseDate.addDays(daysSinceBase);
    return current.toString("dddd");
}

// Compare dates
bool Date::lessThan(const Date& d) const {
    return m_DaysSinceBaseDate < d.m_DaysSinceBaseDate;
}

//Checkas if the dates are equal
bool Date::equals(const Date& d) const {
    return m_DaysSinceBaseDate == d.m_DaysSinceBaseDate;
}

// Calculate the number of days between two dates
int Date::daysBetween(const Date& d) const {
    return d.m_DaysSinceBaseDate - m_DaysSinceBaseDate;
}

// Add a specified number of days to the date
Date Date::addDays(int days) const {
    QDate baseDate(1900, 1, 1); // Base date
    QDate currentDate = baseDate.addDays(m_DaysSinceBaseDate);
    QDate futureDate = currentDate.addDays(days);
    return Date(futureDate.year(), futureDate.month(), futureDate.day());
}

// Check if a given year is a leap year
bool Date::leapYear(int year) {
    return QDate::isLeapYear(year);
}

// Get the name of the month
QString Date::monthName(int month) {
    return QDate::longMonthName(month);
}

// Calculate the number of days in a year
int Date::yearDays(int year) {
    return QDate(year, 12, 31).dayOfYear();
}

// Calculate the number of days in a month
int Date::monthDays(int month, int year) {
    return QDate(year, month, 1).daysInMonth();
}

// Calculate the number of days since the base date
int Date::ymd2dsbd(int y, int m, int d) const {
    QDate baseDate(baseYear, 1, 1);
    QDate currentDate(y, m, d);
    return baseDate.daysTo(currentDate);
}

// Get the year, month, and day from the date
void Date::getYMD(int& y, int& m, int& d) const {
    QDate baseDate(baseYear, 1, 1);
    QDate currentDate = baseDate.addDays(m_DaysSinceBaseDate);
    y = currentDate.year();
    m = currentDate.month();
    d = currentDate.day();
}

