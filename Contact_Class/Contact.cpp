/*
 * Kim Magidhi
 * Contact.cpp - Implementation file for the Contact class.
 *
 * This file contains the implementations of the methods defined in the Contact class.
 *
 * Date: 11/07/2023
*/

#include "Contact.h"

// Default constructor (Initializes a Contact with empty values)
Contact::Contact() {
    category = 0;
    firstName = "";
    lastName = "";
    streetAddress = "";
    zipCode = "";
    city = "";
    phoneNumber = "";
}

// Parameterized constructor (Initializes a Contact with specified values)
Contact::Contact(int category, const QString& firstName, const QString& lastName, const QString& streetAddress, const QString& zipCode, const QString& city, const QString& phoneNumber) {
    this->category = category;
    this->firstName = firstName;
    this->lastName = lastName;
    this->streetAddress = streetAddress;
    this->zipCode = zipCode;
    this->city = city;
    this->phoneNumber = phoneNumber;
}

// Setter for the category property.
void Contact::setCategory(int category) {
    this->category = category;
}

// Getter for the category property.
int Contact::getCategory() const {
    return category;
}

// Setter for the first name property.
void Contact::setFirstName(const QString& firstName) {
    this->firstName = firstName;
}

// Getter for the first name property.
QString Contact::getFirstName() const {
    return firstName;
}

// Setter for the last name property.
void Contact::setLastName(const QString& lastName) {
    this->lastName = lastName;
}

// Getter for the last name property.
QString Contact::getLastName() const {
    return lastName;
}

// Setter for the street address property.
void Contact::setStreetAddress(const QString& streetAddress) {
    this->streetAddress = streetAddress;
}

// Getter for the street address property.
QString Contact::getStreetAddress() const {
    return streetAddress;
}

// Setter for the zip code property.
void Contact::setZipCode(const QString& zipCode) {
    this->zipCode = zipCode;
}

// Getter for the zip code property.
QString Contact::getZipCode() const {
    return zipCode;
}

// Setter for the city property.
void Contact::setCity(const QString& city) {
    this->city = city;
}

// Getter for the city property.
QString Contact::getCity() const {
    return city;
}

// Setter for the phone number property.
void Contact::setPhoneNumber(const QString& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

// Getter for the phone number property.
QString Contact::getPhoneNumber() const {
    return phoneNumber;
}

// Converts the Contact object to a formatted string.
QString Contact::toString() const {
    return "Category: " + QString::number(category) +
           ", First Name: " + firstName +
           ", Last Name: " + lastName +
           ", Street Address: " + streetAddress +
           ", Zip Code: " + zipCode +
           ", City: " + city +
           ", Phone Number: " + phoneNumber;
}

