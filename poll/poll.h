
#include <sys/poll.h>
#include <stdio.h>
#include <unistd.h>

#define TIMEOUT 5

int test_poll()
{

    pollfd fds[2];

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    int ret = poll(fds, 2, TIMEOUT);

    if (!ret)
    {
        printf("%d seconds elapsed.\n", TIMEOUT);
        return 0;
    }
    if (fds[0].revents & POLLIN)
    {
        printf("stdin is readable\n");
    }
    if (fds[1].revents & POLLOUT)
    {
        printf("stdout is writeable\n");
    }
    return 0;
}