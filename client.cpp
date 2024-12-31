#include "includes/client.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <host> <port>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string host = argv[1];
  int port = std::stoi(argv[2]);

  Client client;
  if (client.connectToServer(host, port) != 0) {
    return EXIT_FAILURE;
  }

  std::string message;
  while (true) {
    std::cout << "Enter message (type 'exit' to quit): ";
    std::getline(std::cin, message);

    if (message == "exit") {
      break;
    }

    if (client.sendMessage(message) != 0) {
      break;
    }

    std::string response = client.receiveMessage();
    if (response.empty()) {
      break;
    }

    std::cout << "Server response: " << response << std::endl;
  }

  return EXIT_SUCCESS;
}
