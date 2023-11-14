/*
 * Kim Magidhi
 * crypto.h - Header file for the Crypto class.
 *
 * This file defines the Crypto class, which provides encryption and decryption
 * functionality using a specified key and operation sequence. 
 *
 * Date: 11/13/2023
 */


#ifndef CRYPTO_H
#define CRYPTO_H

#include <QString>
#include <QVector>

class Crypto {
public:
    // Constructor
    Crypto(unsigned int key, const QString& opSequence);

    // Encrypts the given text using the specified operations
    QString encrypt(const QString& text);

    // Decrypts the given ciphertext using the specified operations
    QString decrypt(const QString& ciphertext);

private:
    unsigned int m_Key;        // Encryption/decryption key
    QString m_OpSequence;      // Operation sequence for encryption/decryption

    // Shifts characters in the text by the key
    QString shift(const QString& text, unsigned int key);

    // Unshifts characters in the ciphertext by the key
    QString unshift(const QString& ciphertext, unsigned int key);

    // Permutes characters in the text based on the key
    QString permute(const QString& text, unsigned int key);

    // Unpermutes characters in the ciphertext based on the key
    QString unpermute(const QString& scrtext, unsigned int key);

    // Generates a random integer within the specified range
    int limitedRand(int min, int max);

    // Generates a random permutation of integers based on the key
    QVector<int> randomPerm(int n, unsigned int key);
};

#endif


