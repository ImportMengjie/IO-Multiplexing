#include <stdio.h>
#include "select.hpp"
#include "poll/poll.h"
#include "others/myTuple.hpp"
#include <string>
#include <iostream>
#include <tuple>


int main()
{
    printf("hello world\n");
    tuple<int,float,std::string> t(1,1.1,"hello");
    std::cout<<t.head()<<t.tail().head()<<t.tail().tail().head()<<std::endl;
    std::tuple<int,float,std::string> t2(1,1.1,"hello");
    std::get<2>(t2);
    std::tuple_element<2, decltype(t2)>::type a;
//    // test_poll();
//    test_select2();
    return 0;
}