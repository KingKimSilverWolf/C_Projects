/*
 * Kim Magidhi
 * ContactFactory.cpp - Implementation file for the ContactFactory class.
 *
 * This file contains the implementation of methods in the ContactFactory class. 
 * It also generates random contacts with different properties, 
 * such as category, names, addresses, and phone numbers. These generated contacts are 
 * then added to a ContactList.
 *
 * Date: 11/07/2023
 */

#include "ContactFactory.h"
#include "ContactList.h"
#include <cstdlib>
#include <vector> // Lets me use a dynamic array-like data structure that can grow or shrink in size as needed
#include <string>

// Constructor for ContactFactory class
ContactFactory::ContactFactory() {
    
}

// Generate a random contact with various properties and return it
Contact ContactFactory::generateRandomContact() {
    Contact contact;

    // Randomly select a category (friends, family, or work).
    int randomCategory = rand() % 3; // Generates a random number between 0 and 2.

    switch (randomCategory) {
        case 0:
            contact.setCategory(0); // Set the category to "friends"
            break;
        case 1:
            contact.setCategory(1); // Set the category to "family"
            break;
        case 2:
            contact.setCategory(2); // Set the category to "work"
            break;
        default:
            contact.setCategory(0); // Default to "friends" category (0) in case of an unexpected value.
            break;
    }

    // Select a random first name from the list of names.
    std::vector<std::string> firstNames = {"John", "Mary", "David", "Linda", "Michael","Sarah", 
    "Christopher", "Emily", "William", "Jessica", "Benjamin", "Olivia", "James", "Sophia", 
    "Daniel", "Emma", "Andrew", "Mia", "Joseph", "Isabella", "Samuel", "Ava", "Matthew", 
    "Grace", "Olivia", "Alexander", "Sophia", "Nicholas", "Abigail", "Ethan"};
    int randomFirstNameIndex = rand() % firstNames.size();
    contact.setFirstName(QString::fromStdString(firstNames[randomFirstNameIndex]));

    // Select a random last name from the list of names.
    std::vector<std::string> lastNames = {"Smith", "Johnson", "Williams", "Brown", "Jones",
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Davis", "Miller", "Wilson", "Moore", 
    "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", 
    "Garcia", "Martinez", "Robinson"};
    int randomLastNameIndex = rand() % lastNames.size();
    contact.setLastName(QString::fromStdString(lastNames[randomLastNameIndex]));

    // Select a random street address from the list of addresses.
    std::vector<std::string> streetAddresses = {"123 Elm St", "456 Oak Ave", "789 Maple Rd", 
    "101 Pine Ln", "234 Cedar Dr","3 Elm St", "42 Oak Ave", "7 Maple Rd", "101 Pine Ln", 
    "23 Cedar Dr", "56 Pine St", "8 Birch Ave", "345 Oak Rd", "6 Maple Ln", "9 Pine Dr", 
    "2 Birch St", "57 Elm Ave", "89 Oak Rd", "12 Maple Ln", "4 Cedar Dr", "78 Pine St", 
    "10 Birch Ave", "34 Oak Rd", "67 Maple Ln", "90 Cedar Dr"};
    int randomAddressIndex = rand() % streetAddresses.size();
    contact.setStreetAddress(QString::fromStdString(streetAddresses[randomAddressIndex]));

    // Generate a random 5-digit zip code.
    std::string zipCode = "";
    for (int i = 0; i < 5; ++i) {
        int randomDigit = rand() % 10; // Random number between 0 and 9.
        zipCode += std::to_string(randomDigit);
    }
    contact.setZipCode(QString::fromStdString(zipCode));

    // Select a random city name from the list of cities.
    std::vector<std::string> cityNames = {"New York", "Los Angeles", "Chicago", "Houston", 
    "Miami", "San Francisco", "Dallas", "Phoenix", "Philadelphia", "Seattle", "Atlanta", 
    "Denver", "Boston", "San Diego", "Austin", "Las Vegas", "Nashville", "Orlando", 
    "Portland", "Detroit", "Minneapolis", "Charlotte", "San Antonio", "Baltimore", 
    "Indianapolis", "New Orleans", "Sacramento", "Kansas City", "Jacksonville", "Columbus", 
    "San Jose", "Raleigh", "Salt Lake City", "St. Louis", "Tampa", "Pittsburgh", 
    "Cincinnati", "Milwaukee", "Memphis", "Omaha"};
    int randomCityIndex = rand() % cityNames.size();
    contact.setCity(QString::fromStdString(cityNames[randomCityIndex]));

    // Generate a random phone number.
    std::string phoneNumber = "555-";
    for (int i = 0; i < 8; ++i) {
        int randomDigit = rand() % 10; // Random number between 0 and 9.
        phoneNumber += std::to_string(randomDigit);
        if (i == 2 || i == 5) {
            phoneNumber += "-"; // Add hyphens to the phone number.
        }
    }
    contact.setPhoneNumber(QString::fromStdString(phoneNumber));

    return contact;
}

// Overloaded operator to generate a random contact and add it to the ContactList
void ContactFactory::operator>>(ContactList& cl) {
    Contact contact = generateRandomContact();
    cl.add(contact); // Add the generated contact to the ContactList.
}

