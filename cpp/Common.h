
#ifndef H_COMMON_H
#define H_COMMON_H
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <thread>
using namespace std;

struct Request {
    string message;
    int rid;
};

class Producer {
    public:
      Request prepareRequest(string& message);
      void SendRequests();
      static int reqIdCounter;
};

class Consumer {
    int no_requests;
    queue<Request> mqueue;
    std::mutex mq_mutex;
    static Consumer *instance;
    std::condition_variable cv;
    Consumer(){
        no_requests = 10;
    }
    public:
        void processRequests();
        void putRequest(Request req);
        static Consumer* getInstance();
};

#endif

