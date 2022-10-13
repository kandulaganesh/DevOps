#include "Common.h"

Consumer* Consumer::instance = nullptr;
bool ready;

void Consumer::processRequests(){
    cout << "Beginning of processRequests\n";
    int idx = 0;
    for(idx = 0; idx < no_requests; idx++){
         std::unique_lock<std::mutex> lk(mq_mutex);
         cv.wait(lk, []{return ready;});
         ready = false;
         Request r = mqueue.back();
         mqueue.pop();
         cout << "Request message is " << r.message << std::endl;
    }
}

Consumer* Consumer::getInstance(){
    if(instance == nullptr){
        instance = new Consumer();
    }
    return instance;
}

void Consumer::putRequest(Request r){
    const std::lock_guard<std::mutex> lock(mq_mutex);
    mqueue.push(r);
    ready = true;
    cv.notify_one();
}
