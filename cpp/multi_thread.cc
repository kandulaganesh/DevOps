
#include "Common.h"
using namespace std;

/*
 * Compile: g++ Common.h Consumer.cc Producer.cc multi_thread.cc -std=c++11 -lpthread
 */

int main()
{
    cout << "Beginning of main\n";
    Consumer* in = Consumer::getInstance();
    thread t1(&Consumer::processRequests, in);

    // Danger Danger... Using only Pointer.. Not Object. (As No Data Members are available)
    Producer *p;
    thread t2(&Producer::SendRequests, p);
    
    t1.join();
    t2.join();
    return 0;
}

