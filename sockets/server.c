#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    perror("usage: ./server <port>\n");
    return 1;
  }

  char *port = argv[1];
  unsigned short port_num = atoi(port);

  struct sockaddr_in sock_addr = {AF_INET, htons(port_num), INADDR_ANY};
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    perror("socket failed\n");
    return 1;
  }

  int b = bind(sockfd, (const struct sockaddr *)&sock_addr, sizeof(sock_addr));

  if (b != 0) {
    perror("bind failed\n");
    return 1;
  }

  int lis = listen(sockfd, 2);

  if (lis != 0) {
    perror("listen failed\n");
    return 1;
  }

  printf("* Running on http://127.0.0.1:%d\n", port_num);
  printf("\n");

  struct sockaddr_in client_addr_info;
  unsigned int client_addr_len;
  int acceptfd =
      accept(sockfd, (struct sockaddr *)&client_addr_info, &client_addr_len);

  if (acceptfd == -1) {
    perror("accept failed\n");
    return 1;
  }

  while (1) {

    char message[4096] = {0};

    ssize_t rec = recv(acceptfd, message, sizeof(message), 0);
    printf("%s\n", message);

    if (rec == -1) {
      perror("recieve message failed\n");
      return 1;
    }

    ssize_t s = send(acceptfd, message, sizeof(message), 0);

    if (s == -1) {
      perror("Send message failed\n");
      return 1;
    }
  }

  close(sockfd);

  return 0;
}
