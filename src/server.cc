#include "../includes/server.h"
#include <cstring>
#include <iostream>
#include <unistd.h> // For read and close system calls

Server::Server() {
  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Check if socket was created successfully
  if (sockfd == -1) {
    std::cerr << "Failed to create a socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  // Initialize the sockaddr structure
  memset(&sockaddr, 0, sizeof(sockaddr));
}

int Server::startServer(int port) {
  // Configure the sockaddr structure
  sockaddr.sin_family = AF_INET; // IPv4
  sockaddr.sin_addr.s_addr =
      INADDR_ANY; // Accept connections on any network interface
  sockaddr.sin_port = htons(port); // Convert port to network byte order

  // Bind the socket to the specified port
  if (bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
    std::cerr << "Failed to bind to port " << port << ". errno: " << errno
              << std::endl;
    close(sockfd);
    return -1;
  }

  // Start listening on the socket
  if (listen(sockfd, 10) < 0) {
    std::cerr << "Failed to listen on socket. errno: " << errno << std::endl;
    close(sockfd);
    return -1;
  }

  std::cout << "Server is listening on port " << port << "..." << std::endl;

  // Accept and handle incoming connections
  while (true) {
    sockaddr_in clientSockaddr;
    socklen_t clientLen = sizeof(clientSockaddr);
    int clientSock =
        accept(sockfd, (struct sockaddr *)&clientSockaddr, &clientLen);

    if (clientSock < 0) {
      std::cerr << "Failed to accept connection. errno: " << errno << std::endl;
      continue;
    }

    std::cout << "Accepted a new connection." << std::endl;

    // Handle client communication (simple echo server)
    char buffer[1024] = {0};
    ssize_t bytesRead = read(clientSock, buffer, sizeof(buffer));

    if (bytesRead > 0) {
      std::cout << "Received message: " << buffer << std::endl;

      // Echo the message back to the client
      send(clientSock, buffer, bytesRead, 0);
    } else {
      std::cerr << "Failed to read from client. errno: " << errno << std::endl;
    }

    // Close the client socket
    close(clientSock);
    std::cout << "Connection closed." << std::endl;
  }

  return 0;
}

Server::~Server() {
  // Close the server socket
  if (sockfd != -1) {
    close(sockfd);
  }
}
