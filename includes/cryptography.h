#ifndef AES_HH
#define AES_HH

#include <cryptopp/aes.h>
#include <cryptopp/filters.h> // For StringSource and StringSink
#include <cryptopp/filters.h> // For FileSink, StringSource, and StringSink
#include <cryptopp/gcm.h>     // Galois/Counter Mode (GCM) implementation
#include <cryptopp/hex.h>     // For encoding/decoding to hex
#include <cryptopp/hex.h>     // For HexEncoder
#include <cryptopp/osrng.h>   // For random number generation
#include <cryptopp/secblock.h>
#include <iostream>
#include <string>

// AES_GCM class provides encryption and decryption using AES in GCM mode.
class AES_GCM {

public:
  // Constructor: Initializes the AES_GCM instance with a given key and IV.
  AES_GCM(const CryptoPP::SecByteBlock &key, const CryptoPP::SecByteBlock &iv);

  // Encrypts the provided plaintext and returns the ciphertext.
  std::string encrypt(const std::string &plainText);

  // Decrypts the provided ciphertext and returns the plaintext.
  std::string decrypt(const std::string &cipherText);

private:
  CryptoPP::SecByteBlock key; // Key for AES encryption/decryption.
  CryptoPP::SecByteBlock iv;  // Initialization Vector (IV) for GCM mode.
};

#endif // AES_HH

