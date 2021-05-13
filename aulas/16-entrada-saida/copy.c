#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    int source, dest; 
    char buf;

    source = open(argv[1], O_RDONLY);
    dest = open(argv[2], O_WRONLY | O_CREAT, 0700);

    int bytes_read = 1;
    do {
        bytes_read = read(source, &buf, 1);
        if (bytes_read > 0) write(dest, &buf, 1);
    } while (bytes_read > 0);

    close(source);
    close(dest);

    return 0;
}