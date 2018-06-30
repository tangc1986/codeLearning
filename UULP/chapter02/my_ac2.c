#include    <stdio.h>
#include    <sys/types.h>
#include    <utmp.h>
#include    <fcntl.h>
#include    <time.h>

#define SHOW_ORIGIN
#define ANALYZE_DATA

typedef struct _link_node
{
    struct utmp data;
    struct utmp endata;
    int iFlag;
    struct _link_node *next;
} st_link_node;


int travel_wtmp(st_link_node **stppLink);
char *type_to_str(short type);

//int find_matched_process(st_link_node *stpLink, struct utmp *stpData);


int main()
{
    st_link_node *link_head = NULL;

    travel_wtmp(&link_head);
    
    return 0;
}

void showtime(time_t timeval)
{
    char *ctime();
    char *cp;

    cp = ctime(&timeval);
    printf("%30s", cp);
}


int travel_wtmp(st_link_node **stppLink)
{
    int i = 0;
    int fd = 0;
    int iRdNum = 0;
    int iEntSize = sizeof(struct utmp);

    struct utmp stEntry;
    struct utmp stFix;
    st_link_node *stpCur = *stppLink;

#ifdef SHOW_ORIGIN
    printf("%15s%10s%10s%15s%30s%30s\n", "PROC_TYPE", "PID", "DEVICE", "USER", "HOST", "TIME");
    for (i = 0; i < 110; i++) printf("=");
    printf("\n");
#endif

    if ((fd = open(WTMP_FILE, O_RDONLY)) < 0)
    {
        //fprintf(stderr, "open error: %s\n", strerror(errno));
        return -1;
    }
    
    while ((iRdNum = read(fd, &stEntry, iEntSize)) == iEntSize)
    {
        st_link_node *stpNode = NULL;

#ifdef SHOW_ORIGIN
        printf("%15s", type_to_str(stEntry.ut_type));
        printf("%10d", stEntry.ut_pid);
        printf("%10s", stEntry.ut_line);
        printf("%15s", stEntry.ut_name);
        printf("%30s", stEntry.ut_host);
        showtime(stEntry.ut_time);
        printf("\n");
#endif
        
#if 0
        if (stEntry.ut_type == DEAD_PROCESS || stEntry.ut_type == RUN_LVL)
        {
            find_matched_process(*stppLink, &stEntry);
            continue;
        }

        if (strcmp(stEntry.ut_user, BOOT_USER) == 0)
            find_matched_process(*stppLink, &stEntry);

        if ((stpNode = malloc(sizeof(st_link_node))) == NULL)
        {
            fprintf(stderr, "malloc error: %s\n", strerror(errno));
            return -1;
        }

        init_node(stpNode);

        memcpy(&(stpNode->data), &stEntry, iEntSize);

        if (stpCur == NULL)
            *stppLink = stpNode;
        else 
            stpCur->next = stpNode;

        stpCur = stpNode;
#endif
    }

#if 0
    memset(&stFix, 0x00, sizeof(struct utmp));
    stFix.ut_type = RUN_LVL;
    strcpy(stFix.ut_user, SHUT_USER);
    stFix.ut_tv.tv_sec = time(NULL);

    find_matched_process(*stppLink, &stFix);

    if (iRdNum < 0)
    {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        return -1;
    }
#endif
    return 0;
}

char *type_to_str(short type)
{
    switch (type)
    {
        case EMPTY         : return "EMPTY";
        case RUN_LVL       : return "RUN_LVL";
        case BOOT_TIME     : return "BOOT_TIME";
        case NEW_TIME      : return "NEW_TIME";
        case OLD_TIME      : return "OLD_TIME";
        case INIT_PROCESS  : return "INIT_PROCESS";
        case LOGIN_PROCESS : return "LOGIN_PROCESS";
        case USER_PROCESS  : return "USER_PROCESS";
        case DEAD_PROCESS  : return "DEAD_PROCESS";
        case ACCOUNTING    : return "ACCOUNTING";
        default            : return "EMPTY";
    }
}


#if 0

int find_matched_process(st_link_node *stpLink, struct utmp *stpData)
{
    while (stpLink != NULL)
    {
        if (stpLink->data.ut_type == USER_PROCESS && stpLink->iFlag != MATCHED)
        {
            if (strcmp(stpLink->data.ut_line, NOUT_LINE) == 0)
            {
                if ( ( stpData->ut_type == DEAD_PROCESS && 
                       strcmp(stpData->ut_line, stpLink->data.ut_line) == 0 &&
                       strcmp (stpData->ut_host, stpLink->data.ut_host) == 0) || 
                     ( stpData->ut_type == RUN_LVL &&
                       strcmp(stpData->ut_user, SHUT_USER) == 0))
                {
                    memcpy(&(stpLink->endata), stpData, sizeof(struct utmp));
                    stpLink->iFlag = MATCHED;
                }
            }
            else 
            {   /* pesu terminal */
                if ( ( stpData->ut_type == DEAD_PROCESS && 
                       strcmp(stpLink->data.ut_line, stpData->ut_line) == 0) ||
                     ( stpData->ut_type == RUN_LVL && 
                       strcmp(stpData->ut_user, SHUT_USER) == 0))
                {
                    memcpy(& (stpLink->endata), stpData, sizeof(struct utmp));
                    stpLink->iFlag = MATCHED;
                }
            }
        }
        else if (strcmp(stpLink->data.ut_user, BOOT_USER) == 0 && stpLink->iFlag != MATCHED)
        {
            if (stpData->ut_type == RUN_LVL && strcmp(stpData->ut_user, SHUT_USER) == 0)
            {
                memcpy(&(stpLink->endata), stpData, sizeof(struct utmp));
                stpLink->iFlag = MATCHED;
            }
        }

        stpLink = stpLink->next;
    }

    return 0;
}
#endif
