#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define ASK    "Do you want another transaction"
#define TRIES  3                /* max ties */
#define SLEEPTIME 2             /* time per try */
#define BEEP  putchar('\a')     /* alert user */

main()
{
    int response;
    tty_mode(0);                            /* save tty mode */
    set_cr_noecho_mode();                   /* set -icanon, -echo */
    set_nodelay_mode();                     /* noinput => EOF */
    response = get_response(ASK, TRIES);    /* get some answer */
    tty_mode(1);                            /* restore tty mode */
    return response;
}

int get_response(char * question, int maxtries)
{
    int input;
    printf("%s (y/n)?", question);
    while (1)
    {
        sleep(SLEEPTIME);
        input = tolower(get_ok_char());
        if (input == 'y')
            return 0;
        if (input == 'n')
            return 1;
        if (maxtries-- == 0)
            return 2;
        BEEP;
    }
}

get_ok_char()
{
    int c;
    while ((c = getchar()) != EOF && strchr("yYnN", c) == NULL)
        ;
    return c;
}

set_cr_noecho_mode()
{
    struct termios    ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag    &= ~ICANON;
    ttystate.c_lflag    &= ~ECHO;
    ttystate.c_cc[VMIN]  = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

set_nodelay_mode()
{
    int termflags;
    termflags = fcntl(0, F_GETFL);
    termflags |= O_NDELAY;
    fcntl(0, F_SETFL, termflags);
}

tty_mode(int how)
{
    static struct termios original_mode;
    static int original_flags;
    if (how == 0)
    {
        tcgetattr(0, &original_mode);
        original_flags = fcntl(0, F_GETFL);
    }
    else
    {
        tcsetattr(0, TCSANOW, &original_mode);
        fcntl(0, F_SETFL, original_flags);
    }
}
