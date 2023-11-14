/*
 * Kim Magidhi
 * ContactFactory.h - Header file for the ContactFactory class.
 *
 * This header file defines the ContactFactory class, which is responsible for generating
 * random Contact objects and adding them to a ContactList. It declares the class interface,
 * including the constructor, a method for generating random contacts, and the >> operator
 * overload to add contacts to a ContactList.
 *
 * Date: 11/07/2023
 */
 
#ifndef CONTACTFACTORY_H
#define CONTACTFACTORY_H

#include "ContactList.h"

class ContactFactory {

public:
    ContactFactory();                // Constructor for the ContactFactory class.
    Contact generateRandomContact(); // Generates a random Contact object.
    void operator>>(ContactList& cl); // Overloaded >> operator to add contacts to a ContactList.
};

#endif

