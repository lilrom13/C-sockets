// Server.c
// By Romain Margheriti
// November 10th 2016

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int ac, char **av) {
  int WelcomeSocket, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  WelcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(WelcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if (listen(WelcomeSocket, 5) == 0)
    printf("Listening\n");
  else
    printf("Error\n");

  addr_size = sizeof serverStorage;
  newSocket = accept(WelcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
  strcpy(buffer, "Hello World\n");
  send(newSocket, buffer, 13, 0);

  return 0;
}
