#pragma once

#include "types.h"

#define BACKLOG_SIZE 1024

int open_socket_fd();
err_t bind_fd_socket(int sockfd, int port);
err_t listen_fd_socket(int sockfd);
int accept_socket_fd(int sockfd);
int close_fd_socket(int sockfd);
