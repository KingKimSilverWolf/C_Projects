/*
 * Kim Magidhi
 * Contact.h - Header file for the Contact class.
 *
 * This file defines the Contact class, which shows a contact
 * with properties like category, first name, last name, street address,
 * zip code, city, and phone number. It also gives methods to set and get
 * these properties and to convert contact information to a formatted string.
 *
 * Date: 11/07/2023
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
// Private variables 
private:
    int category;
    QString firstName;
    QString lastName;
    QString streetAddress;
    QString zipCode;
    QString city;
    QString phoneNumber;

public:
    // Default constructor
    Contact();

    // Parameterized constructor
    Contact(int category, const QString& firstName, const QString& lastName, 
    const QString& streetAddress, const QString& zipCode, const QString& city, 
    const QString& phoneNumber);

    // Setter and Getter methods 
    void setCategory(int category);
    int getCategory() const;
    void setFirstName(const QString& firstName);
    QString getFirstName() const;
    void setLastName(const QString& lastName);
    QString getLastName() const;
    void setStreetAddress(const QString& streetAddress);
    QString getStreetAddress() const;
    void setZipCode(const QString& zipCode);
    QString getZipCode() const;
    void setCity(const QString& city);
    QString getCity() const;
    void setPhoneNumber(const QString& phoneNumber);
    QString getPhoneNumber() const;

    // Convert the contact information to a formatted string
    QString toString() const;
};

#endif 


