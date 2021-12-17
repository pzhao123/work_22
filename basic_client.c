#include "pipe_networking.h"


int main() {

    int to_server;
    int from_server;
    
    //handshake
    from_server = client_handshake( &to_server );

    while (1) {       
        //read stdin
        char line[BUFFER_SIZE];
        printf("Input: ");
        fgets(line, BUFFER_SIZE, stdin);
        line[strlen(line) - 1] = '\0';

        //for exiting
        if (!strcmp(line, "exit")) return 0;

        //send input to server
        write(to_server, line, sizeof(line));

        //read and print server response
        char response[BUFFER_SIZE];
        read(from_server, response, sizeof(response));
        printf("OUTPUT: %s\n", response);
    }
    return 0;
}