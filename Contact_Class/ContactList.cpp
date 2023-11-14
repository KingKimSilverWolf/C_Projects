/*
 * Kim Magidhi
 * ContactList.cpp - Implementation file for the ContactList class.
 *
 * This file contains the implementation of the ContactList class, which represents a list
 * of contact data. It has methods for adding, removing, and getting contact information,
 * as well as displaying the contact list. 
 *
 * Date: 11/07/2023
 */

#include "ContactList.h"
#include "Contact.h"
#include <QDebug>

ContactList::ContactList() {
    // Initialize the list by clearing it
    contactData.clear();
}

void ContactList::add(const Contact& contact) {
    // Add the contact's data to the list as a string
    contactData.append(contact.toString());
}

void ContactList::remove(const Contact& contact) {
    // Remove the contact's data from the list
    contactData.removeAll(contact.toString());
}

QStringList ContactList::getPhoneList(int category) const {
    QStringList phoneList;
    for (const QString& contact : contactData) {
        // Parse the contact data to check if it matches the category and add to the phone list
        QStringList parts = contact.split(", ");
        if (parts.size() > 0) {
            QString categoryString = parts[0].right(parts[0].size() - 10); 
            int contactCategory = categoryString.toInt();
            if (contactCategory == category) {
                phoneList.append(parts[1]); 
            }
        }
    }
    return phoneList;
}

QStringList ContactList::getMailingList(int category) const {
    QStringList mailingList;
    for (const QString& contact : contactData) {
        // Parse the contact data to check if it matches the category and add to the mailing list
        QStringList parts = contact.split(", ");
        if (parts.size() > 0) {
            QString categoryString = parts[0].right(parts[0].size() - 10); // Extract the category part
            int contactCategory = categoryString.toInt();
            if (contactCategory == category) {
                mailingList.append(contact); // Add the whole contact to the mailing list
            }
        }
    }
    return mailingList;
}

int ContactList::size() const {
    return contactData.size();
}

void ContactList::display() const {
    for (const QString& contact : contactData) {
        qDebug() << contact; 
    }
}

