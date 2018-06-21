#include    <stdio.h>
#include    <sys/types.h>
#include    <utmp.h>
#include    <fcntl.h>
#include    <time.h>

#define SHOWHOST

double gettime(struct utmp *);

int main()
{
    double total_time = 0;
    struct utmp *utbufp,    /* holds pointer to next rec    */
            *utmp_next();   /* returns pointer to next  */

    if ( utmp_open( UTMP_FILE ) == -1 ){
        perror(UTMP_FILE);
        exit(1);
    }
    while ( ( utbufp = utmp_next() ) != ((struct utmp *) NULL) )
        total_time += gettime( utbufp );
    utmp_close( );
    printf("        total     %.2f", total_time);
    return 0;
}

double gettime( struct utmp *utbufp )
{
    time_t cur_time;
    time_t active_time;
    
    if ( utbufp->ut_type != USER_PROCESS )
        return 0;
    
    time(&cur_time);
    active_time = cur_time - utbufp->ut_time;
    if (active_time >0)
        return (double)active_time;
    else
        return 0.0;
}

