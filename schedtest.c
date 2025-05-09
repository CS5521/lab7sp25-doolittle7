#include "types.h"
#include "user.h"

void useless();

int
main(int argc, char *argv[])
{
    // Proper usage check
    // schedtest 1 10 10 10 10 10 10 10
    if (argc == 1 || argc > 9) goto improper_or_help;   // Finally, a good usage for goto statements
    if (atoi(argv[1]) <= 0) goto improper_or_help;      // Same as above

    int * cpids = malloc(sizeof(int) * (argc - 2)); // max children.

    int i;
    int tickets = 0;
    for (i = 0; i + 2 < argc; i++) { // 2 -> argc - 1 are our ticket counts
        tickets = atoi(argv[i + 2]);
        if (tickets < 10) goto improper_or_help; // maybe Dijkstra was right
        int pid = fork();
        printf(1, "%d\n", pid);
        if (pid == 0) {
            settickets(tickets); // set the child's ticket to the argument provided
            useless(); // go to the useless function
        } else {
            cpids[i] = pid; // add the child pid to the array.
        }
    }

    for (i = 0; i < atoi(argv[1]); i++) {
        ps();
        sleep(3);
    }

    for (i = 0; i + 2< argc; i++) {
        kill(cpids[i]);
        wait();
    }
    exit();

    improper_or_help:
        printf(1, "usage: schedtest loops tickets1 [ tickets2 ... ticketsN ]\n\tloops must be greater than 0\n\ttickets must be greater than or equal to 10\n\tup to 7 tickets can be provided\n");
        exit();
}

void useless()
{
    int i = 0;
    while(1) {
        if (i > 10) i = 0;
        i += 1;
    }
}