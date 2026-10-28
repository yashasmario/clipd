#include "../../include/clipd/base.h"

#include <poll.h>
#include <stddef.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef __APPLE__
#define PASTE_CMD "pbpaste"
#else
#define PASTE_CMD "wl-paste --no-newline 2>/dev/null"
#endif



int main(i32 argc, char *argv[]){
    if (argc > 1){
        printf("Usage: clipd\n");
        return 0;
    }
    
    FILE *f = popen(PASTE_CMD, "r");
        
    int ch;
    while ((ch = fgetc(f)) != EOF){
        putchar(ch);
    }
    pclose(f);
}
