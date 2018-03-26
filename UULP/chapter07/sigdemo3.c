#include <stdio.h>
#include <signal.h>

#define INPUTLEN 100

main(int ac, char * av[])
{
    void inthander(int);
    void quithander(int);
    char input[INPUTLEN];
    int nchars;

    signal(SIGINT, inthander);
    signal(SIGQUIT, quithander);

    do
    {
        printf("\nType a message\n");
        nchars = read(0, input, (INPUTLEN-1));
        if (nchars == -1)
            perror("read returned an error");
        else
        {
            input[nchars] = '\0';
            printf("You typed: %s", input);
        }
    } while(strncmp(input, "quit", 4) != 0);
}

void inthander(int s)
{
    int rv;
    void (*prev_qhandler)();
    prev_qhandler = signal(SIGQUIT, SIG_IGN);

    printf("Received signal %d.. waiting\n", s);
    sleep(2);
    printf("Leaving inthander\n");

    signal(SIGQUIT, prev_qhandler);
}

void quithander(int s)
{
    printf("Received signal %d.. waiting\n", s);
    sleep(3);
    printf("Leaving quithander\n");
}