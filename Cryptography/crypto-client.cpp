/*
 * Kim Magidhi
 * crypto-client.cpp - Main program file for testing the Crypto class.
 *
 * This file contains the main program that tests the Crypto class defined in the crypto.h header.
 * It shows the encryption and decryption of a sample string using a randomly generated key and
 * operation sequence. The program outputs information about the original string, the encrypted string
 * (displaying only printable characters), and the recovered string after decryption.
 *
 * Date: 11/13/2023
 */


#include <QTextStream>
#include <QTime>
#include "crypto.h"

// Function to check if a character is printable
bool isPrintable(QChar ch) {
    // Check if the character is printable
    return ch.isPrint();
}

// Function to generate a random key between min and max (inclusive)
unsigned generateRandomKey(int min, int max) {
    return static_cast<unsigned>(qrand() % (max - min + 1) + min);
}

// Main function
int main() {
    QTextStream cout(stdout);

    // Original string for encryption and decryption
    QString str1("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvnm,,, ./?"), str2;

    // Display original string information
    cout << "Original string: " << str1 << Qt::endl;
    cout << "Length: " << str1.length() << Qt::endl;

    // Operation sequence for encryption and decryption
    QString seqstr("pspsp");

    // Seed the random number generator based on the current time
    qsrand(QTime::currentTime().msec());

    // Generate a random key between 128 and 9999
    unsigned key = generateRandomKey(128, 9999);
    Crypto crypt(key, seqstr);

    // Encrypt the original string
    str2 = crypt.encrypt(str1);

    // Display only printable characters in the encrypted string
    QString printableStr2;
    for (const QChar& ch : str2) {
        if (isPrintable(ch)) {
            printableStr2.append(ch);
        }
    }

    cout << "Encrypted string (Printable characters only): " << printableStr2 << Qt::endl;

    // Decrypt the encrypted string
    QString decryptedStr = crypt.decrypt(str2);
    cout << "Recovered string: " << decryptedStr << Qt::endl;

    // Check if the recovered string matches the original
    if (decryptedStr == str1) {
        cout << "Decryption successful!" << Qt::endl;
    } else {
        cout << "Decryption failed. Original and recovered strings do not match." << Qt::endl;
    }

    return 0;
}

