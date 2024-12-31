#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h> // For sockaddr_in and inet_pton
#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h> // For read and close system calls
                    //
class Client {
public:
  // Constructor
  Client();

  // Connects to the server at the specified host and port
  int connectToServer(const std::string &host, int port);

  // Sends a message to the server
  int sendMessage(const std::string &message);

  // Receives a message from the server
  std::string receiveMessage();

  // Destructor: Cleans up resources
  ~Client();

private:
  // Socket file descriptor
  int sockfd;
};

#endif // CLIENT_H
