#include        <stdio.h>
#include        <unistd.h>
#include        <fcntl.h>

void oops(char *, char *);

main(int ac, char *av[])
{
    int fd;

    if ( ac != 2 )
    {
        fprintf(stderr, "usage: %s source\n", *av);
        exit(1);
    }

    if ( (fd = open(av[1], O_WRONLY)) == -1 )
        oops("Cannot open", av[1]);

    lseek(fd, 20000, SEEK_END);
    
    write( fd, "hello", sizeof("hello"));

    close(fd);
}

void oops(char *s1, char *s2)
{
        fprintf(stderr, "Error: %s ", s1);
        perror(s2);
        exit(1);
}


