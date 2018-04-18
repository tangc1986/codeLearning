#define RECLAIM_INTERVAL 60

void ticket_reclaim()
{
    int i;
    char tick[BUFSIZ];

    for (i = 0; i < MAXUSERS; i++)
    {
        if ((ticket_array[i] != TICKET_AVAIL) &&
            (kill(ticket_array[i], 0) == -1) &&
            (errno == ESRCH))
        {
            sprintf(tick, "%d. %d", ticket_array[i], i);
            narrate("freeing", tick, NULL);
            ticket_array[i] = TICKET_AVAIL;
            num_tickets_out--;
        }
    }
    alarm(RECLAIM_INTERVAL);
}

static char *do_validate(char *msg)
{
    int pid, slot;

    if (sscanf(msg+5, "%d.%d", &pid, &slot) == 2 && ticket_array[slot] == pid)
        return "GOOD Valid ticket";

    narrate("Bogus ticket", msg+5, NULL);
    return "FAIL invalid ticket";
}

handle_request(char *req, struct sockaddr_in *client, socklen_t addlen)
{
    char *response;
    int ret;

    if (strncmp(req, "HELO", 4) == 0)
        response = do_hello(req);
    else if (strncmp(req, "GBYE", 4) == 0)
        response = do_goodbye(req);
    else if (strncmp(req, "VALD", 4) == 0)
        response = do_validate(req);
    else
        response = "FAIL invalid request";

    narrate("SAID:", response, client);
    ret = sendto(sd, response, strlen(response), 0, client, addlen);
    if (ret == -1)
        perror("SERVER sendto failed");
}