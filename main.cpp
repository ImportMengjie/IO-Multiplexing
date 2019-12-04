#include <stdio.h>
#include "select.hpp"
#include "poll/poll.h"

int main()
{
    printf("hello world\n");
    // test_poll();
    test_select2();
    return 0;
}