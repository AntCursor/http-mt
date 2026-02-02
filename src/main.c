#include "server.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int socketfd = open_socket_fd();
  if (socketfd < 0)
    perror("Error creating socket fd.\n");

  if (ERR_OK != bind_fd_socket(socketfd, 8080))
    perror("Error binding socket to port.\n");

  if (ERR_OK != listen_fd_socket(socketfd))
    perror("Error marking socket for listening.\n");

  int connectionfd = accept_socket_fd(socketfd);
  if (connectionfd < 0)
    perror("Error accepting connection.\n");

  printf("Hello, World!\n");

  close_fd_socket(connectionfd);
  close_fd_socket(socketfd);

  return EXIT_SUCCESS;
}
