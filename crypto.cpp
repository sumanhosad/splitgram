#include "includes/cryptography.h"

int main() {
  using namespace CryptoPP;

  // Generate a random key and IV using AutoSeededRandomPool.
  AutoSeededRandomPool prng;
  SecByteBlock key(
      AES::DEFAULT_KEYLENGTH);         // Default key length for AES (16 bytes).
  SecByteBlock iv(AES::BLOCKSIZE);     // AES block size (16 bytes).
  prng.GenerateBlock(key, key.size()); // Generate random key.
  prng.GenerateBlock(iv, iv.size());   // Generate random IV.

  // Create an instance of AES_GCM with the generated key and IV.
  AES_GCM aesGcm(key, iv);

  // Define the plaintext message to encrypt.
  std::string plainText = "Authenticated encryption example.";
  std::string cipherText, recoveredText;

  try {
    // Encrypt the plaintext and store the result in cipherText.
    cipherText = aesGcm.encrypt(plainText);

    // Decrypt the ciphertext and store the result in recoveredText.
    recoveredText = aesGcm.decrypt(cipherText);

    // Print the original plaintext.
    std::cout << "Plaintext: " << plainText << "\n";

    // Print the ciphertext in hex format for better readability.
    std::cout << "Ciphertext (Hex): ";
    StringSource(
        cipherText, true,
        new HexEncoder(new FileSink(std::cout))); // Convert to hex and print.
    std::cout << "\n";

    // Print the recovered plaintext.
    std::cout << "Recovered Text: " << recoveredText << "\n";

  } catch (const CryptoPP::Exception &e) {
    // Handle any exceptions thrown by Crypto++ operations.
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}

