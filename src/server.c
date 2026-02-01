#include <stdint.h>
#include <sys/socket.h>

int open_socket_fd() {
  // int socket(int domain, int type, int protocol);
  // socket()  creates  an  endpoint for communication
  // and returns a file descriptor that refers to that endpoint.
  // if protocol arg is 0, then the default for that type and domain
  // is used.
  return socket(AF_INET, SOCK_STREAM, 0);
}
