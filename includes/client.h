#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h> // For inet_pton
#include <cstring>     // For memset
#include <iostream>    // For standard I/O
#include <string>
#include <unistd.h>

class Client {
private:
  int sockfd;                    // Socket descriptor for the client
  struct sockaddr_in serverAddr; // Server address structure
  bool connected;                // Flag to check if the client is connected

public:
  Client();                                               // Constructor
  ~Client();                                              // Destructor
  int connectToServer(const std::string &host, int port); // Connect to server
  void sendMessage(const std::string &message);           // Send a message
  void receiveMessage();                                  // Receive a message
  void closeConnection();   // Close the connection
  bool isConnected() const; // Check if connected
};

#endif
