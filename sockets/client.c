#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  char message[4096] = {0};
  const char *ip = "127.0.0.1";
  const char *port = "8080";

  struct addrinfo *addrinfo;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    perror("Socket failed\n");
    return 1;
  }

  int getinfo = getaddrinfo(ip, port, NULL, &addrinfo);

  if (getinfo != 0) {
    perror("getaddrinfo failed\n");
    return 1;
  }

  int con = connect(sockfd, addrinfo->ai_addr, addrinfo->ai_addrlen);

  if (con != 0) {
    perror("Connect failed\n");
    return 1;
  }

  printf("Connected to the Server on 127.0.0.1:8080\n");
  printf("\n");

  while (1) {

    printf("> ");

    fgets(message, sizeof(message), stdin);

    int message_len = strlen(message);

    ssize_t sen = send(sockfd, message, message_len, 0);

    if (sen == -1) {
      perror("Send message failed\n");
      return 1;
    }

    ssize_t rec = recv(sockfd, message, sizeof(message), 0);

    if (rec == -1) {
      perror("Recieve message failed\n");
      return 1;
    }

    message[rec] = '\0';

    puts(message);
  }

  close(sockfd);

  return 0;
}
