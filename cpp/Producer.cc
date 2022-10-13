
#include "Common.h"

int Producer::reqIdCounter = 0;

Request Producer::prepareRequest(string &message){
    reqIdCounter += 1;
    Request obj = {message, reqIdCounter};
    return obj;
}

void Producer::SendRequests(){
    int idx = 0;
    while(idx < 10){
        string msg = "Message " + to_string(idx);
        idx += 1;
        Request r = prepareRequest(msg);
        Consumer::getInstance()->putRequest(r);
        sleep(5);
    }
}
