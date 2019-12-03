
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int test_select2()
{
    timeval tv;
    int ret;

    fd_set readfds;
    fd_set writefds;

    while (true)
    {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        FD_ZERO(&writefds);
        FD_SET(STDOUT_FILENO, &writefds);

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        // int ret = select(STDERR_FILENO, &readfds, &writefds, NULL, &tv);
        int ret = select(STDERR_FILENO, &readfds, NULL, NULL, &tv);
        if (ret == -1)
        {
            perror("select");
            return 1;
        }
        else if (!ret)
        {
            printf("%d seconds elapsed. \n", TIMEOUT);
            return 0;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds))
        {
            char buf[BUF_LEN + 1];
            int len = read(STDIN_FILENO, buf, BUF_LEN);
            if (len == -1)
            {
                perror("read");
                return 1;
            }
            if (len)
            {
                buf[len] = '\0';
                printf("recv: %s\n", buf);
                int len = sprintf(buf, "tv.sec:%ld & tv.usec:%ld\n", tv.tv_sec, tv.tv_usec);
                printf("%s", buf);
            }
        }

        if (FD_ISSET(STDOUT_FILENO, &writefds))
        {
            char buf[BUF_LEN + 1];
            int len = sprintf(buf, "tv.sec:%ld & tv.usec:%ld\n", tv.tv_sec, tv.tv_usec);
            // printf("out: %s\n", buf);
        }
    }
}

int test_select()
{
    timeval tv;
    int ret;

    // read fds
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(STDERR_FILENO + 1, &readfds, NULL, NULL, &tv);
    if (ret == -1)
    {
        perror("select");
        return 1;
    }
    else if (!ret)
    {
        printf("%d seconds elapsed. \n", TIMEOUT);
        return 0;
    }
    if (FD_ISSET(STDIN_FILENO, &readfds))
    {
        char buf[BUF_LEN + 1];
        int len = read(STDIN_FILENO, buf, BUF_LEN);
        if (len == -1)
        {
            perror("read");
            return 1;
        }
        if (len)
        {
            buf[len] = '\0';
            printf("recv: %s\n", buf);
        }
        return 0;
    }
    fprintf(stderr, "this should not happen!\n");
    return 1;
}