/*
 * Kim Magidhi
 * contact-test.cpp - Implementation file for testing the Contact class.
 *
 * This file contains the implementations of test cases and functions to test
 * the Contact class. It covers tests things like creating, modifying, and displaying contact data.
 *
 * Date: 11/07/2023
 */

#include <iostream>
#include "ContactFactory.h"
#include "ContactList.h"
#include <cstdlib>
#include <ctime> // For seeding the time

int main() {
    ContactList contactList;
    ContactFactory cf;

    // Seed the random number generator with the current system time so we get new values 
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate and add 10 random contacts to the ContactList.
    for (int i = 0; i < 10; ++i) {
        cf >> contactList;
    }

    // Display the original ContactList.
    std::cout << "Original Contact List:\n";
    contactList.display();  

    // Test getPhoneList() and getMailingList() for categories 0, 1, and 2.
    for (int categoryToQuery = 0; categoryToQuery <= 2; ++categoryToQuery) {
        // Assign labels to each number.
        std::string categoryLabel;
        if (categoryToQuery == 0) {
            categoryLabel = "friends";
        } else if (categoryToQuery == 1) {
            categoryLabel = "family";
        } else if (categoryToQuery == 2) {
            categoryLabel = "work";
        }

        // Get the phone list for the selected category.
        QStringList phoneList = contactList.getPhoneList(categoryToQuery);

        // Get the mailing list for the selected category.
        QStringList mailingList = contactList.getMailingList(categoryToQuery);

        // Display the results for the current category.
        std::cout << "\nPhone List for Category " << categoryLabel << ":\n";
        for (const QString& phoneInfo : phoneList) {
            std::cout << phoneInfo.toStdString() << std::endl;
        }

        std::cout << "\nMailing List for Category " << categoryLabel << ":\n";
        for (const QString& mailingInfo : mailingList) {
            std::cout << mailingInfo.toStdString() << std::endl;
        }
    }

    // Summarize the results.
    std::cout << "\nSummary:\n";
    std::cout << "Original Contact List Size: " << contactList.size() << std::endl;

    // Add summary information for each category.
    for (int categoryToQuery = 0; categoryToQuery <= 2; ++categoryToQuery) {
        // Assign labels to each number.
        std::string categoryLabel;
        if (categoryToQuery == 0) {
            categoryLabel = "friends";
        } else if (categoryToQuery == 1) {
            categoryLabel = "family";
        } else if (categoryToQuery == 2) {
            categoryLabel = "work";
        }

        QStringList phoneList = contactList.getPhoneList(categoryToQuery);
        QStringList mailingList = contactList.getMailingList(categoryToQuery);
        std::cout << "Phone List Size for Category " << categoryLabel << ": " << phoneList.size() << std::endl;
        std::cout << "Mailing List Size for Category " << categoryLabel << ": " << mailingList.size() << std::endl;
    }

    return 0;
}

