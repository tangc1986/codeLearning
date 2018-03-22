#include <stdio.h>
#include <signal.h>

main()
{
    void wakeup(int);

    printf("about to sleep 4 seconds\n");
    signal(SIGALRM, wakeup);
    alarm(4);
    pause();
    printf("Morning so soon? \n");
}

void wakeup(int signum)
{
#ifndef SHHHH
    printf("Alarm received from kernel\n");
#endif
}