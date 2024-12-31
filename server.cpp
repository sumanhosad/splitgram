#include "includes/server.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
    return EXIT_FAILURE;
  }

  int port = std::atoi(argv[1]);
  if (port <= 0) {
    std::cerr << "Invalid port number." << std::endl;
    return EXIT_FAILURE;
  }

  Server server;
  if (server.startServer(port) == -1) {
    std::cerr << "Failed to start the server." << std::endl;
    return EXIT_FAILURE;
  }
  //
  // if (server.listenServer(port) < 0) {
  //   std::cerr << "Failed to listen on socket. errno: " << errno << std::endl;
  //   return EXIT_FAILURE;
  // }
  // int clientsock = server.acceptClients();
  // server.handleClients(clientsock);
  // server.closeClients(clientsock);
  //
  return EXIT_SUCCESS;
}
