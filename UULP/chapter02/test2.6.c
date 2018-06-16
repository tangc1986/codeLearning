#include        <stdio.h>
#include        <unistd.h>
#include        <fcntl.h>

#define BUFFERSIZE      20

void oops(char *, char *);

main(int ac, char *av[])
{
    int     read_fd_01, write_fd, read_fd_02, n_chars;
    char    buf[BUFFERSIZE];


    if ( ac != 2 )
    {
        fprintf(stderr, "usage: %s source\n", *av);
        exit(1);
    }

    if ( (read_fd_01 = open(av[1], O_RDONLY)) == -1 )
        oops("Cannot open", av[1]);

    if ( (write_fd = open(av[1], O_WRONLY)) == -1 )
        oops( "Cannot open", av[1]);
    
    if ( (read_fd_02 = open(av[1], O_RDONLY)) == -1 )
        oops("Cannot open", av[1]);


    if ( (n_chars = read(read_fd_01, buf, BUFFERSIZE)) > 0 )
        write( fileno(stdout), buf, BUFFERSIZE );

    write( write_fd, "testing 123...", sizeof("testing 123..."));

    if ( (n_chars = read(read_fd_02, buf, BUFFERSIZE)) > 0 )
        write( fileno(stdout), buf, BUFFERSIZE );

    close(read_fd_01);
    close(read_fd_02);
    close(write_fd);
}

void oops(char *s1, char *s2)
{
        fprintf(stderr, "Error: %s ", s1);
        perror(s2);
        exit(1);
}

