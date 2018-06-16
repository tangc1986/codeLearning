/** cp1.c
 *     version 1 of cp - uses read and write with tunable buffer size
 *
 *     usage: cp1 src dest
 */
#include        <stdio.h>
#include        <unistd.h>
#include        <fcntl.h>
#include        <limits.h>

#define BUFFERSIZE      4096
#define COPYMODE        0644

void oops(char *, char *);

main(int ac, char *av[])
{
    int     in_fd, out_fd, n_chars;
    char    buf[BUFFERSIZE];
    char    abs_path_in[PATH_MAX] = {0};
    char    abs_path_out[PATH_MAX] = {0};
    
    /* check args   */
    if ( ac != 3 ){
            fprintf( stderr, "usage: %s source destination\n", *av);
            exit(1);
    }
    /* open files   */

    if ( (in_fd=open(av[1], O_RDONLY)) == -1 )
            oops("Cannot open", av[1]);

    if ( (out_fd=creat( av[2], COPYMODE)) == -1 )
            oops( "Cannot creat", av[2]);

    if (realpath(av[1], abs_path_in) && realpath(av[2], abs_path_out))
        if (memcmp(abs_path_in, abs_path_out, PATH_MAX) == 0)
        {
            //fprintf( stderr, "%s\n", abs_path_in);
            fprintf( stderr, "%s and %s are same file.\n", av[1], av[2]);
            exit(1);
        }

    /* copy files   */

    while ( (n_chars = read(in_fd, buf, BUFFERSIZE)) > 0 )
            if ( write( out_fd, buf, n_chars ) != n_chars )
                    oops("Write error to ", av[2]);
    if ( n_chars == -1 )
        oops("Read error from", av[1]);

    /* close files  */

    if ( close(in_fd) == -1 || close(out_fd) == -1 )
            oops("Error closing files","");
}

void oops(char *s1, char *s2)
{
        fprintf(stderr,"Error: %s ", s1);
        perror(s2);
        exit(1);
}
