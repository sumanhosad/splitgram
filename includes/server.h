#ifndef SERVER_H
#define SERVER_H

#include <cstdlib>      // For std functions like exit()
#include <iostream>     // For input/output operations
#include <netinet/in.h> // For sockaddr_in structure
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For read and close system calls

class Server {
public:
  // Constructor: Initializes the socket
  Server();
  int startServer(int port);
  int listenServer(int port);
  int acceptClients();
  int handleClients(int clientSock);
  int closeClients(int clientSock);

  virtual ~Server();

private:
  int sockfd;
  sockaddr_in sockaddr, clientSockaddr;
};

#endif // SERVER_H
