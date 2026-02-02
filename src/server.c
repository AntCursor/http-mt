#include "server.h"
#include "types.h"
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/socket.h>
#include <unistd.h>

int open_socket_fd() {
  /*
  int socket(int domain, int type, int protocol);
  socket()  creates  an  endpoint for communication
  and returns a file descriptor that refers to that endpoint.
  if protocol arg is 0, then the default for that type and domain
  is used, TCP.
  */
  return socket(AF_INET, SOCK_STREAM, 0);
}

err_t bind_fd_socket(int sockfd, int port) {
  /*
  int bind(int sockfd, const struct sockaddr *addr,
  bind() assigns the address specified by addr to the socket
  referred to by the file descriptor sockfd
  The rules used in name binding vary between address families.
  Consult the  manual entries in Section 7 for detailed information.
  For AF_INET, see ip(7)
  */

  //            struct sockaddr_in {
  //                sa_family_t    sin_family; /* address family: AF_INET */
  //                in_port_t      sin_port;   /* port in network byte order */
  //                struct in_addr sin_addr;   /* internet address */
  //            };
  //
  //            /* Internet address */
  //            struct in_addr {
  //                uint32_t       s_addr;     /* address in network byte order
  //                */
  //            };
  //

  const struct in_addr naddr = {INADDR_ANY};
  // 0.0.0.0 maps to all available network interfaces

  const in_port_t nport = htons(port);

  struct sockaddr_in sock = {0};
  sock.sin_family = AF_INET;
  sock.sin_addr = naddr;
  sock.sin_port = nport;

  return bind(sockfd, (struct sockaddr *)&sock, sizeof(sock));
}

err_t listen_fd_socket(int sockfd) {
  // int listen(int sockfd, int backlog);
  // listen()  marks  the  socket  referred to by sockfd as a passive socket,
  // that is, as a socket that will be used to accept incoming connection re‐
  // quests using accept(2).

  return listen(sockfd, BACKLOG_SIZE);
}

int accept_socket_fd(int sockfd) {
  // int accept(int sockfd, struct sockaddr *_Nullable restrict addr,
  //                   socklen_t *_Nullable restrict addrlen);
  // It extracts the first connection request
  // on the queue of pending connections for the  listening  socket,  sockfd,
  // creates a new connected socket, and returns a new file descriptor refer‐
  // ring  to  that socket

  socklen_t addr_len = sizeof(struct sockaddr_in);
  return accept(sockfd, NULL, &addr_len);
}

int close_fd_socket(int sockfd) { return close(sockfd); }
