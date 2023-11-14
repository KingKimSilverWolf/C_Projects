/*
 * Kim Magidhi
 * crypto.cpp - Implementation file for the Crypto class.
 *
 * This file contains the implementation of the Crypto class defined in the crypto.h header.
 * It provides the encryption and decryption functionality using a specified key and operation
 * sequence. 
 *
 * Date: 11/13/2023
 */

#include "crypto.h"
#include <cstdlib>
#include <QDebug>
#include <algorithm>  // Added for std::swap

// Constructor that initializes the Crypto object with a key and operation sequence
Crypto::Crypto(unsigned int key, const QString& opSequence)
    : m_Key(key), m_OpSequence(opSequence) {}

// Encrypts the given text 
QString Crypto::encrypt(const QString& text) {
    QString result = text;

    for (const QChar& op : m_OpSequence) {
        switch (op.toLatin1()) {
            case 'p':
                result = permute(result, m_Key);
                break;
            case 's':
                result = shift(result, m_Key);
                break;
            default:
                qWarning() << "Unknown operation encountered during encryption: " << op; // For unknown operation
                break;
        }
    }

    return result;
}

// Decrypts the given ciphertext 
QString Crypto::decrypt(const QString& ciphertext) {
    QString result = ciphertext;

    for (int i = m_OpSequence.length() - 1; i >= 0; --i) {
        const QChar& op = m_OpSequence[i];
        switch (op.toLatin1()) {
            case 'p':
                result = unpermute(result, m_Key);
                break;
            case 's':
                result = unshift(result, m_Key);
                break;
            default:
                qWarning() << "Unknown operation encountered during decryption: " << op; // For unknown operation
                break;
        }
    }

    return result;
}

// Shifts characters in the text by the key
QString Crypto::shift(const QString& text, unsigned int key) {
    QString result = text;

    for (QChar& ch : result) {
        int shiftAmount = limitedRand(1, 128);  // Shift amount between 1 and 128
        ch = static_cast<QChar>((ch.toLatin1() + shiftAmount + key) % 128);
    }

    return result;
}

// Unshifts characters in the ciphertext by the key
QString Crypto::unshift(const QString& ciphertext, unsigned int key) {
    QString result = ciphertext;

    for (QChar& ch : result) {
        int shiftAmount = limitedRand(1, 128);  // Shift amount between 1 and 128
        ch = static_cast<QChar>((ch.toLatin1() - shiftAmount - key + 128) % 128);
    }

    return result;
}

// Permutes characters in the text based on the key
QString Crypto::permute(const QString& text, unsigned int key) {
    QString result = text;
    QVector<int> permutation = randomPerm(result.length(), key);

    for (int i = 0; i < result.length(); ++i) {
        result[i] = text[permutation[i]];
    }

    return result;
}

// Unpermutes characters in the ciphertext based on the key
QString Crypto::unpermute(const QString& scrtext, unsigned int key) {
    QString result = scrtext;
    QVector<int> permutation = randomPerm(result.length(), key);

    for (int i = 0; i < result.length(); ++i) {
        result[permutation[i]] = scrtext[i];
    }

    return result;
}

// Generates a random integer within the specified range
int Crypto::limitedRand(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Generates a random permutation of integers based on the key
QVector<int> Crypto::randomPerm(int n, unsigned int key) {
    QVector<int> result;
    for (int i = 0; i < n; ++i) {
        result.append(i);
    }

    std::srand(key);
    for (int i = n - 1; i > 0; --i) {
        int j = limitedRand(0, i);
        std::swap(result[i], result[j]);
    }

    return result;
}

