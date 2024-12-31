#include "../includes/client.h"

Client::Client() {
  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    std::cerr << "Failed to create socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
}

int Client::connectToServer(const std::string &host, int port) {
  sockaddr_in serverAddr{};
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);

  // Convert hostname to binary address
  if (inet_pton(AF_INET, host.c_str(), &serverAddr.sin_addr) <= 0) {
    std::cerr << "Invalid address/Address not supported" << std::endl;
    return -1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    std::cerr << "Connection to server failed. errno: " << errno << std::endl;
    return -1;
  }

  std::cout << "Connected to the server." << std::endl;
  return 0;
}

int Client::sendMessage(const std::string &message) {
  if (send(sockfd, message.c_str(), message.size(), 0) < 0) {
    std::cerr << "Failed to send message. errno: " << errno << std::endl;
    return -1;
  }
  return 0;
}

std::string Client::receiveMessage() {
  char buffer[1024] = {0};
  ssize_t bytesRead = read(sockfd, buffer, sizeof(buffer));
  if (bytesRead < 0) {
    std::cerr << "Failed to read message. errno: " << errno << std::endl;
    return "";
  }
  return std::string(buffer, bytesRead);
}

Client::~Client() {
  if (sockfd != -1) {
    close(sockfd);
  }
}
