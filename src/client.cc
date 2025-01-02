#include "../includes/client.h"
#include <arpa/inet.h> // For inet_pton
#include <cstring>     // For memset
#include <iostream>    // For standard I/O
#include <unistd.h>    // For close()

Client::Client() : sockfd(-1), connected(false) {
  // Initialize the server address structure
  memset(&serverAddr, 0, sizeof(serverAddr));
}

Client::~Client() {
  // Ensure the connection is closed on destruction
  closeConnection();
}

int Client::connectToServer(const std::string &host, int port) {
  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    std::cerr << "Failed to create socket. errno: " << errno << std::endl;
    return -1;
  }

  // Configure the server address
  serverAddr.sin_family = AF_INET;   // IPv4
  serverAddr.sin_port = htons(port); // Convert port to network byte order

  // Convert hostname/IP string to binary form
  if (inet_pton(AF_INET, host.c_str(), &serverAddr.sin_addr) <= 0) {
    std::cerr << "Invalid address or address not supported: " << host
              << std::endl;
    close(sockfd);
    return -1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    std::cerr << "Connection to server failed. errno: " << errno << std::endl;
    close(sockfd);
    return -1;
  }

  connected = true;
  std::cout << "Connected to the server at " << host << ":" << port
            << std::endl;
  return 0;
}

void Client::sendMessage(const std::string &message) {
  if (!connected) {
    std::cerr << "Not connected to the server. Cannot send message."
              << std::endl;
    return;
  }

  // Send a message to the server
  if (send(sockfd, message.c_str(), message.size(), 0) < 0) {
    std::cerr << "Failed to send message. errno: " << errno << std::endl;
  }
}

void Client::receiveMessage() {
  if (!connected) {
    std::cerr << "Not connected to the server. Cannot receive messages."
              << std::endl;
    return;
  }

  // Buffer to hold the received message
  char buffer[1024] = {0};
  ssize_t bytesRead = read(sockfd, buffer, sizeof(buffer));

  if (bytesRead > 0) {
    std::cout << "Server response: " << buffer << std::endl;
  } else if (bytesRead == 0) {
    std::cerr << "Server disconnected." << std::endl;
    closeConnection();
  } else {
    std::cerr << "Failed to receive message. errno: " << errno << std::endl;
  }
}

void Client::closeConnection() {
  if (connected) {
    close(sockfd);
    sockfd = -1;
    connected = false;
    std::cout << "Disconnected from the server." << std::endl;
  }
}

bool Client::isConnected() const { return connected; }
