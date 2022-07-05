#include
#include
#include
#include
#include
<stdio.h>
    <sys / socket.h>
    <netinet / in.h>
    <string.h>
    <stdlib.h> int main()
{
    int udpSocket, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
    int i;
    /*Create UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);
    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8893);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverStorage;
    while (1)
    {
        /* Try to receive any incoming UDP datagram. Address and port of
        *
        requesting client will be stored on serverStorage variable */
        nBytes = recvfrom(udpSocket, buffer, 1024, 0, (struct sockaddr *)&serverStorage, &addr_size);
        /*Convert message received to uppercase*/
        for (i = 0; i < nBytes - 1; i++)
            buffer[i] = toupper(buffer[i]);
        /*Send uppercase message back to client, using serverStorage as the
        address*/
        sendto(udpSocket, buffer, nBytes, 0, (struct sockaddr *)&serverStorage, addr_size);
    }
    return 0;
}
UDP CLIENT
#include
#include
#include
#include
    <stdio.h>
    <sys / socket.h>
    <netinet / in.h>
    <string.h> int main()
{
    int clientSocket, portNum, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    /*Create UDP socket*/
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8893);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverAddr;
    while (1)
    {
        printf("Type a sentence to send to server:\n");
        fgets(buffer, 1024, stdin);
        printf("You typed: %s", buffer);
        nBytes = strlen(buffer) + 1;
        /*Send message to server*/
        sendto(clientSocket, buffer, nBytes, 0, (struct sockaddr *)&serverAddr, addr_size);
        /*Receive message from server*/
        nBytes = recvfrom(clientSocket, buffer, 1024, 0, NULL,
                          NULL);
        printf("Received from server: %s\n", buffer);
    }
    return 0;
}