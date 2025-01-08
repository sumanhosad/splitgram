#include "../includes/cryptography.h"
#include <cryptopp/filters.h> // For StringSource and StringSink
#include <cryptopp/gcm.h>     // Galois/Counter Mode (GCM) implementation
#include <cryptopp/hex.h>     // For encoding/decoding to hex
#include <cryptopp/osrng.h>   // For random number generation
#include <iostream>

// Constructor: Stores the provided key and IV for encryption/decryption.
AES_GCM::AES_GCM(const CryptoPP::SecByteBlock &key,
                 const CryptoPP::SecByteBlock &iv)
    : key(key), iv(iv) {}

// Encrypts the given plaintext using AES in GCM mode and returns the
// ciphertext.
std::string AES_GCM::encrypt(const std::string &plainText) {
  std::string cipherText;

  try {
    // Create an AES GCM encryptor object.
    CryptoPP::GCM<CryptoPP::AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(key, key.size(), iv);

    // Perform authenticated encryption.
    // StringSource processes the plaintext, applies the encryption filter,
    // and writes the encrypted output to cipherText.
    CryptoPP::StringSource(
        plainText, true,
        new CryptoPP::AuthenticatedEncryptionFilter(
            encryptor, new CryptoPP::StringSink(cipherText)));
  } catch (const CryptoPP::Exception &e) {
    // Catch and display Crypto++ exceptions.
    std::cerr << "Encryption error: " << e.what() << "\n";
    throw; // Re-throw the exception to handle it further if needed.
  }

  return cipherText;
}

// Decrypts the given ciphertext using AES in GCM mode and returns the
// plaintext.
std::string AES_GCM::decrypt(const std::string &cipherText) {
  std::string recoveredText;

  try {
    // Create an AES GCM decryptor object.
    CryptoPP::GCM<CryptoPP::AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(key, key.size(), iv);

    // Perform authenticated decryption.
    // StringSource processes the ciphertext, applies the decryption filter,
    // and writes the decrypted output to recoveredText.
    CryptoPP::StringSource(
        cipherText, true,
        new CryptoPP::AuthenticatedDecryptionFilter(
            decryptor, new CryptoPP::StringSink(recoveredText)));
  } catch (const CryptoPP::Exception &e) {
    // Catch and display Crypto++ exceptions.
    std::cerr << "Decryption error: " << e.what() << "\n";
    throw; // Re-throw the exception to handle it further if needed.
  }

  return recoveredText;
}
