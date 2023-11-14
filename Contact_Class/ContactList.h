/*
 * Kim Magidhi
 * ContactList.h - Header file for the ContactList class.
 *
 * Header file that defines the ContactList class, which represents a list of contact data.
 *
 * Date: 11/07/2023
 */

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QStringList>
#include "Contact.h"

class ContactList {
private:
    QStringList contactData; // Store contact data as QStringList

public:
    ContactList();

    // Method to add a contact to the list
    void add(const Contact& contact);

    // Method to remove a contact from the list
    void remove(const Contact& contact);

    // Method to get a list of phone numbers for contacts with the given category
    QStringList getPhoneList(int category) const;

    // Method to get a list of mailing information for contacts with the given category
    QStringList getMailingList(int category) const;

    // Method to get the number of contacts in the list
    int size() const;

    // Method to display the contents of the contact list
    void display() const;
};

#endif

