#ifndef _SOCKET_H
#define _SOCKET_H

#include <string>
#include "wrap_zmq.h" 
using namespace std;

class Socket {
public:
    void* socket;
    SocketType socket_type; 
    string endpoint; 
    Socket(void* context, SocketType new_socket_type, string new_endpoint);
    ~Socket();
    void send(Message message); 
    Message receive(); 
    void subscribe(string new_endpoint); 
    string get_endpoint(); 
    void*& get_socket();
};

#endif
