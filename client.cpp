#include "includes/client.h"
#include <ostream>

void displayMenu() {
  std::cout << "\n--- Client Menu ---" << std::endl;
  std::cout << "1. Send a message to the server" << std::endl;
  std::cout << "2. Close the connection" << std::endl;
  std::cout << "3. Reconnect to the server " << std::endl;
  std::cout << "4. Exit the program" << std::endl;
  std::cout << "Enter your choice: ";
}

int main(int argc, char *argv[]) {
  Client client;
  std::string serverIP = "127.0.0.1"; // IP address of the server
  int port = std::atoi(argv[2]);      // Port number of the server

  // Connect to the server
  if (client.connectToServer(serverIP, port) < 0) {
    return -1;
  }

  int choice;
  while (true) {
    displayMenu();
    std::cin >> choice;
    std::cin.ignore(); // Clear the newline character from the input buffer

    switch (choice) {
    case 1: {
      // Send a message to the server
      if (!client.isConnected()) {
        std::cout << "Not connected to the server. Please reconnect."
                  << std::endl;
        break;
      }

      std::string message;
      std::cout << "Enter message to send: ";
      std::getline(std::cin, message);
      client.sendMessage(message);

      // Receive the server's response
      client.receiveMessage();
      break;
    }
    case 2:
      // Close the connection
      client.closeConnection();
      break;
    case 3:
      // reConnect to the server
      if (client.connectToServer(serverIP, port) < 0) {
        std::cout << "Not connected to the server. Please reconnect.";
        return -1;
      } else {
        std::cout << "ReConnected to the server.";
      }
      break;

    case 4:
      // Exit the program
      client.closeConnection();
      std::cout << "Exiting the program." << std::endl;
      return 0;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }

  return 0;
}
