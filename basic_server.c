#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  while (1) {
      
    from_client = server_setup();
    int f = fork();
    //if subserver
    if (!f) {
        to_client = server_connect(from_client);
        char line[BUFFER_SIZE];

        //get client input and send back processed string
        while (read(from_client, line, sizeof(line))) {       
            
            int len = strlen(line);
            int i;
            for (i = 0; i < len; i++) {
                if ((line[i] >= 'a' && line[i] <= 'z')) {
                    line[i] = line[i] - 32;
                }
            }
            write(to_client, line, sizeof(line));
    
        }
    }
    //if parent
    else {
    }
    
      
  }
  return 0;
}