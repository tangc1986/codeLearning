#include <stdio.h>

int main(int ac, char *av[])
{
    setup();
    if (get_ticket() != 0)
        exit(0);

    do_regular_work();

    release_ticket();
    shut_down();
}

do_regular_work()
{
    printf("SuperSleep version 1.0 Running-Licensed Software\n");
    sleep(10);
}
